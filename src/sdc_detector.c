/**
 *  @file sdc_detector.c
 *  @author Sheng Di
 *  @date April, 2015
 *  @brief the key detection operations, including adaptive update of dataset, the call of solutions, etc.
 *  (C) 2015 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include <string.h>
#include <stdlib.h>
#include "sdc_detector.h"

void SDC_Init_NULL()
{
	//int i = 0;
	dataset_head = NULL;
	
	sdc_manager.valuerange_counter = -1;
	sdc_manager.isFortran = 0;
	totalCost = 0;
}

void debugSetting()
{
	sdc_manager.sol_ID=SDC_AID;
	if(sdc_manager.sol_ID==SDC_AID)
	{
		sdc_manager.lambda = 0.1;
		sdc_manager.check_bestfit_rate = 20;
		sdc_manager.samp_distance = 3;
		sdc_manager.fixed_value_range = 100;
		//sdc_manager.fixed_value_range = -1;
		sdc_manager.collect_value_range_rate = 10;
		sdc_manager.impact_err_bound_ratio = 0.001;
		printf("lambda=%f, bestfit_rate=%d\n", sdc_manager.lambda, sdc_manager.check_bestfit_rate);	
	}
	else
	{
		sdc_manager.floor=0.000000001;
		sdc_manager.delta_coeff = 10;
		sdc_manager.errFeedback=0;
		sdc_manager.samp_distance = 0;
		printf("sdc_manager.samp_distance=%d\n",sdc_manager.samp_distance);	
	}
}

int SDC_Init(char *configFile, MPI_Comm globalComm)
{
	int i = 0;
	int loadFileResult;
	gettimeofday(&startTime, NULL);
	//read configuration file and initialize communicator
	SDC_COMM_WORLD = globalComm;
    MPI_Comm_rank(SDC_COMM_WORLD, &myRankID);
    MPI_Comm_size(SDC_COMM_WORLD, &nbProc);	
	
	//if(myRankID==0)
	//	printf("Configuration file is: %s\n", configFile);

	sdc_cfgFile = configFile;
	loadFileResult = SDC_LoadConf();
	if(loadFileResult==0)
		exit(0);

	//initialize structures
	SDC_Init_NULL();
	for(i=0;i<DetectResultSize;i++)
		detectResult[i] = -1;
	create_datasetlist(&dataset_head);
	
	/*****************************
	/*following is only for debug
	 * ***************************/ 
	//debugSetting();	
	
	return 0;
}

int SDC_Init_nonMPI()
{
	int i;
	SDC_Init_NULL();
	for(i=0;i<DetectResultSize;i++)
		detectResult[i] = -1;
	create_datasetlist(&dataset_head);
	
	/*****************************
	/*following is only for debug
	 * ***************************/ 
	debugSetting();
	return 0;	
}


/*-------------------------------------------------------------------------*/
/**
 *     @brief      register into the list for a variable
 *     @param      Dataset array.
 *
**/
/*-------------------------------------------------------------------------*/

void SDC_Protect(char* var_name, void* data, int data_type, int r5, int r4, int r3, int r2, int r1)
{
	int dim = 0;
	SDC_dataset* sdc_dataset;
	//construct dataset
	
	if(r1==0) dim = 0;
	else if(r2==0) dim = 1;
	else if(r3==0) dim = 2;
	else if(r4==0) dim = 3;
	else if(r5==0) dim = 4;
	else dim = 5;
	
	malloc_dataset(&sdc_dataset, data_type, dim, r5, r4, r3, r2, r1);
	
	sdc_dataset->value_range = sdc_manager.fixed_value_range;
	sdc_dataset->FPNum = 1;
	
	strcpy(sdc_dataset->var_name,var_name);
	sdc_dataset->var = data;
	//put the dataset into the head_d4 list (tail position)
	insert_dataset(dataset_head, sdc_dataset);
}

