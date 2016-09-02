#============================================================
[Detection]
#solution name : Adaptive Impact-driven Detector (AID)
sol_name = AID

#sample_distance is used by both AID nad non-AID for different purposes.
#For AID: samp_distance is used for determining the number of samples used to search bestfit orders
#For non-AID: samp_distance is valid only when sampling >= 1,
samp_distance = 3

#-------------------------------------------------------------
##Version Type A: adaptive impact-driven detector, only valid when sol_name=AID
#impact_err_bound_ratio is set to 0.00078125 for FLASH, and 0.05 for heatdis.c
impact_err_bound_ratio = 0.001

#lambda, the coefficient to determine the outstanding solution set
lambda = 0.2

#check_bestfit_rate, how often to search the bestfit order, e.g., do it every 20 iterations?
check_bestfit_rate = 20

#if the global value range is fixed, users can set its value here
#If there are many variables to protect, fixed_value_range should be set to the minimum value.
#fixed_value_range = -1 means to use the dynamic value range, then fixed_value_range will be ignored.
#fixed_value_range != -1 can avoid the communication cost of MPI_Allreduce(max,min) 
fixed_value_range = 20

#frequency: # of steps: how often to compute the global value range
collect_value_range_rate = 10

#--------------------------------------------------------------
## Version Type B: non-adaptive, only valid when sol_name!=AID
#floor: the upper bound when the threshold is going to be set to 0 (i.e., to avoid the threshold=0)
#as for AID: for example, when the interval of global_value_range =0, then the detection range will be [X-0,X+0]. the floor will be used to avoid this situation.
floor = 0.01

#the emplifier coefficient to be multipled with last_error, only valid when sol_name!=AID
delta_coeff = 10

#feed back control: 0 means "no feedback", 1 means "1-degree error feedback", or 2 means "2-degree....", only valid when sol_name!=AID
errFeedback = 0

#==============================================================

