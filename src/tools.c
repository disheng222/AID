/**
 *  BSD license
 *  @file sdc_datasetlist.c
 *  @author Sheng Di
 *  @date April, 2015
 *  @brief maintain the key data structures regarding the data set.
 *  (C) 2015 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */
 
#include "sdc_detector.h"
#include <dirent.h>
#include <sys/types.h>

void SDC_Print(char *msg) {
	fprintf(stdout, "[SDC rank:%06d] : %s \n", myRankID, msg);
    fflush(stdout);
}

