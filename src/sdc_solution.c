/**
 *  @file sdc_solution.c
 *  @author Sheng Di
 *  @date April, 2015
 *  @brief Key solutions of the silent data corruption, including the prediction methods.
 *  (C) 2015 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */


#include "sdc_detector.h"
#include <stdlib.h>

double abs_(double value)
{
	double result = value>0?value:-value;
	return result;
}

void computeErrors(double X[3], double V, double predErr[3])
{
	double r_0,r_1,r_2;
	int min_order = -1;
	r_0 = X[0];
	r_1 = 2*X[0]-X[1];
	r_2 = 3*X[0]-3*X[1]+X[2];
	predErr[0] = abs_(r_0-V);
	predErr[1] = abs_(r_1-V);
	predErr[2] = abs_(r_2-V);
}

int computeValidBestOrder(SDC_dataset *pp, int bestfit_order)
{
	int validOrder = compute_curStepLength(pp->head) - 1;
	if(validOrder>=bestfit_order)
		return bestfit_order;
	else
		return validOrder;
}

double* computeBestPredOrder_d1(SDC_dataset *set)
{
	int counter_ = 0;
	int i,j,k,z,m;
	double X[3], V;
	double predErr[3];
	SDC_data* p; //used for set->head
	SDC_data* q; //used for set->sampHead
	double* maxErr = (double *) malloc(3*sizeof(double)); //max local prediction errors of order0,1,2 respectively
	maxErr[0]=0;
	maxErr[1]=0;
	maxErr[2]=0;
	
	int *X_int;
	float *X_float;
	double *X_double;
	
	for(i=0;i<set->r1;i++)
	{
		if(i%sdc_manager.samp_distance==0)
		{
			p = set->head;
			
			switch(set->data_type)
			{
				case SDC_INTEGER:
					X_int = (int *)p->next->X; //set->head must have at least one dataset.
					V = X_int[i];
					break;
				case SDC_FLOAT:
					X_float = (float *)p->next->X;
					V = X_float[i];
					break;
				case SDC_DOUBLE:
					X_double = (double *)p->next->X;
					V = X_double[i];
					break;
				default: 
					printf("Error: Wrong data_type. (sdc_solution)");
					exit(0);
			}					
		
			p=p->next;
			
			q = set->sampHead;
			
			for(m=0;m<3;m++)
			{
				if(p->next!=NULL)
				{
					switch(set->data_type)
					{
						case SDC_INTEGER:
							X_int = (int *)p->next->X;
							X[m] = X_int[i];
							break;
						case SDC_FLOAT:
							X_float = (float *)p->next->X;
							X[m] = X_float[i];
							break;
						case SDC_DOUBLE:
							X_double = (double *)p->next->X;
							X[m] = X_double[i];
							break;
						default: 
							printf("Error: Wrong data_type. (sdc_solution)");
							exit(0);
					}
					
					p=p->next;
					continue;
				}
				else
				{
					switch(set->data_type)
					{
						case SDC_INTEGER:
							X_int = (int *)q->next->X;
							X[m] = X_int[counter_];
							break;
						case SDC_FLOAT:
							X_float = (float *)q->next->X;
							X[m] = X_float[counter_];
							break;
						case SDC_DOUBLE:
							X_double = (double *)q->next->X;
							X[m] = X_double[counter_];
							break;
						default: 
							printf("Error: Wrong data_type. (sdc_solution)");
							exit(0);
					}					
					q=q->next;
				}
			}
											
			computeErrors(X,V,predErr);
		
			if(maxErr[0]<predErr[0])
				maxErr[0] = predErr[0];
			if(maxErr[1]<predErr[1])
				maxErr[1] = predErr[1];
			if(maxErr[2]<predErr[2])
				maxErr[2] = predErr[2];			
				
			counter_++;																
		}
	}
	return maxErr;	
}

double* computeBestPredOrder_d2(SDC_dataset *set)
{
	int counter_ = 0;
	int i,j,k,z,m;
	double X[3], V;
	double predErr[3];
	SDC_data* p; //used for set->head
	SDC_data* q; //used for set->sampHead
	double* maxErr = (double *) malloc(3*sizeof(double)); //max local prediction errors of order0,1,2 respectively
	maxErr[0]=0;
	maxErr[1]=0;
	maxErr[2]=0;
	
	int *X_int;
	float *X_float;
	double *X_double;

	for(i=0;i<set->r2;i++)
		for(j=0;j<set->r1;j++)
		{
			if((i+j)%sdc_manager.samp_distance==0)
			{
				p = set->head;
				
				switch(set->data_type)
				{
					case SDC_INTEGER:
						X_int = (int *)p->next->X; //set->head must have at least one dataset.
						V = X_int[i*set->r1+j];
						break;
					case SDC_FLOAT:
						X_float = (float *)p->next->X;
						V = X_float[i*set->r1+j];
						break;
					case SDC_DOUBLE:
						X_double = (double *)p->next->X;
						V = X_double[i*set->r1+j];
						break;
					default: 
						printf("Error: Wrong data_type. (sdc_solution)");
						exit(0);
				}					
			
				p=p->next;
				
				q = set->sampHead;
				
				for(m=0;m<3;m++)
				{
					if(p->next!=NULL)
					{
						switch(set->data_type)
						{
							case SDC_INTEGER:
								X_int = (int *)p->next->X;
								X[m] = X_int[i*set->r1+j];
								break;
							case SDC_FLOAT:
								X_float = (float *)p->next->X;
								X[m] = X_float[i*set->r1+j];
								break;
							case SDC_DOUBLE:
								X_double = (double *)p->next->X;
								X[m] = X_double[i*set->r1+j];
								break;
							default: 
								printf("Error: Wrong data_type. (sdc_solution)");
								exit(0);
						}
						
						p=p->next;
						continue;
					}
					else
					{
					switch(set->data_type)
					{
						case SDC_INTEGER:
							X_int = (int *)q->next->X;
							X[m] = X_int[counter_];
							break;
						case SDC_FLOAT:
							X_float = (float *)q->next->X;
							X[m] = X_float[counter_];
							break;
						case SDC_DOUBLE:
							X_double = (double *)q->next->X;
							X[m] = X_double[counter_];
							break;
						default: 
							printf("Error: Wrong data_type. (sdc_solution)");
							exit(0);
					}						
						q=q->next;
					}
				}
												
				computeErrors(X,V,predErr);
			
				if(maxErr[0]<predErr[0])
					maxErr[0] = predErr[0];
				if(maxErr[1]<predErr[1])
					maxErr[1] = predErr[1];
				if(maxErr[2]<predErr[2])
					maxErr[2] = predErr[2];			
					
				counter_++;																
			}
		}
	return maxErr;	
}

