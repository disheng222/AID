/**
 *  @file sdc_datalist.c
 *  @author Sheng Di
 *  @date April, 2015
 *  @brief maintain the key data structures regarding the data.
 *  (C) 2015 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "sdc_datalist.h"
#include "sdc_detector.h"

/**
    @brief      Memory allocation
    @param		data             
    @param      data_type
    @param      dim dimension
    @param      r5	dimension 5
    @param      r4	dimension 4
    @param      r3	dimension 3
    @param      r2	dimension 2
    @param      r1	dimension 1        
    @return    

    This function allocate memory for an array, whose dimension is dim

 **/
void malloc_data(SDC_data** data, int data_type, int dim, int r5, int r4, int r3, int r2, int r1)
{
	*data = (SDC_data *)malloc(sizeof(SDC_data));
	(*data)->data_type = data_type;
	(*data)->dim = dim;
	(*data)->r5 = r5;
	(*data)->r4 = r4;
	(*data)->r3 = r3;
	(*data)->r2 = r2;
	(*data)->r1 = r1;

	(*data)->next = NULL;
}

void free_data(SDC_data *data)
{
	int *X_int;
	float *X_float;
	double *X_double;
	if(data->X!=NULL)
		free(data->X);
	free(data);
	data = NULL;
}

void free_datalist(SDC_data *head)
{
	SDC_data *p, *q;
	if(head==NULL)
		return;
	p = head->next;
	while(p!=NULL)
	{
		q = p;
		p=p->next;
		free_data(q);
	}
	free(head);
}

/**
 * the operations of the list for data
 * the format of the list: [head] [data1] [data2] [data3] .....
 * head is an empty node.
 */
void create_datalist(SDC_data **head)
{
	*head = (SDC_data *) malloc(sizeof(SDC_data));
	(*head)->r1=0;
	(*head)->next = NULL;
} 

void create_datalist_size(SDC_data **head, int data_type, int size, int dim, int r5, int r4, int r3, int r2, int r1)
{
	int i;
	SDC_data *p;
	(*head) = (SDC_data *) malloc(sizeof(SDC_data));
	(*head)->data_type = data_type;
	(*head)->dim = dim;
	(*head)->r1 = size;
	p = *head;
	for(i=0;i<size;i++)
	{
			p->next = (SDC_data *) malloc(sizeof(SDC_data));
			p->next->dim = dim;
			p->next->r5 = r5;
			p->next->r4 = r4;
			p->next->r3 = r3;
			p->next->r2 = r2;
			p->next->r1 = r1;
			p->next->X = NULL;
			p=p->next;
	}
	p->next = NULL;
}

/**
 * delete the last data
 */
void delete_data(SDC_data *head)
{
	SDC_data *p, *q;
	p = head;
	while(p->next->next!=NULL)
		p = p->next;
	q = p->next;
	p->next = NULL;
	free_data(q);
	head->r1--;
}

void clear_datalist(SDC_data *head)
{
	SDC_data *p, *q;
	p = head;
	q = p->next;
	while(q!=NULL)
	{
		p->next=q->next;
		free_data(q);
		q = p->next;
	}
}

/**
 * insert one data to the head
 */
void insert_data(SDC_data *head, void* data, int data_type, int r5, int r4, int r3, int r2, int r1)
{
	int dim = head->dim;				
	SDC_data *newData;

	newData = (SDC_data *)malloc(sizeof(SDC_data));
	newData->data_type = data_type;
	newData->dim = dim;
	newData->r5 = r5;
	newData->r4 = r4;
	newData->r3 = r3;
	newData->r2 = r2;
	newData->r1 = r1;
	newData->next = NULL;	
	
	
	copy_p(data, &(newData->X), data_type, dim, r5, r4, r3, r2, r1);

	newData->next = head->next;
	head->next = newData;
	head->r1++;
}

/**
 * This may be the best way to determine the bestfit prediction method to use
 * */
int compute_curStepLength(SDC_data *head)
{
	int length = 0;
	SDC_data *p;
	p = head;
	while(p->next!=NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}
