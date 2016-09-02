/**
 *  @file sdc_datasetlist.c
 *  @author Sheng Di
 *  @date April, 2015
 *  @brief maintain the key data structures regarding the data set
 *  (C) 2015 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */


#include "sdc_detector.h"

//create_datasetlist_....
/**
 * the operations of the list
 * the format of the list: [head] [data1] [data2] [data3] .....
 * head is an empty node.
 */
void create_datasetlist(SDC_dataset ** dataset_head)
{
	(*dataset_head) = (SDC_dataset *) malloc(sizeof(SDC_dataset));
	//(*head)->var_name = NULL;
	(*dataset_head)->var = NULL;
	(*dataset_head)->r1=0;
	(*dataset_head)->head = NULL;
	(*dataset_head)->sampHead = NULL;
	(*dataset_head)->next = NULL;
}


//malloc_dateset_....
void malloc_dataset(SDC_dataset** dataset, int data_type, int dim, int r5, int r4, int r3, int r2, int r1)
{
//	int total_size;
//	int sampLength;
	*dataset = (SDC_dataset *)malloc(sizeof(SDC_dataset));
	(*dataset)->data_type = data_type;
	(*dataset)->dim = dim;
	(*dataset)->r5 = r5;
	(*dataset)->r4 = r4;
	(*dataset)->r3 = r3;
	(*dataset)->r2 = r2;
	(*dataset)->r1 = r1;
	//(*dataset)->var_name = NULL;
	
	if(sdc_manager.samp_distance<=0)
	{
		printf("ERROR: samp_distance cannot be smaller or equal to 0\n");
		exit(0);
	}
	(*dataset)->bestfit_order = 2;
	(*dataset)->value_range = -1;
	
	create_datalist_size(&(*dataset)->head,data_type, 3,dim,r5,r4,r3,r2,r1); //size=4 : X[-3], X[-2], X[-1]....
//	if(dim==5) total_size = r5*r4*r3*r2*r1;
//	else if(dim==4) total_size = r4*r3*r2*r1;
//	else if(dim==3) total_size = r3*r2*r1;
//	else if(dim==2) total_size = r2*r1;
//	else if(dim==1) total_size = r1;
	
//	sampLength = total_size/sdc_manager.samp_distance+1;
//	create_datalist_size(&(*dataset)->sampHead, data_type, 0, 1, 0, 0, 0, 0, sampLength);		
	create_datalist_size(&(*dataset)->sampHead, data_type, 0, 1, 0, 0, 0, 0, 0);		
}

//free_dataset_....
void free_dataset(SDC_dataset *p)
{
	free_datalist(p->head);

	free_datalist(p->sampHead);
		
	free(p);
}

void delete_first_dataset(SDC_dataset *head)
{
	SDC_dataset *p;
	if(head->next!=NULL)
		p = head->next;
	else
		return;
	head->next = p->next;
	free_dataset(p);
}

void free_datasetlist()
{
	if(dataset_head==NULL)
		return;	
	while(dataset_head->next!=NULL)
		delete_first_dataset(dataset_head);
	free(dataset_head);
}

void delete_dataset(SDC_dataset *head, char* var_name)
{
	SDC_dataset *p1, *p2;
	if(head->next==NULL)
	{
		printf("\nlist null!\n");
	}
	else
	{
		p1 = head;
		while(strcmp(var_name, p1->next->var_name)!=0 && p1->next!=NULL)
		{
			p1=p1->next;
		}
		if(strcmp(var_name, p1->next->var_name)==0)
		{
			p2 = p1->next;
			p1->next = p2->next;
			free_dataset(p2);
			printf("delete: %s\n", var_name);
		}
		else
			printf("%s not been found !\n", var_name);
	}
}

void insert_dataset(SDC_dataset *head, SDC_dataset *data)
{
	head->r1++;
	data->next = head->next;
	head->next = data;
}

void search_dataset(SDC_dataset *head, char* var_name, SDC_dataset **result)
{
	SDC_dataset *p;
	p = head->next;
	while(p!=NULL)
	{
		if(strcmp(var_name, p->var_name)==0)
			break;
		p=p->next;
	}

	if(strcmp(var_name, p->var_name)==0)
		*result=p;
	else
		*result=NULL;
}