double* computeBestPredOrder_d3(SDC_dataset *set)
{
	int counter_ = 0;
	int i,j,k,z,m;
	double X[3], V;
	double predErr[3];
	SDC_data* p; //used for set->head
	SDC_data* q; //used for set->sampHead
	double* maxErr = (double *) malloc(3*sizeof(double)); //max local prediction errors of order0,1,2 respectively
	maxErr[0]=0;
	maxErr[1]=0;
	maxErr[2]=0;
	
	int *X_int;
	float *X_float;
	double *X_double;
	
	for(i=0;i<set->r3;i++)
		for(j=0;j<set->r2;j++)
			for(k=0;k<set->r1;k++)
			{
				if((i+j+k)%sdc_manager.samp_distance==0)
				{
					p = set->head;
					
					switch(set->data_type)
					{
						case SDC_INTEGER:
							X_int = (int *)p->next->X; //set->head must have at least one dataset.
							V = X_int[i*set->r2*set->r1+j*set->r1+k];
							break;
						case SDC_FLOAT:
							X_float = (float *)p->next->X;
							V = X_float[i*set->r2*set->r1+j*set->r1+k];
							break;
						case SDC_DOUBLE:
							X_double = (double *)p->next->X;
							V = X_double[i*set->r2*set->r1+j*set->r1+k];
							break;
						default: 
							printf("Error: Wrong data_type. (sdc_solution)");
							exit(0);
					}					
				
					p=p->next;
					
					q = set->sampHead;
					
					for(m=0;m<3;m++)
					{
						if(p->next!=NULL)
						{
							switch(set->data_type)
							{
								case SDC_INTEGER:
									X_int = (int *)p->next->X;
									X[m] = X_int[i*set->r2*set->r1+j*set->r1+k];
									break;
								case SDC_FLOAT:
									X_float = (float *)p->next->X;
									X[m] = X_float[i*set->r2*set->r1+j*set->r1+k];
									break;
								case SDC_DOUBLE:
									X_double = (double *)p->next->X;
									X[m] = X_double[i*set->r2*set->r1+j*set->r1+k];
									break;
								default: 
									printf("Error: Wrong data_type. (sdc_solution)");
									exit(0);
							}
							
							p=p->next;
							continue;
						}
						else
						{
							switch(set->data_type)
							{
								case SDC_INTEGER:
									X_int = (int *)q->next->X;
									X[m] = X_int[counter_];
									break;
								case SDC_FLOAT:
									X_float = (float *)q->next->X;
									X[m] = X_float[counter_];
									break;
								case SDC_DOUBLE:
									X_double = (double *)q->next->X;
									X[m] = X_double[counter_];
									break;
								default: 
									printf("Error: Wrong data_type. (sdc_solution)");
									exit(0);
							}					
							q=q->next;
						}
					}
													
					computeErrors(X,V,predErr);
				
					if(maxErr[0]<predErr[0])
						maxErr[0] = predErr[0];
					if(maxErr[1]<predErr[1])
						maxErr[1] = predErr[1];
					if(maxErr[2]<predErr[2])
						maxErr[2] = predErr[2];			
						
					counter_++;																
				}
			}
	return maxErr;	
}