void SDC_Protect_F(char* var_name, int data_type, int r5, int r4, int r3, int r2, int r1)
{
	int dim = 0;
	SDC_dataset* sdc_dataset;
	
	if(r1==0) dim = 0;
	else if(r2==0) dim = 1;
	else if(r3==0) dim = 2;
	else if(r4==0) dim = 3;
	else if(r5==0) dim = 4;
	else dim = 5;	
	
	//construct dataset
	malloc_dataset(&sdc_dataset, data_type, dim, r5, r4, r3, r2, r1);
	sdc_dataset->value_range = sdc_manager.fixed_value_range;
	sdc_dataset->FPNum = 1;
	
	sprintf(sdc_dataset->var_name,var_name);
	//sdc_dataset->var = data; // as for fortran, the address (or reference) of the variable passed to the function will be changed, so we need to pass it in each iteration
	//put the dataset into the head_d4 list (tail position)
	insert_dataset(dataset_head, sdc_dataset);
}

int sdc_snapshot_1var_F(SDC_dataset *pp, void* var)
{
	int existError = 0;
	if(counter>=StartStepNum)
	{
		switch(sdc_manager.sol_ID)
		{
			case SDC_AID:
				existError = adaptiveImpactDriven(pp, var);
				break;			
			default:
				printf("Error: Wrong SDC_manager.sol_ID occuring sdc_detector.c (please check config.sdc).\n");
				exit(0);
		}
	}
	adaptive_updateData(pp, var);
				
	return existError;	
}

int SDC_Snapshot()
{
	SDC_dataset *pp;
	int existError = 0;
	if(dataset_head==NULL)
	{
		counter++;	
		return 0;
	}
	//determine if it's enough to predict
	pp = dataset_head->next;
	while(pp!=NULL)
	{
		existError = sdc_snapshot_1var_F(pp, pp->var);
		if(existError==1)
		{
			pp->existErr = 1;
		}
		//move pp
		pp = pp->next;	
	}
	
	counter++;
	return existError;
}

void SDC_PrintDetectResult()
{
	int i;
	char buf[SDC_BUFS];
	//printf("Rank [%d]: ", myRankID);
	for(i=0;i<DetectResultSize;i++)
	{
		if(i>=StartStepNum&&detectResult[i]==-1)
			break;
		sprintf(buf, "%s %d:%d", buf, i, detectResult[i]); 
	}
	SDC_Print(buf);
}

void SDC_Finalize()
{
	if(dataset_head!=NULL)
		free_datasetlist();
	gettimeofday(&endTime, NULL);
}

int SDC_SetMark(int i, int res)
{
	if(i>DetectResultSize)
		return 1;
	detectResult[i] = res;
	return 0;
}

void incr_counter()
{
	counter++;
}

/**
 * dimension: =1,2,3,4, or 5
 * */
int compute_steps_required(int modStep, SDC_dataset *set)
{
	int bestfit_required = 0;

	if(modStep>=StartStepNum-4&&modStep<=StartStepNum-2)
		bestfit_required = 3 - set->bestfit_order;
	else
		bestfit_required = 0;
	return bestfit_required;
}

void cost_start()
{
	gettimeofday(&costStart, NULL);
}

void cost_end()
{
	double elapsed;
	struct timeval costEnd;
	gettimeofday(&costEnd, NULL);
	elapsed = ((costEnd.tv_sec*1000000+costEnd.tv_usec)-(costStart.tv_sec*1000000+costStart.tv_usec))/1000000.0;
	totalCost += elapsed;
}

void print_Cost_Ratio()
{
	double elapsed = ((endTime.tv_sec*1000000+endTime.tv_usec)-(startTime.tv_sec*1000000+startTime.tv_usec))/1000000.0;
	printf("detectionOverhead: costRatio=%f, totalCost=%f, wallclock=%f\n", totalCost/elapsed, totalCost, elapsed);
}

/**
 * @deprecated
 * See printCostRatio
 * */
double computeTotalElapsedTime()
{
	 double elapsed = ((endTime.tv_sec*1000000+endTime.tv_usec)-(startTime.tv_sec*1000000+startTime.tv_usec))/1000000.0;
	 return elapsed;
}

void SDC_Increment_FPNum()
{
	SDC_dataset *pp = dataset_head->next;
	while(pp!=NULL)
	{
		if(pp->existErr==1)
		{
			pp->FPNum++;
			pp->existErr = 0;
		}
		//move pp
		pp = pp->next;	
	}
}