void updateData(SDC_dataset *set, void* data, int r5, int r4, int r3, int r2, int r1)
{
	int dim = set->dim;
	if(set->head->r1==3)
	{
		delete_data(set->head); //delete the last data
	}
	if(sdc_manager.samp_distance<=1)
		insert_data(set->head, data, r5, r4, r3, r2, r1); 
	else
	{
		printf("ERROR (sdc_datasetlist.c 241): D5 does not support sampling model\n");
		exit(0);
	}
}

void filloutSampleData_d1(SDC_data* newData, void* data, int sampLength)
{
	int counter = 0;
	int i;
	int* data_int, *X_int;
	float* data_float, *X_float;
	double* data_double, *X_double;
	int data_type = newData->data_type;
	int r1 = newData->r1;
	
	if(data_type==SDC_INTEGER)
	{
		data_int = (int *)data;
		X_int = (int *)malloc(sampLength*sizeof(int));
		for(i=0;i<r1;i++)
		{
			if(i%sdc_manager.samp_distance==0)
			{
				X_int[counter] = data_int[i];
				counter++;
			}	
		}
		newData->X = X_int;		
	}
	else if(data_type==SDC_FLOAT)
	{
		data_float = (float *)data;
		X_float = (float *)malloc(sampLength*sizeof(float));
		for(i=0;i<r1;i++)
		{
			if(i%sdc_manager.samp_distance==0)
			{
				X_float[counter] = data_float[i];
				counter++;
			}	
		}
		newData->X = X_float;
	}
	else if(data_type==SDC_DOUBLE)
	{
		data_double = (double *)data;
		X_double = (double *)malloc(sampLength*sizeof(double));
		for(i=0;i<r1;i++)
		{
			if(i%sdc_manager.samp_distance==0)
			{
				X_double[counter] = data_double[i];
				counter++;
			}
		}
		newData->X = X_double;
	}
}

void filloutSampleData_d2(SDC_data* newData, void* data, int sampLength)
{
	int counter = 0;
	int i,j;
	int* data_int, *X_int;
	float* data_float, *X_float;
	double* data_double, *X_double;	
	int data_type = newData->data_type;
	int r2 = newData->r2;
	int r1 = newData->r1;
	
	if(data_type==SDC_INTEGER)
	{
		data_int = (int *)data;
		X_int = (int *)malloc(sampLength*sizeof(int));
		for(i=0;i<r2;i++)
			for(j=0;j<r1;j++)
			{
				if((i+j)%sdc_manager.samp_distance==0)
				{
					X_int[counter] = data_int[i*r1+j];
					counter++;
				}	
			}
		newData->X = X_int;	
	}
	else if(data_type==SDC_FLOAT)
	{
		data_float = (float *)data;
		X_float = (float *)malloc(sampLength*sizeof(float));
		for(i=0;i<r2;i++)
			for(j=0;j<r1;j++)
			{
				if((i+j)%sdc_manager.samp_distance==0)
				{
					X_float[counter] = data_float[i*r1+j];
					counter++;
				}
			}
		newData->X = X_float;	
	}
	else if(data_type==SDC_DOUBLE)
	{
		data_double = (double *)data;
		X_double = (double *)malloc(sampLength*sizeof(double));
		for(i=0;i<r2;i++)
			for(j=0;j<r1;j++)
			{
				if((i+j)%sdc_manager.samp_distance==0)
				{
					X_double[counter] = data_double[i*r1+j];
					counter++;
				}	
			}
		newData->X = X_double;
	}
}

