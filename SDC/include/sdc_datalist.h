/**
 *  @file sdc_datalist.h
 *  @author Sheng Di
 *  @date April, 2015
 *  @brief Header file for the data list.
 *  (C) 2015 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#ifndef _SDC_DATALIST_H
#define _SDC_DATALIST_H

#include <stdlib.h>

typedef struct SDC_data
{
    int data_type;
    int dim;
    int r5;
    int r4;
    int r3;
    int r2;
    int r1;
    void* X;
    struct SDC_data *next;
} SDC_data;

#endif   /* ----- #ifndef _DATALIST_H  ----- */
