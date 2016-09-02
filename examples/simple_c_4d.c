/**
 **  @file   simple_c_4d.c
 **  @author Sheng Di
 **  @date   April, 2015
 **  @brief  Simple test for C version.
 **/

#include <stdio.h> 
#include <stdlib.h>
//#include <papi.h>
#include "sdc_detector.h"

//void allocate_1d_p(int n, double **a)
//{
//     *a = (double *) malloc (n* sizeof(double));
//}

int main (void) {

	//PAPI_dmem_info_t dmem;
	int i,j1,j2,j3,j4;
	//int size1=10;
	//int size2=10;
	//int size3=10;
	//int size4=10;
	double *data;
	//double data[size1][size2][size3][size4];
	int result;
	//allocate_4d_p(10,10,10,10, &data);
	int size=50000;
	allocate_1d_p(size,&data);
	printf("start....\n");
	
	SDC_Init_nonMPI();	
	//SDC_Protect("data", data, SDC_DOUBLE, 0, size1,size2,size3,size4);
	SDC_Protect("data", data, SDC_DOUBLE, 0, 0,0,0,size);
        printf("------------1\n");	
	for(i=0;i<1000;i++)
	{
		if(i%10000==0)
			printf("time step: %d\n", i);
	//	for(j4=0;j4<size1;j4++)
	//		for(j3=0;j3<size2;j3++)
	//			for(j2=0;j2<size3;j2++)
	//				for(j1=0;j1<size4;j1++)
	//					data[j4][j3][j2][j1] = i;
		for(j1=0;j1<size;j1++)
			data[j1]=i;
		result=SDC_Snapshot();
		SDC_SetMark(i,result);
/*		if(i%10000==0)
		{
			PAPI_get_dmem_info(&dmem);
			printf("===================i=%d===================\n",i);
			printf("Mem Size:\t\t%lld\n",dmem.size);
			printf("Mem Resident:\t\t%lld\n",dmem.resident);
			printf("Mem High Water Mark:\t%lld\n",dmem.high_water_mark);
			printf("Mem Shared:\t\t%lld\n",dmem.shared);
			printf("Mem Text:\t\t%lld\n",dmem.text);
			printf("Mem Library:\t\t%lld\n",dmem.library);
			printf("Mem Heap:\t\t%lld\n",dmem.heap);
			printf("Mem Locked:\t\t%lld\n",dmem.locked);
			printf("Mem Stack:\t\t%lld\n",dmem.stack);
			printf("Mem Pagesize:\t\t%lld\n",dmem.pagesize);
			printf("=========================================\n");
		}
*/
	}
	
	//free_4d_p(10,10,data);
	free(data);
	SDC_Finalize();
	SDC_PrintDetectResult();
	printf("done.");		
	return 0;
}
