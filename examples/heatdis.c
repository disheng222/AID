/**
 *  @file   heatdis.c
 *  @author Leonardo A. Bautista Gomez, Sheng Di
 *  @date   May, 2014
 *  @brief  Heat distribution code to test SDC.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include "sdc_detector.h"
#include "mpi.h"
//#include <papi.h>

#define PRECISION   0.001
#define ITER_TIMES  1000000 //1000
#define HEATSOURCE  100
#define ITER_OUT    100
#define WORKTAG     26
#define QUITTAG     56
#define REDUCE      8
#define SDC_REDUCE  1

void allocate_2d_array (int r, int c, double **storage)
{
   *storage = (double *) malloc (r * c * sizeof(double));
}

void initData(int rowsize, int M, int rank, double *g, int nbProcs)
{
    int i, j;
    for (i = 0; i < rowsize; i++)
    {
        for (j = 0; j < M; j++)
        {
            g[(i*M)+j] = 0;
        }
    }
    if (rank == 0)
    {
        for (j = (M*0.1); j < (M*0.9); j++)
        {
            g[j] = HEATSOURCE;
        }
        //j = M*0.5;
        //g[j]=100;
        //g[3*M+3]=100;
    }
    if (rank == nbProcs - 1)
        for (j = M*(rowsize-1)+M*0.3; j < M*(rowsize-1)+M*0.7; j++)
            g[j] = HEATSOURCE;
    if (rank == nbProcs/2)
        for (i = rowsize/2-2; i<=rowsize/2+2;i++)
            for (j = M/2-2; j <=M/2+2;j++)
                g[(i-1)*M+j] = HEATSOURCE;
}

#ifdef INTERACTIVE
char snapshotDir[100];

/* Print solution to standard output or a file */
void print_solution (int M, int N, char *filename, double **u)
{
   int i, j;
   char sep;
   FILE *outfile;

   if (!filename) {
      sep = '\t';   /* just for easier view */
      outfile = stdout;
   } else {
      sep = '\n';   /* for gnuplot format */
      outfile = fopen(filename,"w");
      if (outfile == NULL) {
         printf("Can't open output file.");
         exit(-1);
      }
   }

   /* Print the solution array */
   for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++)
         fprintf (outfile, "%6.2f%c", u[i][j], sep);
      fprintf(outfile, "\n"); /* Empty line for gnuplot */
   }
   if (outfile != stdout)
      fclose(outfile);
}


/* Allocate two-dimensional array. */
void receiveData(int rowsize, int numprocs, int M, double **original, double *h)
{
    MPI_Status status;
    int count;
    int source_ID, i, j;
    double *p;
    allocate_2d_array(rowsize+2, M, &p);
    for(count = 1; count <= numprocs - 1; count++)
    {
        MPI_Recv(&p[0], (rowsize+2)*M, MPI_DOUBLE, MPI_ANY_SOURCE, QUITTAG, MPI_COMM_WORLD, &status);
        if(status.MPI_TAG == QUITTAG)
        {
            source_ID = status.MPI_SOURCE;
            for(i = 1; i <= rowsize; i++)
            {
                int rownumber = source_ID * rowsize +i -1;
                for(j = 0;j<M;j++)
                {
                    original[rownumber][j] = p[i*M+j];
                }   
            }
        }
        else
            printf("EXCEPT ERROR!\n");
    }
    for(i = 0;i<rowsize;i++)
        for(j = 0;j <= M-1;j++)
            original[i][j] = h[(i+1)*M+j];
}

void reduceData(int numprocs, int currentRank, int M, int rowsize, double **original, double *h, int k)
{
    if(currentRank == 0)
    {
        receiveData(rowsize, numprocs, M, original, h);
        char tmpfilename[100];
        sprintf(tmpfilename, "%s/%05d.dat", snapshotDir, k);
        print_solution(M,M, tmpfilename, original);
        /*char gnuplot[200];
        sprintf(gnuplot, "./plot.sh %d %d %s 2d %d", M, M, snapshotDir, k);
        system(gnuplot);*/
    }
    else
    {
        MPI_Send(&h[0], (rowsize+2)*M, MPI_DOUBLE, 0, QUITTAG, MPI_COMM_WORLD);
    }
}
#endif

