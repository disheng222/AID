/**
 *  @file   sdc_memalloc.c
 *  @author Sheng Di (disheng222@gmail.com)
 *  @date   Aug., 2014
 *  @brief  allocating memory for some data structures used in SDC
 */

#include <stdlib.h>
#include <stdio.h>
#include "sdc_datalist.h"
#include "sdc_detector.h"


void copy_p(void* data, void **data_, int data_type, int dim, int r5, int r4,int r3, int r2, int r1)
{
	int total_size,i;
	int *data_int, *X_int;
	float *data_float, *X_float;
	double *data_double, *X_double;
	switch(data_type)
	{
		case SDC_INTEGER:
			switch(dim)
			{
				case 1:
					total_size = r1;
					break;
				case 2:
					total_size = r1*r2;
					
					break;
				case 3:
					total_size = r1*r2*r3;
					break;
				case 4:
					total_size = r1*r2*r3*r4;
					break;
				case 5:
					total_size = r1*r2*r3*r4*r5;
					break;
				default: 
					printf("Error: wrong dim\n");
					exit(0);
			}
			X_int = (int *)malloc(total_size*sizeof(int));
			data_int = (int *)data;
			for(i=0;i<total_size;i++)
				X_int[i] = data_int[i];
			*data_ = X_int;
			break;
		case SDC_FLOAT:
			switch(dim)
			{
				case 1:
					total_size = r1;
					break;
				case 2:
					total_size = r1*r2;
					
					break;
				case 3:
					total_size = r1*r2*r3;
					break;
				case 4:
					total_size = r1*r2*r3*r4;
					break;
				case 5:
					total_size = r1*r2*r3*r4*r5;
					break;
				default: 
					printf("Error: wrong dim\n");
					exit(0);
			}
			X_float = (float *)malloc(total_size*sizeof(float));
			data_float = (float *)data;
			for(i=0;i<total_size;i++)
				X_float[i] = data_float[i];			
			*data_ = X_float;
			break;
		case SDC_DOUBLE:
			switch(dim)
			{
				case 1:
					total_size = r1;
					break;
				case 2:
					total_size = r1*r2;
					
					break;
				case 3:
					total_size = r1*r2*r3;
					break;
				case 4:
					total_size = r1*r2*r3*r4;
					break;
				case 5:
					total_size = r1*r2*r3*r4*r5;
					break;
				default: 
					printf("Error: wrong dim\n");
					exit(0);
			}
			X_double = (double *)malloc(total_size*sizeof(double));
			data_double = (double *)data;
			for(i=0;i<total_size;i++)
				X_double[i] = data_double[i];			
			*data_ = X_double;
			break;
		default:
			printf("Error: Wrong type...\n");
			exit(0);
	}
}


/**
 * operate memory for particular pointer-based multi-dimensional arrays
 */
void doubleCopy_5d_p(int r5, int r4, int r3, int r2, int r1, double *****target, double *****source)
{
	int i,j,k,z,p;
	for(p=0;p<r5;p++)
		for(i=0;i<r4;i++)
			for(j=0;j<r3;j++)
				for(k=0;k<r2;k++)
					for(z=0;z<r1;z++)
					{
						target[p][i][j][k][z] = source[p][i][j][k][z];
					}
}

/**
 * operate memory for particular pointer-based multi-dimensional arrays
 */
void doubleCopy_4d_p(int r4, int r3, int r2, int r1, double ****target, double ****source)
{
	int i,j,k,z;
	for(i=0;i<r4;i++)
		for(j=0;j<r3;j++)
			for(k=0;k<r2;k++)
				for(z=0;z<r1;z++)
				{
					target[i][j][k][z] = source[i][j][k][z];
				}
}

void doubleCopy_3d_p(int r3, int r2, int r1, double ***target, double ***source)
{
	int i,j,k;
	for(i=0;i<r3;i++)
		for(j=0;j<r2;j++)
			for(k=0;k<r1;k++)
			{
				target[i][j][k] = source[i][j][k];
			}
}

void doubleCopy_2d_p(int r2, int r1, double **target, double **source)
{
	int i,j;
	for(i=0;i<r2;i++)
		for(j=0;j<r1;j++)
		{
			target[i][j] = source[i][j];
		}
}

void doubleCopy_1d_p(int r1, double *target, double *source)
{
	int i;
	for(i=0;i<r1;i++)
		target[i] = source[i];			
}

void allocate_1d_p(int n, double **a)
{
     double *storage;
     storage = (double *) malloc (n* sizeof(double));
     *a = storage;
}

void free_1d_p(double *a)
{
	//double *p;
	if(a!=NULL)
	{
		//p = &a[0];
		//free(p);		
		free(a);
		a=NULL;
	}
}

void allocate_2d_p(int r, int c, double ***a)
{
	double *storage;
	int i;
	storage = (double *) malloc (r*c* sizeof(double));
	*a = (double **) malloc (r*sizeof(double));
	for(i=0;i<r;i++)
		 (*a)[i] = &storage[i*c];
}

void free_2d_p(double **a)
{
	if(a!=NULL)
	{
		free(a);
		a=NULL;
	}
}