void filloutSampleData_d3(SDC_data* newData, void* data, int sampLength)
{
	int counter = 0;
	int i,j,k;
	int* data_int, *X_int;
	float* data_float, *X_float;
	double* data_double, *X_double;	
	int data_type = newData->data_type;
	int r3 = newData->r3;
	int r2 = newData->r2;
	int r1 = newData->r1;
	
	if(data_type==SDC_INTEGER)
	{
		data_int = (int *)data;
		X_int = (int *)malloc(sampLength*sizeof(int));
		for(i=0;i<r3;i++)
			for(j=0;j<r2;j++)
				for(k=0;k<r1;k++)
				{
					if((i+j+k)%sdc_manager.samp_distance==0)
					{
						X_int[counter] = data_int[i*r2*r1+j*r1+k];
						counter++;
					}	
				}
		newData->X = X_int;	
	}			
	else if(data_type==SDC_FLOAT)
	{
		data_float = (float *)data;
		X_float = (float *)malloc(sampLength*sizeof(float));
		for(i=0;i<r3;i++)
			for(j=0;j<r2;j++)
				for(k=0;k<r1;k++)
				{
					if((i+j+k)%sdc_manager.samp_distance==0)
					{
						X_float[counter] = data_float[i*r2*r1+j*r1+k];
						counter++;
					}	
				}
		newData->X = X_float;
	}
	else if(data_type==SDC_DOUBLE)
	{
		data_double = (double *)data;
		X_double = (double *)malloc(sampLength*sizeof(double));
		for(i=0;i<r3;i++)
			for(j=0;j<r2;j++)
				for(k=0;k<r1;k++)
				{
					if((i+j+k)%sdc_manager.samp_distance==0)
					{
						X_double[counter] = data_double[i*r2*r1+j*r1+k];
						counter++;
					}	
				}
		newData->X = X_double;
	}
}

void filloutSampleData_d4(SDC_data* newData, void* data, int sampLength)
{
	int counter = 0;
	int i,j,k,z;
	int* data_int, *X_int;
	float* data_float, *X_float;
	double* data_double, *X_double;	
	int data_type = newData->data_type;
	int r4 = newData->r4;
	int r3 = newData->r3;
	int r2 = newData->r2;
	int r1 = newData->r1;
	
	if(data_type==SDC_INTEGER)
	{
		data_int = (int *)data;		
		X_int = (int *)malloc(sampLength*sizeof(int));		
		for(i=0;i<r4;i++)
			for(j=0;j<r3;j++)
				for(k=0;k<r2;k++)
					for(z=0;z<r1;z++)
					{
						if((i+j+k+z)%sdc_manager.samp_distance==0)
						{
							X_int[counter] = data_int[i*r3*r2*r1+j*r2*r1+k*r1+z];
							counter++;
						}	
					}
		newData->X = X_int;
	}
	else if(data_type==SDC_FLOAT)
	{
		data_float = (float *)data;
		X_float = (float *)malloc(sampLength*sizeof(float));		
		for(i=0;i<r4;i++)
			for(j=0;j<r3;j++)
				for(k=0;k<r2;k++)
					for(z=0;z<r1;z++)
					{
						if((i+j+k+z)%sdc_manager.samp_distance==0)
						{
							X_float[counter] = data_float[i*r3*r2*r1+j*r2*r1+k*r1+z];
							counter++;
						}	
					}
		newData->X = X_float;
	}
	else if(data_type==SDC_DOUBLE)
	{
		data_double = (double *)data;
		X_double = (double *)malloc(sampLength*sizeof(double));		
		for(i=0;i<r4;i++)
			for(j=0;j<r3;j++)
				for(k=0;k<r2;k++)
					for(z=0;z<r1;z++)
					{
						if((i+j+k+z)%sdc_manager.samp_distance==0)
						{
							X_double[counter] = data_double[i*r3*r2*r1+j*r2*r1+k*r1+z];
							counter++;
						}	
					}
		newData->X = X_double;			
	}				
}