double* computeBestPredOrder_d4(SDC_dataset *set)
{
	int counter_ = 0;
	int i,j,k,z,m;
	double X[3], V;
	double predErr[3];
	SDC_data* p; //used for set->head
	SDC_data* q; //used for set->sampHead
	double* maxErr = (double *) malloc(3*sizeof(double)); //max local prediction errors of order0,1,2 respectively
	maxErr[0]=0;
	maxErr[1]=0;
	maxErr[2]=0;
	
	int *X_int;
	float *X_float;
	double *X_double;
	
	for(i=0;i<set->r4;i++)
		for(j=0;j<set->r3;j++)
			for(k=0;k<set->r2;k++)
				for(z=0;z<set->r1;z++)
				{
					if((i+j+k+z)%sdc_manager.samp_distance==0)
					{
						p = set->head;
	
						switch(set->data_type)
						{
							case SDC_INTEGER:
								X_int = (int *)p->next->X; //set->head must have at least one dataset.
								V = X_int[i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
								break;
							case SDC_FLOAT:
								X_float = (float *)p->next->X;
								V = X_float[i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
								break;
							case SDC_DOUBLE:
								X_double = (double *)p->next->X;
								V = X_double[i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
								break;
							default: 
								printf("Error: Wrong data_type. (sdc_solution)");
								exit(0);
						}					
						p=p->next;
					
						q = set->sampHead;
					
						for(m=0;m<3;m++)
						{
							if(p->next!=NULL)
							{
								switch(set->data_type)
								{
									case SDC_INTEGER:
										X_int = (int *)p->next->X;
										X[m] = X_int[i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
										break;
									case SDC_FLOAT:
										X_float = (float *)p->next->X;
										X[m] = X_float[i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
										break;
									case SDC_DOUBLE:
										X_double = (double *)p->next->X;
										X[m] = X_double[i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
										break;
									default: 
										printf("Error: Wrong data_type. (sdc_solution)");
										exit(0);
								}
								
								p=p->next;
								continue;
							}
							else
							{
								switch(set->data_type)
								{
									case SDC_INTEGER:
										X_int = (int *)q->next->X;
										X[m] = X_int[counter_];
										break;
									case SDC_FLOAT:
										X_float = (float *)q->next->X;
										X[m] = X_float[counter_];
										break;
									case SDC_DOUBLE:
										X_double = (double *)q->next->X;
										X[m] = X_double[counter_];
										break;
									default: 
										printf("Error: Wrong data_type. (sdc_solution)");
										exit(0);
								}						
								q=q->next;
							}
						}
						computeErrors(X,V,predErr);
						if(maxErr[0]<predErr[0])
							maxErr[0] = predErr[0];
						if(maxErr[1]<predErr[1])
							maxErr[1] = predErr[1];
						if(maxErr[2]<predErr[2])
							maxErr[2] = predErr[2];			
						counter_++;																
					}
				}

	return maxErr;	
}

double* computeBestPredOrder_d5(SDC_dataset *set)
{
	int counter_ = 0;
	int a,i,j,k,z,m;
	double X[3], V;
	double predErr[3];
	SDC_data* p; //used for set->head
	SDC_data* q; //used for set->sampHead
	double* maxErr = (double *) malloc(3*sizeof(double)); //max local prediction errors of order0,1,2 respectively
	maxErr[0]=0;
	maxErr[1]=0;
	maxErr[2]=0;
	
	int *X_int;
	float *X_float;
	double *X_double;
	
	for(a=0;a<set->r5;a++)
		for(i=0;i<set->r4;i++)
			for(j=0;j<set->r3;j++)
				for(k=0;k<set->r2;k++)
					for(z=0;z<set->r1;z++)
					{
						if((a+i+j+k+z)%sdc_manager.samp_distance==0)
						{
							p = set->head;
						
							switch(set->data_type)
							{
								case SDC_INTEGER:
									X_int = (int *)p->next->X; //set->head must have at least one dataset.
									V = X_int[a*set->r4*set->r3*set->r2*set->r1+i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
									break;
								case SDC_FLOAT:
									X_float = (float *)p->next->X;
									V = X_float[a*set->r4*set->r3*set->r2*set->r1+i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
									break;
								case SDC_DOUBLE:
									X_double = (double *)p->next->X;
									V = X_double[a*set->r4*set->r3*set->r2*set->r1+i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
									break;
								default: 
									printf("Error: Wrong data_type. (sdc_solution)");
									exit(0);
							}					
					
							p=p->next;
						
							q = set->sampHead;
						
							for(m=0;m<3;m++)
							{
								if(p->next!=NULL)
								{
									switch(set->data_type)
									{
										case SDC_INTEGER:
											X_int = (int *)p->next->X;
											X[m] = X_int[a*set->r4*set->r3*set->r2*set->r1+i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
											break;
										case SDC_FLOAT:
											X_float = (float *)p->next->X;
											X[m] = X_float[a*set->r4*set->r3*set->r2*set->r1+i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
											break;
										case SDC_DOUBLE:
											X_double = (double *)p->next->X;
											X[m] = X_double[a*set->r4*set->r3*set->r2*set->r1+i*set->r3*set->r2*set->r1+j*set->r2*set->r1+k*set->r1+z];
											break;
										default: 
											printf("Error: Wrong data_type. (sdc_solution)");
											exit(0);
									}
									
									p=p->next;
									continue;
								}
								else
								{
									switch(set->data_type)
									{
										case SDC_INTEGER:
											X_int = (int *)q->next->X;
											X[m] = X_int[counter_];
											break;
										case SDC_FLOAT:
											X_float = (float *)q->next->X;
											X[m] = X_float[counter_];
											break;
										case SDC_DOUBLE:
											X_double = (double *)q->next->X;
											X[m] = X_double[counter_];
											break;
										default: 
											printf("Error: Wrong data_type. (sdc_solution)");
											exit(0);
									}						
									q=q->next;
								}
							}
															
							computeErrors(X,V,predErr);
						
							if(maxErr[0]<predErr[0])
								maxErr[0] = predErr[0];
							if(maxErr[1]<predErr[1])
								maxErr[1] = predErr[1];
							if(maxErr[2]<predErr[2])
								maxErr[2] = predErr[2];			
								
							counter_++;																
						}
					}
	return maxErr;	
}

/**
 * The key algorithm (Algorithm 1): 
 * select the bestfit prediction order
 * 
 * */

int computeBestPredOrder(SDC_dataset *set)
{	
	int m,i,z;
	double theta, range, lambda, validErrBound, outstandErrBound;	
	double minPredErr;
	double* maxErr;
	switch(set->dim)
	{
		case 1:
			maxErr=computeBestPredOrder_d1(set);
			break;
		case 2:
			maxErr=computeBestPredOrder_d2(set);
			break;
		case 3:
			maxErr=computeBestPredOrder_d3(set);
			break;
		case 4:
			maxErr=computeBestPredOrder_d4(set);
			break;
		case 5:
			maxErr=computeBestPredOrder_d5(set);
			break;
		default:
			printf("Error: only support dimention 5 at most\n");
			exit(0);
	}

	/**
	 * Select bestfit prediction order based on our adaptive algorithm.
	 * */
	theta = sdc_manager.impact_err_bound_ratio;
	lambda = sdc_manager.lambda;
	range = set->value_range;

	validErrBound = theta*range;
	m = 0; 
	for(i=0;i<3;i++)
		if(maxErr[i]<validErrBound)
		{
			m = 1;
			break;
		}
	//m == 0 means invalid solution; m==1 means existence	
	if(m==1)
	{
		outstandErrBound = lambda*validErrBound;
		z = 0;
		for(i=0;i<3;i++)
		{
			if(maxErr[i]<outstandErrBound)
			{
				z = 1;
				break;
			}
		}	
		if(z==1) //outstanding solution exists
		{
			//the order with min cost is i
			set->bestfit_order = i;
			set->max_err = maxErr[i];
			free(maxErr);
			return i;
		}
		else //z == 0
		{
			//get the order with min error
			z = 0;
			minPredErr = maxErr[0];
			for(i=1;i<3;i++)
			{
				if(minPredErr>maxErr[i])
				{
					z = i;
					minPredErr = maxErr[i];
				}
			}
			set->bestfit_order = z;
			set->max_err = maxErr[z];
			free(maxErr);
			return z;
		}
	}
	else
	{
		set->bestfit_order = 0;
		set->max_err = maxErr[0];
		free(maxErr);
		return 0;
	}
}

void computeMinMax(void* data, int data_type, int r5, int r4, int r3, int r2, int r1, double minmax[2])
{
	int a,i,j,k,z;	
	double cur_data;
	double min, max;
	
	int *data_int = NULL;
	float *data_float = NULL;
	double *data_double = NULL;
	
	switch(data_type)
	{
		case SDC_INTEGER:
			data_int = (int *)data;
			max = min = data_int[0];
			break;
		case SDC_FLOAT:
			data_float = (float *)data;
			max = min = data_float[0];
			break;
		case SDC_DOUBLE:
			data_double = (double *)data;
			max = min = data_double[0];
			break;
		default: 
			printf("Error: Wrong data_type. (sdc_solution)");
			exit(0);
	}	
	
	if(r1==0) //dimension=0
	{
		printf("doesn't support dimension 0.\n");
		exit(0);
	}
	else if(r2==0) //dimension=1
	{
		switch(data_type)
		{
			case SDC_INTEGER:
				for(i=0;i<r1;i++)
				{
					cur_data = data_int[i];
					if(max<cur_data)
						max = cur_data;
					if(min>cur_data)
						min = cur_data;
				}
				break;
			case SDC_FLOAT:
				for(i=0;i<r1;i++)
				{
					cur_data = data_float[i];
					if(max<cur_data)
						max = cur_data;
					if(min>cur_data)
						min = cur_data;
				}			
				break;
			case SDC_DOUBLE:
				for(i=0;i<r1;i++)
				{
					cur_data = data_double[i];
					if(max<cur_data)
						max = cur_data;
					if(min>cur_data)
						min = cur_data;
				}				
				break;
			default:
				printf("Error: Wrong data_type.\n");
				exit(0);
		}		
	}
	else if(r3==0) //dimension=2
	{
		switch(data_type)
		{
			case SDC_INTEGER:
				for(i=0;i<r2;i++)
					for(j=0;j<r1;j++)
					{
						cur_data = data_int[i*r1+j];
						if(max<cur_data)
							max = cur_data;
						if(min>cur_data)
							min = cur_data;
					}			
				break;
			case SDC_FLOAT:
				for(i=0;i<r2;i++)
					for(j=0;j<r1;j++)
					{
						cur_data = data_float[i*r1+j];
						if(max<cur_data)
							max = cur_data;
						if(min>cur_data)
							min = cur_data;
					}
				break;
			case SDC_DOUBLE:
				for(i=0;i<r2;i++)
					for(j=0;j<r1;j++)
					{
						cur_data = data_double[i*r1+j];
						if(max<cur_data)
							max = cur_data;
						if(min>cur_data)
							min = cur_data;
					}				
				break;
			default:
				printf("Error: Wrong data_type.\n");
				exit(0);
		}
	}
	else if(r4==0) //dimension=3
	{
		switch(data_type)
		{
			case SDC_INTEGER:
				for(i=0;i<r3;i++)
					for(j=0;j<r2;j++)
						for(k=0;k<r1;k++)
						{
							cur_data = data_int[i*r2*r1+j*r1+k];
							if(max<cur_data)
								max = cur_data;
							if(min>cur_data)
								min = cur_data;
						}
				break;
			case SDC_FLOAT:
				for(i=0;i<r3;i++)
					for(j=0;j<r2;j++)
						for(k=0;k<r1;k++)
						{
							cur_data = data_float[i*r2*r1+j*r1+k];
							if(max<cur_data)
								max = cur_data;
							if(min>cur_data)
								min = cur_data;
						}			
				break;
			case SDC_DOUBLE:
				for(i=0;i<r3;i++)
					for(j=0;j<r2;j++)
						for(k=0;k<r1;k++)
						{
							cur_data = data_double[i*r2*r1+j*r1+k];
							if(max<cur_data)
								max = cur_data;
							if(min>cur_data)
								min = cur_data;
						}				
				break;
			default:
				printf("Error: Wrong data_type.\n");
				exit(0);
		}
	}
	else if(r5==0) //dimension=4
	{
		switch(data_type)
		{
			case SDC_INTEGER:
				for(i=0;i<r4;i++)
					for(j=0;j<r3;j++)
						for(k=0;k<r2;k++)
							for(z=0;z<r1;z++)
							{
								cur_data = data_int[i*r3*r2*r1+j*r2*r1+k*r1+z];
								if(max<cur_data)
									max = cur_data;
								if(min>cur_data)
									min = cur_data;
							}
				break;
			case SDC_FLOAT:
				for(i=0;i<r4;i++)
					for(j=0;j<r3;j++)
						for(k=0;k<r2;k++)
							for(z=0;z<r1;z++)
							{
								cur_data = data_float[i*r3*r2*r1+j*r2*r1+k*r1+z];
								if(max<cur_data)
									max = cur_data;
								if(min>cur_data)
									min = cur_data;
							}			
				break;
			case SDC_DOUBLE:
				for(i=0;i<r4;i++)
					for(j=0;j<r3;j++)
						for(k=0;k<r2;k++)
							for(z=0;z<r1;z++)
							{
								cur_data = data_double[i*r3*r2*r1+j*r2*r1+k*r1+z];
								if(max<cur_data)
									max = cur_data;
								if(min>cur_data)
									min = cur_data;
							}				
				break;
			default:
				printf("Error: Wrong data_type.\n");
				exit(0);
		}		
	}
	else //dimension=5
	{
		switch(data_type)
		{
			case SDC_INTEGER:
				for(a=0;a<r5;a++)
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									cur_data = data_int[a*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z];
									if(max<cur_data)
										max = cur_data;
									if(min>cur_data)
										min = cur_data;
								}
				break;
			case SDC_FLOAT:
				for(a=0;a<r5;a++)
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									cur_data = data_float[a*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z];
									if(max<cur_data)
										max = cur_data;
									if(min>cur_data)
										min = cur_data;
								}			
				break;
			case SDC_DOUBLE:
				for(a=0;a<r5;a++)
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									cur_data = data_double[a*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z];
									if(max<cur_data)
										max = cur_data;
									if(min>cur_data)
										min = cur_data;
								}				
				break;
			default:
				printf("Error: Wrong data_type.\n");
				exit(0);
		}				
	}

	minmax[0] = min;
	minmax[1] = max;
}

void aggregate_value_range()
{
	int i;
	double minmax[2], range;
	//compute local max and min
	int size = dataset_head->r1;
	double local_min_array[size];
	double local_max_array[size];
	double global_min_array[size];
	double global_max_array[size];
	SDC_dataset *p = dataset_head;
	
	if(sdc_manager.valuerange_counter < counter/sdc_manager.collect_value_range_rate) 
	{
		for(i=0;p->next!=NULL;i++)
		{
			computeMinMax(p->next->head->next->X, p->next->data_type, p->next->r5, p->next->r4, p->next->r3, p->next->r2, p->next->r1, minmax);
			local_min_array[i] = minmax[0];
			local_max_array[i] = minmax[1];
			p = p->next;
		}
		
		//use MPI_Allreduce to compute global max and min
		MPI_Allreduce(local_min_array, global_min_array, size, MPI_DOUBLE, MPI_MIN, SDC_COMM_WORLD);
		MPI_Allreduce(local_max_array, global_max_array, size, MPI_DOUBLE, MPI_MAX, SDC_COMM_WORLD);
		
		p = dataset_head;
		for(i=0;p->next!=NULL;i++)
		{
			range = global_max_array[i] - global_min_array[i];
			if(range==0)
				range = sdc_manager.floor;
			p->next->value_range = range;
			p=p->next;
		}
		//Mark this aggregation operation to avoid repeated operations when dealing with other variables...
		sdc_manager.valuerange_counter = counter/sdc_manager.collect_value_range_rate;
	}
}

////////////////////////////////////Following are prediction methods/////////////////////////////////////////
////prediction with dimension 5
int quadraticCurveFitting(SDC_dataset *pp, void* var)
{
	int index;
	char buf[SDC_BUFS];
	int existError = 0;
	double a, b, threshold, abs_err;
	int r1,r2,r3,r4,r5;
	SDC_data *p;
	int w,i,j,k,z;
	void* XT_1;
	void* XT_2;
	void* XT_3;
	double pred_v1, pred_final;

	int * XT_1_int, * XT_2_int, * XT_3_int;
	float * XT_1_float, * XT_2_float, * XT_3_float;
	double * XT_1_double, * XT_2_double, * XT_3_double;
	
	int *var_int;
	float *var_float;
	double *var_double;
	
	p = pp->head->next;
	XT_1=p->X;
	p=p->next;
	XT_2=p->X;
	p=p->next;
	XT_3=p->X;
	
	r1=pp->r1; 
	r2=pp->r2;
	r3=pp->r3;
	r4=pp->r4; 
	r5=pp->r5;
	//perform prediction
	
	switch(pp->data_type)
	{
		case SDC_INTEGER:
			var_int = (int *)var;
			XT_1_int = (int *)XT_1;
			XT_2_int = (int *)XT_2;
			XT_3_int = (int *)XT_3;
			switch(pp->dim)
			{
				case 1:
					for(i=0;i<r1;i++)
					{
						pred_final = pred_v1 = 3*XT_1_int[i]-3*XT_2_int[i]+XT_3_int[i];
						if(sdc_manager.sol_ID==SDC_AID)
						{
							abs_err = abs_(pred_final - var_int[i]);
							threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
							if(abs_err > threshold)
							{
								existError = 1;
								break; // remove break??
							}
						}
						else
						{										
							printf("Error: Wrong sol_ID. This version doesn't support other solution.");
							exit(0);
						}
					}					
					break;
				case 2:
					for(i=0;i<r2;i++)
						for(j=0;j<r1;j++)
						{
							int index = i*r1+j;
							pred_final = pred_v1 = 3*XT_1_int[index]-3*XT_2_int[index]+XT_3_int[index];
							if(sdc_manager.sol_ID==SDC_AID)
							{
								threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
								abs_err = abs_(pred_final - var_int[index]);
								if(abs_err > threshold)
								{
									existError = 1;
									break; // remove break??
								}
							}
							else
							{										
								printf("Error: Wrong sol_ID. This version doesn't support other solution.");
								exit(0);
							}
						}
					break;
				case 3:
					for(i=0;i<r3;i++)
						for(j=0;j<r2;j++)
							for(k=0;k<r1;k++)
							{
								index = i*r2*r1+j*r1+k;
								pred_final = pred_v1 = 3*XT_1_int[index]-3*XT_2_int[index]+XT_3_int[index];
								if(sdc_manager.sol_ID==SDC_AID)
								{
									threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
									abs_err = abs_(pred_final - var_int[index]);
									if(abs_err > threshold)
									{
										existError = 1;
										break; // remove break??
									}
								}
								else
								{										
									printf("Error: Wrong sol_ID. This version doesn't support other solution.");
									exit(0);
								}
							}
					break;
				case 4:
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									index = i*r3*r2*r1+j*r2*r1+k*r1+z;
									pred_final = pred_v1 = 3*XT_1_int[index]-3*XT_2_int[index]+XT_3_int[index];
									if(sdc_manager.sol_ID==SDC_AID)
									{
										threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
										abs_err = abs_(pred_final - var_int[index]);
										if(abs_err > threshold)
										{
											existError = 1;
											break; // remove break??
										}
									}
									else
									{										
										printf("Error: Wrong sol_ID. This version doesn't support other solution.");
										exit(0);
									}
								}			
					break;
				case 5:
					for(w=0;w<r5;w++)
						for(i=0;i<r4;i++)
							for(j=0;j<r3;j++)
								for(k=0;k<r2;k++)
									for(z=0;z<r1;z++)
									{
										index = w*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z;
										pred_final = pred_v1 = 3*XT_1_int[index]-3*XT_2_int[index]+XT_3_int[index];
										if(sdc_manager.sol_ID==SDC_AID)
										{
											threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
											abs_err = abs_(pred_final - var_int[index]);
											if(abs_err > threshold)
											{
												existError = 1;
												break; // remove break??
											}
										}
										else
										{										
											printf("Error: Wrong sol_ID. This version doesn't support other solution.");
											exit(0);
										}
									}
					break;
				default:
					printf("Error: doesn't support dimension 6 or higher.\n");
					exit(0);
			}
			break;
		case SDC_FLOAT:
			var_float = (float *)var;
			XT_1_float = (float *)XT_1;
			XT_2_float = (float *)XT_2;
			XT_3_float = (float *)XT_3;
			switch(pp->dim)
			{
				case 1:
					for(i=0;i<r1;i++)
					{
						pred_final = pred_v1 = 3*XT_1_float[i]-3*XT_2_float[i]+XT_3_float[i];
						if(sdc_manager.sol_ID==SDC_AID)
						{
							threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
							abs_err = abs_(pred_final - var_float[i]);
							if(abs_err > threshold)
							{
								existError = 1;
								break; // remove break??
							}
						}
						else
						{										
							printf("Error: Wrong sol_ID. This version doesn't support other solution.");
							exit(0);
						}
					}					
					break;
				case 2:
					for(i=0;i<r2;i++)
						for(j=0;j<r1;j++)
						{
							int index = i*r1+j;
							pred_final = pred_v1 = 3*XT_1_float[index]-3*XT_2_float[index]+XT_3_float[index];
							if(sdc_manager.sol_ID==SDC_AID)
							{
								threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
								abs_err = abs_(pred_final - var_float[index]);
								if(abs_err > threshold)
								{
									existError = 1;
									break; // remove break??
								}
							}
							else
							{										
								printf("Error: Wrong sol_ID. This version doesn't support other solution.");
								exit(0);
							}
						}
					break;
				case 3:
					for(i=0;i<r3;i++)
						for(j=0;j<r2;j++)
							for(k=0;k<r1;k++)
							{
								index = i*r2*r1+j*r1+k;
								pred_final = pred_v1 = 3*XT_1_float[index]-3*XT_2_float[index]+XT_3_float[index];
								if(sdc_manager.sol_ID==SDC_AID)
								{
									threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
									abs_err = abs_(pred_final - var_float[index]);
									if(abs_err > threshold)
									{
										existError = 1;
										break; // remove break??
									}
								}
								else
								{										
									printf("Error: Wrong sol_ID. This version doesn't support other solution.");
									exit(0);
								}
							}
					break;
				case 4:
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									index = i*r3*r2*r1+j*r2*r1+k*r1+z;
									pred_final = pred_v1 = 3*XT_1_float[index]-3*XT_2_float[index]+XT_3_float[index];
									if(sdc_manager.sol_ID==SDC_AID)
									{
										threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
										abs_err = abs_(pred_final - var_float[index]);
										if(abs_err > threshold)
										{
											existError = 1;
											break; // remove break??
										}
									}
									else
									{										
										printf("Error: Wrong sol_ID. This version doesn't support other solution.");
										exit(0);
									}
								}			
					break;
				case 5:
					for(w=0;w<r5;w++)
						for(i=0;i<r4;i++)
							for(j=0;j<r3;j++)
								for(k=0;k<r2;k++)
									for(z=0;z<r1;z++)
									{
										index = w*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z;
										pred_final = pred_v1 = 3*XT_1_float[index]-3*XT_2_float[index]+XT_3_float[index];
										if(sdc_manager.sol_ID==SDC_AID)
										{
											threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
											abs_err = abs_(pred_final - var_float[index]);
											if(abs_err > threshold)
											{
												existError = 1;
												break; // remove break??
											}
										}
										else
										{										
											printf("Error: Wrong sol_ID. This version doesn't support other solution.");
											exit(0);
										}
									}
					break;
				default:
					printf("Error: doesn't support dimension 6 or higher.\n");
					exit(0);
			}		
			break;
		case SDC_DOUBLE:
			var_double = (double *)var;
			XT_1_double = (double *)XT_1;
			XT_2_double = (double *)XT_2;
			XT_3_double = (double *)XT_3;
			switch(pp->dim)
			{
				case 1:
					for(i=0;i<r1;i++)
					{
						pred_final = pred_v1 = 3*XT_1_double[i]-3*XT_2_double[i]+XT_3_double[i];
						if(sdc_manager.sol_ID==SDC_AID)
						{
							threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
							abs_err = abs_(pred_final - var_double[i]);
							if(abs_err > threshold)
							{
								existError = 1;
								break; // remove break??
							}
						}
						else
						{										
							printf("Error: Wrong sol_ID. This version doesn't support other solution.");
							exit(0);
						}
					}					
					break;
				case 2:
					for(i=0;i<r2;i++)
						for(j=0;j<r1;j++)
						{
							int index = i*r1+j;
							pred_final = pred_v1 = 3*XT_1_double[index]-3*XT_2_double[index]+XT_3_double[index];
							if(sdc_manager.sol_ID==SDC_AID)
							{
								threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
								abs_err = abs_(pred_final - var_double[index]);
								if(abs_err > threshold)
								{
									existError = 1;
									break; // remove break??
								}
							}
							else
							{										
								printf("Error: Wrong sol_ID. This version doesn't support other solution.");
								exit(0);
							}
						}
					break;
				case 3:
					for(i=0;i<r3;i++)
						for(j=0;j<r2;j++)
							for(k=0;k<r1;k++)
							{
								index = i*r2*r1+j*r1+k;
								pred_final = pred_v1 = 3*XT_1_double[index]-3*XT_2_double[index]+XT_3_double[index];
								if(sdc_manager.sol_ID==SDC_AID)
								{
									threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
									abs_err = abs_(pred_final - var_double[index]);
									if(abs_err > threshold)
									{
										existError = 1;
										break; // remove break??
									}
								}
								else
								{										
									printf("Error: Wrong sol_ID. This version doesn't support other solution.");
									exit(0);
								}
							}
					break;
				case 4:
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									index = i*r3*r2*r1+j*r2*r1+k*r1+z;
									pred_final = pred_v1 = 3*XT_1_double[index]-3*XT_2_double[index]+XT_3_double[index];
									if(sdc_manager.sol_ID==SDC_AID)
									{
										threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
										abs_err = abs_(pred_final - var_double[index]);
										if(abs_err > threshold)
										{
											existError = 1;
											break; // remove break??
										}
									}
									else
									{										
										printf("Error: Wrong sol_ID. This version doesn't support other solution.");
										exit(0);
									}
								}			
					break;
				case 5:
					for(w=0;w<r5;w++)
						for(i=0;i<r4;i++)
							for(j=0;j<r3;j++)
								for(k=0;k<r2;k++)
									for(z=0;z<r1;z++)
									{
										index = w*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z;
										pred_final = pred_v1 = 3*XT_1_double[index]-3*XT_2_double[index]+XT_3_double[index];
										if(sdc_manager.sol_ID==SDC_AID)
										{
											threshold = sdc_manager.impact_err_bound_ratio*pp->value_range*pp->FPNum;
											abs_err = abs_(pred_final - var_double[index]);
											if(abs_err > threshold)
											{
												existError = 1;
												break; // remove break??
											}
										}
										else
										{										
											printf("Error: Wrong sol_ID. This version doesn't support other solution.");
											exit(0);
										}
									}
					break;
				default:
					printf("Error: doesn't support dimension 6 or higher.\n");
					exit(0);
			}			
			break;
		default: 
			printf("Error: Wrong data_type.");
			exit(0);
	}

	return existError;
}

int linearCurveFitting(SDC_dataset *pp, void* var)
{
	int index;
	char buf[SDC_BUFS];
	int existError = 0;
	double a, b, threshold, abs_err;
	int r1,r2,r3,r4,r5;
	SDC_data *p;
	int w,i,j,k,z;
	void* XT_1;
	void* XT_2;
//	void* XT_3;
	double pred_v1, pred_final;

	int * XT_1_int, * XT_2_int;
	float * XT_1_float, * XT_2_float;
	double * XT_1_double, * XT_2_double;
	
	int *var_int;
	float *var_float;
	double *var_double;
	
	p = pp->head->next;
	XT_1=p->X;
	p=p->next;
	XT_2=p->X;
//	p=p->next;
//	XT_3=p->X;
	
	r1=pp->r1; 
	r2=pp->r2;
	r3=pp->r3;
	r4=pp->r4; 
	r5=pp->r5;
	//perform prediction
	
	switch(pp->data_type)
	{
		case SDC_INTEGER:
			var_int = (int *)var;
			XT_1_int = (int *)XT_1;
			XT_2_int = (int *)XT_2;
			switch(pp->dim)
			{
				case 1:
					for(i=0;i<r1;i++)
					{
						pred_final = pred_v1 = 2*XT_1_int[i]-XT_2_int[i];
						if(sdc_manager.sol_ID==SDC_AID)
						{
							threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
							abs_err = abs_(pred_final - var_int[i]);
							if(abs_err > threshold)
							{
								existError = 1;
								break; // remove break??
							}
						}
						else
						{										
							printf("Error: Wrong sol_ID. This version doesn't support other solution.");
							exit(0);
						}
					}					
					break;
				case 2:
					for(i=0;i<r2;i++)
						for(j=0;j<r1;j++)
						{
							int index = i*r1+j;
							pred_final = pred_v1 = 2*XT_1_int[index]-XT_2_int[index];
							if(sdc_manager.sol_ID==SDC_AID)
							{
								threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
								abs_err = abs_(pred_final - var_int[index]);
								if(abs_err > threshold)
								{
									existError = 1;
									break; // remove break??
								}
							}
							else
							{										
								printf("Error: Wrong sol_ID. This version doesn't support other solution.");
								exit(0);
							}
						}
					break;
				case 3:
					for(i=0;i<r3;i++)
						for(j=0;j<r2;j++)
							for(k=0;k<r1;k++)
							{
								index = i*r2*r1+j*r1+k;
								pred_final = pred_v1 = 2*XT_1_int[index]-XT_2_int[index];
								if(sdc_manager.sol_ID==SDC_AID)
								{
									threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
									abs_err = abs_(pred_final - var_int[index]);
									if(abs_err > threshold)
									{
										existError = 1;
										break; // remove break??
									}
								}
								else
								{										
									printf("Error: Wrong sol_ID. This version doesn't support other solution.");
									exit(0);
								}
							}
					break;
				case 4:
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									index = i*r3*r2*r1+j*r2*r1+k*r1+z;
									pred_final = pred_v1 = 2*XT_1_int[index]-XT_2_int[index];
									if(sdc_manager.sol_ID==SDC_AID)
									{
										threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
										abs_err = abs_(pred_final - var_int[index]);
										if(abs_err > threshold)
										{
											existError = 1;
											break; // remove break??
										}
									}
									else
									{										
										printf("Error: Wrong sol_ID. This version doesn't support other solution.");
										exit(0);
									}
								}			
					break;
				case 5:
					for(w=0;w<r5;w++)
						for(i=0;i<r4;i++)
							for(j=0;j<r3;j++)
								for(k=0;k<r2;k++)
									for(z=0;z<r1;z++)
									{
										index = w*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z;
										pred_final = pred_v1 = 2*XT_1_int[index]-XT_2_int[index];
										if(sdc_manager.sol_ID==SDC_AID)
										{
											threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
											abs_err = abs_(pred_final - var_int[index]);
											if(abs_err > threshold)
											{
												existError = 1;
												break; // remove break??
											}
										}
										else
										{										
											printf("Error: Wrong sol_ID. This version doesn't support other solution.");
											exit(0);
										}
									}
					break;
				default:
					printf("Error: doesn't support dimension 6 or higher.\n");
					exit(0);
			}
			break;
		case SDC_FLOAT:
			var_float = (float *)var;
			XT_1_float = (float *)XT_1;
			XT_2_float = (float *)XT_2;
			switch(pp->dim)
			{
				case 1:
					for(i=0;i<r1;i++)
					{
						pred_final = pred_v1 = 2*XT_1_float[i]-XT_2_float[i];
						if(sdc_manager.sol_ID==SDC_AID)
						{
							threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
							abs_err = abs_(pred_final - var_float[i]);
							if(abs_err > threshold)
							{
								existError = 1;
								break; // remove break??
							}
						}
						else
						{										
							printf("Error: Wrong sol_ID. This version doesn't support other solution.");
							exit(0);
						}
					}					
					break;
				case 2:
					for(i=0;i<r2;i++)
						for(j=0;j<r1;j++)
						{
							int index = i*r1+j;
							pred_final = pred_v1 = 2*XT_1_float[index]-XT_2_float[index];
							if(sdc_manager.sol_ID==SDC_AID)
							{
								threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
								abs_err = abs_(pred_final - var_float[index]);
								if(abs_err > threshold)
								{
									existError = 1;
									break; // remove break??
								}
							}
							else
							{										
								printf("Error: Wrong sol_ID. This version doesn't support other solution.");
								exit(0);
							}
						}
					break;
				case 3:
					for(i=0;i<r3;i++)
						for(j=0;j<r2;j++)
							for(k=0;k<r1;k++)
							{
								index = i*r2*r1+j*r1+k;
								pred_final = pred_v1 = 2*XT_1_float[index]-XT_2_float[index];
								if(sdc_manager.sol_ID==SDC_AID)
								{
									threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
									abs_err = abs_(pred_final - var_float[index]);
									if(abs_err > threshold)
									{
										existError = 1;
										break; // remove break??
									}
								}
								else
								{										
									printf("Error: Wrong sol_ID. This version doesn't support other solution.");
									exit(0);
								}
							}
					break;
				case 4:
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									index = i*r3*r2*r1+j*r2*r1+k*r1+z;
									pred_final = pred_v1 = 2*XT_1_float[index]-XT_2_float[index];
									if(sdc_manager.sol_ID==SDC_AID)
									{
										threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
										abs_err = abs_(pred_final - var_float[index]);
										if(abs_err > threshold)
										{
											existError = 1;
											break; // remove break??
										}
									}
									else
									{										
										printf("Error: Wrong sol_ID. This version doesn't support other solution.");
										exit(0);
									}
								}			
					break;
				case 5:
					for(w=0;w<r5;w++)
						for(i=0;i<r4;i++)
							for(j=0;j<r3;j++)
								for(k=0;k<r2;k++)
									for(z=0;z<r1;z++)
									{
										index = w*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z;
										pred_final = pred_v1 = 2*XT_1_float[index]-XT_2_float[index];
										if(sdc_manager.sol_ID==SDC_AID)
										{
											threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
											abs_err = abs_(pred_final - var_float[index]);
											if(abs_err > threshold)
											{
												existError = 1;
												break; // remove break??
											}
										}
										else
										{										
											printf("Error: Wrong sol_ID. This version doesn't support other solution.");
											exit(0);
										}
									}
					break;
				default:
					printf("Error: doesn't support dimension 6 or higher.\n");
					exit(0);
			}		
			break;
		case SDC_DOUBLE:
			var_double = (double *)var;
			XT_1_double = (double *)XT_1;
			XT_2_double = (double *)XT_2;
			switch(pp->dim)
			{
				case 1:
					for(i=0;i<r1;i++)
					{
						pred_final = pred_v1 = 2*XT_1_double[i]-XT_2_double[i];
						if(sdc_manager.sol_ID==SDC_AID)
						{
							threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
							abs_err = abs_(pred_final - var_double[i]);
							if(abs_err > threshold)
							{
								existError = 1;
								break; // remove break??
							}
						}
						else
						{										
							printf("Error: Wrong sol_ID. This version doesn't support other solution.");
							exit(0);
						}
					}					
					break;
				case 2:
					for(i=0;i<r2;i++)
						for(j=0;j<r1;j++)
						{
							int index = i*r1+j;
							pred_final = pred_v1 = 2*XT_1_double[index]-XT_2_double[index];
							if(sdc_manager.sol_ID==SDC_AID)
							{
								threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
								abs_err = abs_(pred_final - var_double[index]);
								if(abs_err > threshold)
								{
									existError = 1;
									break; // remove break??
								}
							}
							else
							{										
								printf("Error: Wrong sol_ID. This version doesn't support other solution.");
								exit(0);
							}
						}
					break;
				case 3:
					for(i=0;i<r3;i++)
						for(j=0;j<r2;j++)
							for(k=0;k<r1;k++)
							{
								index = i*r2*r1+j*r1+k;
								pred_final = pred_v1 = 2*XT_1_double[index]-XT_2_double[index];
								if(sdc_manager.sol_ID==SDC_AID)
								{
									threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
									abs_err = abs_(pred_final - var_double[index]);
									if(abs_err > threshold)
									{
										existError = 1;
										break; // remove break??
									}
								}
								else
								{										
									printf("Error: Wrong sol_ID. This version doesn't support other solution.");
									exit(0);
								}
							}
					break;
				case 4:
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									index = i*r3*r2*r1+j*r2*r1+k*r1+z;
									pred_final = pred_v1 = 2*XT_1_double[index]-XT_2_double[index];
									if(sdc_manager.sol_ID==SDC_AID)
									{
										threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
										abs_err = abs_(pred_final - var_double[index]);
										if(abs_err > threshold)
										{
											existError = 1;
											break; // remove break??
										}
									}
									else
									{										
										printf("Error: Wrong sol_ID. This version doesn't support other solution.");
										exit(0);
									}
								}			
					break;
				case 5:
					for(w=0;w<r5;w++)
						for(i=0;i<r4;i++)
							for(j=0;j<r3;j++)
								for(k=0;k<r2;k++)
									for(z=0;z<r1;z++)
									{
										index = w*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z;
										pred_final = pred_v1 = 2*XT_1_double[index]-XT_2_double[index];
										if(sdc_manager.sol_ID==SDC_AID)
										{
											threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
											abs_err = abs_(pred_final - var_double[index]);
											if(abs_err > threshold)
											{
												existError = 1;
												break; // remove break??
											}
										}
										else
										{										
											printf("Error: Wrong sol_ID. This version doesn't support other solution.");
											exit(0);
										}
									}
					break;
				default:
					printf("Error: doesn't support dimension 6 or higher.\n");
					exit(0);
			}			
			break;
		default: 
			printf("Error: Wrong data_type.");
			exit(0);
	}

	return existError;
}

int lastStateFitting(SDC_dataset *pp, void* var)
{
	int index;
	char buf[SDC_BUFS];
	int existError = 0;
	double a, b, threshold, abs_err;
	int r1,r2,r3,r4,r5;
	SDC_data *p;
	int w,i,j,k,z;
	void* XT_1;
//	void* XT_2;
//	void* XT_3;
	double pred_v1, pred_final;

	int * XT_1_int;
	float * XT_1_float;
	double * XT_1_double;
	
	int *var_int;
	float *var_float;
	double *var_double;
	
	p = pp->head->next;
	XT_1=p->X;
//	p=p->next;
//	XT_2=p->X;
//	p=p->next;
//	XT_3=p->X;
	
	r1=pp->r1; 
	r2=pp->r2;
	r3=pp->r3;
	r4=pp->r4; 
	r5=pp->r5;
	//perform prediction
	
	switch(pp->data_type)
	{
		case SDC_INTEGER:
			var_int = (int *)var;
			XT_1_int = (int *)XT_1;
			switch(pp->dim)
			{
				case 1:
					for(i=0;i<r1;i++)
					{
						pred_final = pred_v1 = XT_1_int[i];
						if(sdc_manager.sol_ID==SDC_AID)
						{
							threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
							abs_err = abs_(pred_final - var_int[i]);
							if(abs_err > threshold)
							{
								existError = 1;
								break; // remove break??
							}
						}
						else
						{										
							printf("Error: Wrong sol_ID. This version doesn't support other solution.");
							exit(0);
						}
					}					
					break;
				case 2:
					for(i=0;i<r2;i++)
						for(j=0;j<r1;j++)
						{
							int index = i*r1+j;
							pred_final = pred_v1 = XT_1_int[index];
							if(sdc_manager.sol_ID==SDC_AID)
							{
								threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
								abs_err = abs_(pred_final - var_int[index]);
								if(abs_err > threshold)
								{
									existError = 1;
									break; // remove break??
								}
							}
							else
							{										
								printf("Error: Wrong sol_ID. This version doesn't support other solution.");
								exit(0);
							}
						}
					break;
				case 3:
					for(i=0;i<r3;i++)
						for(j=0;j<r2;j++)
							for(k=0;k<r1;k++)
							{
								index = i*r2*r1+j*r1+k;
								pred_final = pred_v1 = XT_1_int[index];
								if(sdc_manager.sol_ID==SDC_AID)
								{
									threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
									abs_err = abs_(pred_final - var_int[index]);
									if(abs_err > threshold)
									{
										existError = 1;
										break; // remove break??
									}
								}
								else
								{										
									printf("Error: Wrong sol_ID. This version doesn't support other solution.");
									exit(0);
								}
							}
					break;
				case 4:
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									index = i*r3*r2*r1+j*r2*r1+k*r1+z;
									pred_final = pred_v1 = XT_1_int[index];
									if(sdc_manager.sol_ID==SDC_AID)
									{
										threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
										abs_err = abs_(pred_final - var_int[index]);
										if(abs_err > threshold)
										{
											existError = 1;
											break; // remove break??
										}
									}
									else
									{										
										printf("Error: Wrong sol_ID. This version doesn't support other solution.");
										exit(0);
									}
								}			
					break;
				case 5:
					for(w=0;w<r5;w++)
						for(i=0;i<r4;i++)
							for(j=0;j<r3;j++)
								for(k=0;k<r2;k++)
									for(z=0;z<r1;z++)
									{
										index = w*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z;
										pred_final = pred_v1 = XT_1_int[index];
										if(sdc_manager.sol_ID==SDC_AID)
										{
											threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
											abs_err = abs_(pred_final - var_int[index]);
											if(abs_err > threshold)
											{
												existError = 1;
												break; // remove break??
											}
										}
										else
										{										
											printf("Error: Wrong sol_ID. This version doesn't support other solution.");
											exit(0);
										}
									}
					break;
				default:
					printf("Error: doesn't support dimension 6 or higher.\n");
					exit(0);
			}
			break;
		case SDC_FLOAT:
			var_float = (float *)var;
			XT_1_float = (float *)XT_1;
			switch(pp->dim)
			{
				case 1:
					for(i=0;i<r1;i++)
					{
						pred_final = pred_v1 = XT_1_float[i];
						if(sdc_manager.sol_ID==SDC_AID)
						{
							threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
							abs_err = abs_(pred_final - var_float[i]);
							if(abs_err > threshold)
							{
								existError = 1;
								break; // remove break??
							}
						}
						else
						{										
							printf("Error: Wrong sol_ID. This version doesn't support other solution.");
							exit(0);
						}
					}					
					break;
				case 2:
					for(i=0;i<r2;i++)
						for(j=0;j<r1;j++)
						{
							int index = i*r1+j;
							pred_final = pred_v1 = XT_1_float[index];
							if(sdc_manager.sol_ID==SDC_AID)
							{
								threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
								abs_err = abs_(pred_final - var_float[index]);
								if(abs_err > threshold)
								{
									existError = 1;
									break; // remove break??
								}
							}
							else
							{										
								printf("Error: Wrong sol_ID. This version doesn't support other solution.");
								exit(0);
							}
						}
					break;
				case 3:
					for(i=0;i<r3;i++)
						for(j=0;j<r2;j++)
							for(k=0;k<r1;k++)
							{
								index = i*r2*r1+j*r1+k;
								pred_final = pred_v1 = XT_1_float[index];
								if(sdc_manager.sol_ID==SDC_AID)
								{
									threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
									abs_err = abs_(pred_final - var_float[index]);
									if(abs_err > threshold)
									{
										existError = 1;
										break; // remove break??
									}
								}
								else
								{										
									printf("Error: Wrong sol_ID. This version doesn't support other solution.");
									exit(0);
								}
							}
					break;
				case 4:
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									index = i*r3*r2*r1+j*r2*r1+k*r1+z;
									pred_final = pred_v1 = XT_1_float[index];
									if(sdc_manager.sol_ID==SDC_AID)
									{
										threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
										abs_err = abs_(pred_final - var_float[index]);
										if(abs_err > threshold)
										{
											existError = 1;
											break; // remove break??
										}
									}
									else
									{										
										printf("Error: Wrong sol_ID. This version doesn't support other solution.");
										exit(0);
									}
								}			
					break;
				case 5:
					for(w=0;w<r5;w++)
						for(i=0;i<r4;i++)
							for(j=0;j<r3;j++)
								for(k=0;k<r2;k++)
									for(z=0;z<r1;z++)
									{
										index = w*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z;
										pred_final = pred_v1 = XT_1_float[index];
										if(sdc_manager.sol_ID==SDC_AID)
										{
											threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
											abs_err = abs_(pred_final - var_float[index]);
											if(abs_err > threshold)
											{
												existError = 1;
												break; // remove break??
											}
										}
										else
										{										
											printf("Error: Wrong sol_ID. This version doesn't support other solution.");
											exit(0);
										}
									}
					break;
				default:
					printf("Error: doesn't support dimension 6 or higher.\n");
					exit(0);
			}		
			break;
		case SDC_DOUBLE:
			var_double = (double *)var;
			XT_1_double = (double *)XT_1;
			switch(pp->dim)
			{
				case 1:
					for(i=0;i<r1;i++)
					{
						pred_final = pred_v1 = XT_1_double[i];
						if(sdc_manager.sol_ID==SDC_AID)
						{
							threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
							abs_err = abs_(pred_final - var_double[i]);
							if(abs_err > threshold)
							{
								existError = 1;
								break; // remove break??
							}
						}
						else
						{										
							printf("Error: Wrong sol_ID. This version doesn't support other solution.");
							exit(0);
						}
					}					
					break;
				case 2:
					for(i=0;i<r2;i++)
						for(j=0;j<r1;j++)
						{
							int index = i*r1+j;
							pred_final = pred_v1 = XT_1_double[index];
							if(sdc_manager.sol_ID==SDC_AID)
							{
								threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
								abs_err = abs_(pred_final - var_double[index]);
								if(abs_err > threshold)
								{
									existError = 1;
									break; // remove break??
								}
							}
							else
							{										
								printf("Error: Wrong sol_ID. This version doesn't support other solution.");
								exit(0);
							}
						}
					break;
				case 3:
					for(i=0;i<r3;i++)
						for(j=0;j<r2;j++)
							for(k=0;k<r1;k++)
							{
								index = i*r2*r1+j*r1+k;
								pred_final = pred_v1 = XT_1_double[index];
								if(sdc_manager.sol_ID==SDC_AID)
								{
									threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
									abs_err = abs_(pred_final - var_double[index]);
									if(abs_err > threshold)
									{
										existError = 1;
										break; // remove break??
									}
								}
								else
								{										
									printf("Error: Wrong sol_ID. This version doesn't support other solution.");
									exit(0);
								}
							}
					break;
				case 4:
					for(i=0;i<r4;i++)
						for(j=0;j<r3;j++)
							for(k=0;k<r2;k++)
								for(z=0;z<r1;z++)
								{
									index = i*r3*r2*r1+j*r2*r1+k*r1+z;
									pred_final = pred_v1 = XT_1_double[index];
									if(sdc_manager.sol_ID==SDC_AID)
									{
										threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
										abs_err = abs_(pred_final - var_double[index]);
										if(abs_err > threshold)
										{
											existError = 1;
											break; // remove break??
										}
									}
									else
									{										
										printf("Error: Wrong sol_ID. This version doesn't support other solution.");
										exit(0);
									}
								}			
					break;
				case 5:
					for(w=0;w<r5;w++)
						for(i=0;i<r4;i++)
							for(j=0;j<r3;j++)
								for(k=0;k<r2;k++)
									for(z=0;z<r1;z++)
									{
										index = w*r4*r3*r2*r1+i*r3*r2*r1+j*r2*r1+k*r1+z;
										pred_final = pred_v1 = XT_1_double[index];
										if(sdc_manager.sol_ID==SDC_AID)
										{
											threshold = pp->FPNum*(pp->max_err + sdc_manager.impact_err_bound_ratio*pp->value_range);
											abs_err = abs_(pred_final - var_double[index]);
											if(abs_err > threshold)
											{
												existError = 1;
												break; // remove break??
											}
										}
										else
										{										
											printf("Error: Wrong sol_ID. This version doesn't support other solution.");
											exit(0);
										}
									}
					break;
				default:
					printf("Error: doesn't support dimension 6 or higher.\n");
					exit(0);
			}			
			break;
		default: 
			printf("Error: Wrong data_type.");
			exit(0);
	}

	return existError;
}

int adaptiveImpactDriven(SDC_dataset *pp, void* var)
{
	int curLength;
	int existError = 0, validBestfitOrder;
	
	if(counter%sdc_manager.collect_value_range_rate==StartStepNum) 
	{
		//MPI_Allreduce() and compute sdc_manager.value_range=max-min
		if(sdc_manager.fixed_value_range<0)
		{
			aggregate_value_range();
		}	
	}
	if(counter%sdc_manager.check_bestfit_rate==StartStepNum)
	{
		//just need to check sample data set, which is constructed in the adaptive_updateData_d4 function of sdc_datasetlist.c
		computeBestPredOrder(pp);
	}
	validBestfitOrder = computeValidBestOrder(pp, pp->bestfit_order);
	curLength = compute_curStepLength(pp->head);

	//perform the prediction and detection
	switch(validBestfitOrder)
	{
		case 0: 
			existError = lastStateFitting(pp, var);
			break;
		case 1:
			existError = linearCurveFitting(pp, var);
			break;
		case 2:
			existError = quadraticCurveFitting(pp, var);
			break;
	}
	return existError;
}