void allocate_3d_p(int r3, int r2, int r1, double ****a)
{
	double *storage;
	int i,j;
	storage = (double *) malloc (r3*r2*r1* sizeof(double));
	*a = (double ***) malloc (r3*sizeof(double));
	for(i=0;i<r3;i++)
	{
			(*a)[i] = (double **) malloc (r2*sizeof(double));
			for(j=0;j<r2;j++)
			{
					(*a)[i][j]=&storage[i*r2*r1+j*r1];
			}
	}
}

void free_3d_p(int r3, double ***a)
{
	int i,j;
	double *p;
	if(a==NULL)
		return;
	p = &a[0][0][0];
	free(p);
	for(i=0;i<r3;i++)
	{
		free(a[i]);
	}
	free(a);
	a=NULL;
}

void allocate_4d_p(int r4, int r3, int r2, int r1, double *****a)
{
	double *storage;
	int i,j,k;
	storage = (double *) malloc (r4*r3*r2*r1* sizeof(double));
	*a = (double ****) malloc (r4*sizeof(double));
	for(i=0;i<r4;i++)
	{
		(*a)[i] = (double ***) malloc (r3*sizeof(double));
		for(j=0;j<r3;j++)
		{
			(*a)[i][j]=(double **) malloc (r2*sizeof(double));
			for(k=0;k<r2;k++)
			{
					(*a)[i][j][k] = &storage[i*r3*r2*r1+j*r2*r1+k*r1];
			}
		}
	}
}


void free_4d_p(int r4, int r3, double ****a)
{
	int i,j;
	double *p;
	if(a==NULL)
		return;

	p = &a[0][0][0][0];
	free(p);
	for(i=0;i<r4;i++)
	{
		for(j=0;j<r3;j++)
		{
			free(a[i][j]);
		}
		free(a[i]);
	}	
	free(a);
	a=NULL;
}

void allocate_5d_p(int r5, int r4, int r3, int r2, int r1, double ******a)
{
	double *storage;
	int i,j,k,z;
	if(sdc_manager.sol_ID==SDC_AID&&sdc_manager.samp_distance<1)
		sdc_manager.samp_distance = 1;
	storage = (double *) malloc (r5*r4*r3*r2*r1* sizeof(double));
	*a = (double *****) malloc (r5*sizeof(double));
	for(i=0;i<r5;i++)
	{
		(*a)[i] = (double ****) malloc (r4*sizeof(double));
		for(j=0;j<r4;j++)
		{
			(*a)[i][j]=(double ***) malloc (r3*sizeof(double));
			for(k=0;k<r3;k++)
			{
				(*a)[i][j][k]=(double **) malloc (r2*sizeof(double));
				for(z=0;z<r2;z++)
				{
					(*a)[i][j][k][z] = &storage[i*r4*r3*r2*r1+j*r3*r2*r1+k*r2*r1+z*r1];
				}
			}
		}
	}
}

void free_5d_p(int r5, int r4, int r3, double *****a)
{
	int i,j,k;
	double *p;
	if(a==NULL)
		return;

	p = &a[0][0][0][0][0];
	free(p);
	for(i=0;i<r5;i++)
	{
		for(j=0;j<r4;j++)
		{
			for(k=0;k<r3;k++)
				free(a[i][j][k]);
			free(a[i][j]);
		}
		free(a[i]);
	}
	free(a);
	a=NULL;
}

void align_1d_p_copy(int r1, double **pp, double *storage)
{
	int i;
	//*pp = (double *) malloc (r1* sizeof(double));
	allocate_1d_p(r1,pp);
	for(i = 0;i<r1;i++)
	{
		(*pp)[i] = storage[i];
	}
}

void align_2d_p_copy(int r2, int r1, double ***pp, double *storage)
{
	int i,j;
	allocate_2d_p(r2,r1,pp);
	for(i = 0;i<r2;i++)
		for(j = 0;j<r1;j++)
		{
			(*pp)[i][j] = storage[i*r1+j];
		}
}

void align_3d_p_copy(int r3, int r2, int r1, double ****pp, double *storage)
{
	int i,j,k;
	allocate_3d_p(r3,r2,r1,pp);
	for(i = 0;i<r3;i++)
		for(j = 0;j<r2;j++)
			for(k = 0;k<r1;k++)
			{
				(*pp)[i][j][k] = storage[i*r2*r1+j*r1+k];
			}
}

void align_4d_p_copy(int r4, int r3, int r2, int r1, double *****pp, double *storage)
{
	int i,j,k,z;
	allocate_4d_p(r4,r3,r2,r1,pp);
	for(i = 0;i<r4;i++)
		for(j = 0;j<r3;j++)
			for(k = 0;k<r2;k++)
				for(z = 0;z<r1;z++)
				{
					(*pp)[i][j][k][z] = storage[i*r3*r2*r1+j*r2*r1+k*r1+z];
				}
}

void align_5d_p_copy(int r5, int r4, int r3, int r2, int r1, double ******pp, double *storage)
{
	int i,j,k,z,m;
	allocate_5d_p(r5,r4,r3,r2,r1,pp);
	for(i = 0;i<r5;i++)
		for(j = 0;j<r4;j++)
			for(k = 0;k<r3;k++)
				for(z = 0;z<r2;z++)
					for(m = 0;m<r1;m++)
					{
						(*pp)[i][j][k][z][m] = storage[i*r4*r3*r2*r1+j*r3*r2*r1+k*r2*r1+z*r1+m];					
					}
}

