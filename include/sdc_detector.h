/**
 *  @file sdc_detector.h
 *  @author Sheng Di
 *  @date April, 2015
 *  @brief Header file for the whole detector.
 *  (C) 2015 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#ifndef _SDC_DETECTOR_H
#define _SDC_DETECTOR_H

#include <stdio.h>
#include <sys/time.h>      /* For gettimeofday(), in microseconds */
#include <time.h>          /* For time(), in seconds */
#include "sdc_datalist.h"
#include "mpi.h"
#include "iniparser.h"

#define StartStepNum 5
#define DetectResultSize 2400
#define SDC_BUFS 10*DetectResultSize
#define VARNAMELEN 256

#define SDC_AID 101 //best solution
#define SDC_LCF 102 //linear curve fitting
#define SDC_QCF 103 //quadratic curve fitting

#define SDC_INTEGER 1000
#define SDC_FLOAT 1001
#define SDC_DOUBLE 1002

/** SDC Meta-information manager **/
typedef struct SDC_manager {
	char sol_name[VARNAMELEN];
	int sol_ID;
	//for AID
	double impact_err_bound_ratio;
	float lambda; //the coefficient to determine the outstanding solution set. It is set to 0.2 usually.
	int check_bestfit_rate; //the rate of checking bestfit order=20
	int collect_value_range_rate;
	double fixed_value_range;
	
	//for non-adaptive detector
	double floor; //such as 10^{-6}
	float delta_coeff;
	int errFeedback; //"0" means "no" ; "1" means 1-degree error feedback ; "2" means 2-degree error feedback
	//samp_distance is used by both AID and non-AID
	int samp_distance; // for non-AID: >=2 means using sampling method; while (<=1) means don't use sampling method
	
	//for marking the valuerage operation
	int valuerange_counter;
	
	//this is fortran version? 
	int isFortran; //1 means fortran; 0 means C
} SDC_manager;

typedef struct SDC_dataset {
	char var_name[VARNAMELEN];
	void *var;
	
	int data_type; //SDC_INTEGER or SDC_FLOAT or SDC_DOUBLE
	
	int dim;
	int r5;
	int r4;
	int r3;
	int r2;
	int r1;
	int FPNum; //# of false positives in the current round/period until next bestfit-order computation
	
	SDC_data *head; //DATA
	
	SDC_data *sampHead; //sampHead->X length is r4*r3*r2*r1/sdc_manager.samp_distance
	
	//bestfit_order, steps_required and value_range are set at runtime
	int bestfit_order; 
	//int steps_required; //steps required to know
	double value_range;
	
	double max_err_order0; //only used by AID for evaluation
	double max_err_order1; //only used by AID for evaluation
	double max_err_order2; //only used by AID for evaluation
	
	double max_err;
	
	struct SDC_dataset *next;	
} SDC_dataset;

SDC_manager sdc_manager;

MPI_Comm SDC_COMM_WORLD;
int myRankID;
int nbProc;
char* sdc_cfgFile;

SDC_dataset *dataset_head;

int detectResult[DetectResultSize];

int counter;

struct timeval startTime; 
struct timeval endTime;  /* Start and end times */
struct timeval costStart; //only used for recording the cost
double totalCost;


int SDC_Init_nonMPI(); //only for dubugging with single process
int SDC_Init_serial(char *configFile);
int SDC_Init(char *configFile, MPI_Comm globalComm);
void SDC_Protect(char* var_name, void* data, int data_type, int r5, int r4, int r3, int r2, int r1);
int SDC_Snapshot();
int SDC_SetMark(int i, int res);
void SDC_Finalize();
void SDC_PrintDetectResult();
void cost_start();
void cost_end();
void print_Cost_Ratio();

#endif /* ----- #ifndef _SDC_DETECTOR_H  ----- */