double doWork(int numprocs, int rank, int M, int rowsize, double *g, double *h)
{
    int i,j;
    MPI_Request req1[2], req2[2];
    MPI_Status status1[2], status2[2];
    double localerror;
    localerror = 0;
    for(i = 0; i < rowsize; i++)
    {
        for(j = 0; j < M; j++)
        {
            h[(i*M)+j] = g[(i*M)+j];
        }
    }
    if (rank > 0)
    {
        MPI_Isend(g+M, M, MPI_DOUBLE, rank-1, WORKTAG, MPI_COMM_WORLD, &req1[0]);
        MPI_Irecv(h,   M, MPI_DOUBLE, rank-1, WORKTAG, MPI_COMM_WORLD, &req1[1]);
    }
    if (rank < numprocs-1)
    {
        MPI_Isend(g+((rowsize-2)*M), M, MPI_DOUBLE, rank+1, WORKTAG, MPI_COMM_WORLD, &req2[0]);
        MPI_Irecv(h+((rowsize-1)*M), M, MPI_DOUBLE, rank+1, WORKTAG, MPI_COMM_WORLD, &req2[1]);
    }
    if (rank > 0)
    {
        MPI_Waitall(2,req1,status1);
    }
    if (rank < numprocs-1)
    {
        MPI_Waitall(2,req2,status2);
    }
    for(i = 1; i < (rowsize-1); i++)
    {
        for(j = 0; j < M; j++)
        {
            if (g[(i*M+j)]>=HEATSOURCE)
                continue;
            g[(i*M)+j] = 0.25*(h[((i-1)*M)+j]+h[((i+1)*M)+j]+h[(i*M)+j-1]+h[(i*M)+j+1]);
            if(localerror < fabs(g[(i*M)+j] - h[(i*M)+j]))
            {
                localerror = fabs(g[(i*M)+j] - h[(i*M)+j]);
            }
        }
    }
    return localerror;
}


int main(int argc, char *argv[])
{
    //PAPI_dmem_info_t dmem;
    char* cfgfile;
    int rank, nbProcs, rowsize, nbLines, i, M, arg;
    double wtime, *h, *g, memSize, localerror, globalerror = 1;
    int sdc_result;
#ifdef INTERACTIVE
    double **original;
#endif

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nbProcs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    M = atoi(argv[1]);
    rowsize = (M / nbProcs);
    nbLines = rowsize +2;
    
    cfgfile=argv[2];
    
    SDC_Init(cfgfile,MPI_COMM_WORLD); ///////////////detector
    	
    allocate_2d_array(nbLines, M, &h);
    allocate_2d_array(nbLines, M, &g);
    initData(nbLines, M, rank, g, nbProcs);
    printf("M=%d\n", M);
#ifdef INTERACTIVE
    original = (double **) malloc(sizeof(double *) * M);
    for (i=0;i<M;i++) original[i] = (double *) malloc(sizeof(double) * M);
    sprintf(snapshotDir, "%s-result", argv[0]);
    //generate result dir if it doesn't exist.
    if(rank == 0 && access(snapshotDir,0)!=0)
	if(mkdir(snapshotDir, 0755)==-1)
	{
	    perror("mkdir error!!!");
            exit(1);
	}
#endif
    memSize = M * nbLines * 2 * sizeof(double) / (1024 * 1024);
    if (rank == 0) printf("Local data size is %d x %d = %f MB (%d).\n", M, nbLines, memSize, arg);
    if (rank == 0) printf("Target precision : %f \n", PRECISION);

    //"h" is variable name, h is variable, M*nbLines is the size of the variable
    SDC_Protect("h", h, SDC_DOUBLE, 0, 0, 0, 0, M*nbLines);  ///////////////detector

    wtime = MPI_Wtime();


    for(i = 0; i <= ITER_TIMES; i++)
    {

        if(rank==0&&i%1000==0) printf("Step: %d, error = %f\n", i, globalerror);
        localerror = doWork(nbProcs, rank, M, nbLines, g, h);
        sdc_result=SDC_Snapshot(); /////////////detector
	SDC_SetMark(i,sdc_result); /////////////detector
	if(sdc_result!=0)
		SDC_Increment_FPNum();
/*	if(i%1000==0)
	{
               PAPI_get_dmem_info(&dmem);
               printf("===================(%d,%d)======\n",rank,i);
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

        if ((i%REDUCE) == 0) MPI_Allreduce(&localerror, &globalerror, 1, MPI_DOUBLE, MPI_MAX, MPI_COMM_WORLD);
        if(globalerror < PRECISION) break;
#ifdef INTERACTIVE
        if(i%SDC_REDUCE == 0)
		reduceData(nbProcs, rank, M, rowsize, original, h, i);
#endif
    }
    if (rank == 0) printf("Execution finished in %lf seconds.\n", MPI_Wtime() - wtime);

    SDC_PrintDetectResult(); ////////////////detector
    
    free(h);
    free(g);
    
    MPI_Finalize();
    SDC_Finalize();         /////////////////detector
    
    printf("done\n");
    return 0;
}