void filloutSampleData_d5(SDC_data* newData, void* data, int sampLength)
{
	int counter = 0;
	int a,i,j,k,z;
	int* data_int, *X_int;
	float* data_float, *X_float;
	double* data_double, *X_double;	
	int data_type = newData->data_type;
	int r5 = newData->r5;
	int r4 = newData->r4;
	int r3 = newData->r3;
	int r2 = newData->r2;
	int r1 = newData->r1;	
	
	if(data_type==SDC_INTEGER)
	{	
		data_int = (int *)data;		
		X_int = (int *)malloc(sampLength*sizeof(int));
		for(a=0;a<r5;a++)
			for(i=0;i<r4;i++)
				for(j=0;j<r3;j++)
					for(k=0;k<r2;k++)
						for(z=0;z<r1;z++)
						{
							if((a+i+j+k+z)%sdc_manager.samp_distance==0)
							{
								X_int[counter] = data_int[a*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z];
								counter++;
							}	
						}
		newData->X = X_int;
	}
	else if(data_type==SDC_FLOAT)
	{
		data_float = (float *)data;
		X_float = (float *)malloc(sampLength*sizeof(float));
		for(a=0;a<r5;a++)
			for(i=0;i<r4;i++)
				for(j=0;j<r3;j++)
					for(k=0;k<r2;k++)
						for(z=0;z<r1;z++)
						{
							if((a+i+j+k+z)%sdc_manager.samp_distance==0)
							{
								X_float[counter] = data_float[a*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z];
								counter++;
							}	
						}
		newData->X = X_float;	
	}
	else if(data_type==SDC_DOUBLE)
	{
		data_double = (double *)data;
		X_double = (double *)malloc(sampLength*sizeof(double));
		for(a=0;a<r5;a++)
			for(i=0;i<r4;i++)
				for(j=0;j<r3;j++)
					for(k=0;k<r2;k++)
						for(z=0;z<r1;z++)
						{
							if((a+i+j+k+z)%sdc_manager.samp_distance==0)
							{
								X_double[counter] = data_double[a*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z];
								counter++;
							}	
						}
		newData->X = X_double;
	}
}

void filloutSampleData(SDC_data* newData, void* data, int sampLength)
{
	switch(newData->dim)
	{
		case 1:
			filloutSampleData_d1(newData, data, sampLength);
			break;
		case 2:
			filloutSampleData_d2(newData, data, sampLength);
			break;
		case 3:
			filloutSampleData_d3(newData, data, sampLength);
			break;
		case 4:
			filloutSampleData_d4(newData, data, sampLength);
			break;
		case 5:
			filloutSampleData_d5(newData, data, sampLength);
			break;
		default:
			printf("ERROR: doesn't support dimension 6 yet.\n");
			exit(0);
	}
}

int computeSampLength(SDC_dataset *set)
{
	int length = 0;
	switch(set->dim)
	{
		case 1:
			length = set->r1/sdc_manager.samp_distance+1;
			break;
		case 2:
			length = set->r2*set->r1/sdc_manager.samp_distance+1;
			break;
		case 3:
			length = set->r3*set->r2*set->r1/sdc_manager.samp_distance+1;
			break;
		case 4:
			length = set->r4*set->r3*set->r2*set->r1/sdc_manager.samp_distance+1;
			break;
		case 5:
			length = set->r5*set->r4*set->r3*set->r2*set->r1/sdc_manager.samp_distance+1;
			break;
		default:
			printf("Error: doesn't support dimension 6. (computeSampLength)\n");
			exit(0);
	}
	return length;
}

void adaptive_updateData(SDC_dataset *set, void* data)
{
	SDC_data *newData;
	int modStep, steps_required, curStepLength, i, to_delete;
	int sampLength;
	modStep = counter%sdc_manager.check_bestfit_rate;
		
	steps_required = compute_steps_required(modStep, set); //if steps_required == 2 and bestorder==0, then we need 1 extra step (sample data)
	//complement the steps_required by sample data sets
	if(steps_required>0&&modStep<=steps_required) //insert a sample data set
	{
		sampLength = computeSampLength(set);	
		malloc_data(&newData, set->data_type, set->dim, set->r5, set->r4, set->r3, set->r2, set->r1);
		filloutSampleData(newData, data, sampLength);
		//insert to the head position
		newData->next = set->sampHead->next;
		set->sampHead->next = newData;
	}
	if(counter%sdc_manager.check_bestfit_rate==StartStepNum)
	{
		//delete sample data steps memory
		clear_datalist(set->sampHead);
	} 
	steps_required = set->bestfit_order+1; //steps_required here refers to the full data set used to make prediction in the future
	curStepLength = compute_curStepLength(set->head);
	//if steps_required==curStepLength, then delete c-s+1=1 and insert 1; if s<c, then delete c-s+1 and add 1; if s>c, then only add 1
	//it's impossible that s>c+1, because of our periodic pipeline style
	to_delete = curStepLength - steps_required + 1;
	for(i=0;i<to_delete;i++)
		delete_data(set->head); //delete the last data	
	insert_data(set->head, data, set->data_type, set->r5, set->r4, set->r3, set->r2, set->r1);
}
