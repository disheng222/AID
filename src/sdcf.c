/**
 *  @file sdcf.c
 *  @author Sheng Di
 *  @date April, 2015
 *  @brief the key C binding file to connect Fortran and C
 *  (C) 2015 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "sdc_detector.h"

void sdc_init_c_(char *configFile,int *len,int *ierr){
    int i;
    char s2[*len+1];
    for(i=0;i<*len;i++)
	s2[i]=configFile[i];
    s2[*len]='\0';
    *ierr = SDC_Init(s2,MPI_COMM_WORLD);
    sdc_manager.isFortran = 1;
}

/*
void sdc_init_()
{
	SDC_Init();
	sdc_manager.isFortran = 1;	
}*/

void sdc_protect_d1_integer_(char* var_name, int *var_name_length, int *r1)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	//SDC_Protect_d1(s2, data, *r1);
	SDC_Protect_F(s2, SDC_INTEGER, 0, 0, 0, 0, *r1);
}

void sdc_protect_d1_float_(char* var_name, int *var_name_length, int *r1)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	//SDC_Protect_d1(s2, data, *r1);
	SDC_Protect_F(s2, SDC_FLOAT, 0, 0, 0, 0, *r1);
}

void sdc_protect_d1_double_(char* var_name, int *var_name_length, int *r1)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	//SDC_Protect_d1(s2, data, *r1);
	SDC_Protect_F(s2, SDC_DOUBLE, 0, 0, 0, 0, *r1);
}

void sdc_protect_d2_integer_(char* var_name, int *var_name_length, int *r1, int *r2)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	SDC_Protect_F(s2, SDC_INTEGER, 0, 0, 0, *r2, *r1);
}

void sdc_protect_d2_float_(char* var_name, int *var_name_length, int *r1, int *r2)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	SDC_Protect_F(s2, SDC_FLOAT, 0, 0, 0, *r2, *r1);
}

void sdc_protect_d2_double_(char* var_name, int *var_name_length, int *r1, int *r2)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	SDC_Protect_F(s2, SDC_DOUBLE, 0, 0, 0, *r2, *r1);
}

void sdc_protect_d3_integer_(char* var_name, int *var_name_length, int *r1, int *r2, int *r3)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	SDC_Protect_F(s2, SDC_INTEGER, 0, 0, *r3, *r2, *r1);
}

void sdc_protect_d3_float_(char* var_name, int *var_name_length, int *r1, int *r2, int *r3)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	SDC_Protect_F(s2, SDC_FLOAT, 0, 0, *r3, *r2, *r1);
}

void sdc_protect_d3_double_(char* var_name, int *var_name_length, int *r1, int *r2, int *r3)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	SDC_Protect_F(s2, SDC_DOUBLE, 0, 0, *r3, *r2, *r1);
}

void sdc_protect_d4_integer_(char* var_name, int *var_name_length, int *r1, int *r2, int *r3, int *r4)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	SDC_Protect_F(s2, SDC_INTEGER, 0, *r4, *r2, *r2, *r1);
}

void sdc_protect_d4_float_(char* var_name, int *var_name_length, int *r1, int *r2, int *r3, int *r4)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	SDC_Protect_F(s2, SDC_FLOAT, 0, *r4, *r2, *r2, *r1);
}

void sdc_protect_d4_double_(char* var_name, int *var_name_length, int *r1, int *r2, int *r3, int *r4)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	SDC_Protect_F(s2, SDC_DOUBLE, 0, *r4, *r2, *r2, *r1);
}

void sdc_protect_d5_integer_(char* var_name, int *var_name_length, int *r1, int *r2, int *r3, int *r4, int *r5)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	SDC_Protect_F(s2, SDC_INTEGER, *r5, *r4, *r3, *r2, *r1);
}

void sdc_protect_d5_float_(char* var_name, int *var_name_length, int *r1, int *r2, int *r3, int *r4, int *r5)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	SDC_Protect_F(s2, SDC_FLOAT, *r5, *r4, *r3, *r2, *r1);
}

void sdc_protect_d5_double_(char* var_name, int *var_name_length, int *r1, int *r2, int *r3, int *r4, int *r5)
{
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	SDC_Protect_F(s2, SDC_DOUBLE, *r5, *r4, *r3, *r2, *r1);
}

void sdc_snapshot_d5_1var_integer_(char* var_name, int *var_name_length, int* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d5_1var_float_(char* var_name, int *var_name_length, float* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d5_1var_double_(char* var_name, int *var_name_length, double* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d4_1var_integer_(char* var_name, int *var_name_length, int* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d4_1var_float_(char* var_name, int *var_name_length, float* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d4_1var_double_(char* var_name, int *var_name_length, double* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d3_1var_integer_(char* var_name, int *var_name_length, int* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d3_1var_float_(char* var_name, int *var_name_length, float* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d3_1var_double_(char* var_name, int *var_name_length, double* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d2_1var_integer_(char* var_name, int *var_name_length, int* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d2_1var_float_(char* var_name, int *var_name_length, float* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d2_1var_double_(char* var_name, int *var_name_length, double* data, int* err)
{
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);

	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	*err = sdc_snapshot_1var_F(p, data);
}

void sdc_snapshot_d1_1var_integer_(char* var_name, int *var_name_length, int* data, int *err)
{	
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);
	
	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	
	*err = sdc_snapshot_1var_F(p, data); 
}

void sdc_snapshot_d1_1var_float_(char* var_name, int *var_name_length, float* data, int *err)
{	
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);
	
	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	
	*err = sdc_snapshot_1var_F(p, data); 
}

void sdc_snapshot_d1_1var_double_(char* var_name, int *var_name_length, double* data, int *err)
{	
	SDC_dataset *p;
	
	int i;
	char s2[*var_name_length+1];
	for(i=0;i<*var_name_length;i++)
		s2[i]=var_name[i];
	s2[*var_name_length]='\0';
	
	search_dataset(dataset_head, s2, &p);
	
	if(p==NULL)
	{
		printf("ERROR: cannot find the variable names in the registered list\n");
		exit(0);
	}
	
	*err = sdc_snapshot_1var_F(p, data); 
}

void sdc_printdetectresult_c_()
{
	SDC_PrintDetectResult();
}

void sdc_finalize_c_()
{
	SDC_Finalize();
}

void sdc_setmark_c_(int *i, int *res, int *err)
{
	*err = SDC_SetMark(*i,*res);
}

void sdc_increase_counter_c_()
{
	incr_counter();
}

void cost_start_c_()
{
	cost_start();
}

void cost_end_c_()
{
	cost_end();
}

void print_cost_ratio_c_()
{
	print_Cost_Ratio();
}

void sdc_increment_fpnum_c_()
{
	incrementFPNum();
}

