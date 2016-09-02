/**
 **  @file   simple_c_4d.c
 **  @author Sheng Di and Omer Subasi
 **  @date   November, 2015
 **  @brief  Simple test for C version.
 **/

#include <stdio.h> 
#include <stdlib.h>
#include "sdc_detector.h"
#include "mpi.h"

int main (int argc, char *argv[]) {

	char* cfgfile;
	int i,j,nbProcs,rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nbProcs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	double *data;
	int result;
	int size=50000;
	allocate_1d_p(size,&data);
	printf("start....\n");
	
    cfgfile=argv[1];

    SDC_Init(cfgfile,MPI_COMM_WORLD); ///////////////detector

	SDC_Protect("data", data, SDC_DOUBLE, 0, 0,0,0,size);

	for(i=0;i<10;i++)
	{
		printf("time step: %d\n", i);
		for(j=0;j<size;j++)
			data[j]=i;
		result=SDC_Snapshot();
		SDC_SetMark(i,result);
	}
	SDC_PrintDetectResult();
	free(data);
    MPI_Finalize();
    SDC_Finalize();         /////////////////detector

	printf("done.");		
	return 0;
}
