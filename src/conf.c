/**
 *  @file   conf.c
 *  @author Leonardo A. Bautista Gomez (leobago@gmail.com) and Sheng Di (disheng222@gmail.com)
 *  @date   created by Leonardo in December, 2013, and modified by Sheng in 2015.
 *  @brief  Configuration loading functions for the SDC library.
 *  (C) 2015 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "string.h"
#include "sdc_detector.h"

/*-------------------------------------------------------------------------*/
/**
    @brief      It reads the configuration given in the configuration file.
    @return     integer         1 if successfull.

    This function reads the configuration given in the SDC configuration
    file and sets other required parameters.

 **/
/*-------------------------------------------------------------------------*/
int SDC_ReadConf() {
    // Check access to SDC configuration file and load dictionary
    dictionary *ini;
    char *par;
    if(myRankID==0)
		printf("[SDC] Reading SDC configuration file (%s) ...\n", sdc_cfgFile);
    if (access(sdc_cfgFile, F_OK) != 0)
    {
        printf("[SDC] Configuration file NOT accessible.\n");
        return 1;
    }
    ini = iniparser_load(sdc_cfgFile);
    if (ini == NULL)
    {
        printf("[SDC] Iniparser failed to parse the conf. file.\n");
        return 1;
    }

	// Reading/setting detection parameters
	par = iniparser_getstring(ini, "Detection:sol_name", NULL);
	snprintf(sdc_manager.sol_name, VARNAMELEN, "%s", par);
	
    if(strcmp(sdc_manager.sol_name, "AID")==0)
		sdc_manager.sol_ID = SDC_AID;
	else
	{
		printf("[SDC] Error: wrong solution name (please check config.sdc file)\n");
		exit(0);
	}

	//floor is used by both SDC_AID and SDC_ABF...
	sdc_manager.floor = (double) iniparser_getdouble(ini, "Detection:floor", 0);


	if(sdc_manager.sol_ID==SDC_AID)
	{
		sdc_manager.impact_err_bound_ratio = (double) iniparser_getdouble(ini, "Detection:impact_err_bound_ratio", 0);
		sdc_manager.lambda = (float) iniparser_getdouble(ini, "Detection:lambda", 0);
		sdc_manager.check_bestfit_rate = (int) iniparser_getint(ini, "Detection:check_bestfit_rate", 0);
		sdc_manager.collect_value_range_rate = (int) iniparser_getint(ini, "Detection:collect_value_range_rate", 0);
		sdc_manager.samp_distance = (int) iniparser_getint(ini, "Detection:samp_distance", 0);	
		sdc_manager.fixed_value_range = (double) iniparser_getint(ini, "Detection:fixed_value_range", 0);
		if(myRankID==0)
			printf("[SDC] SDC Initialization: solution: %s , lambda: %f , check_bestfit_rate: %d, sample_distance: %d\n", sdc_manager.sol_name, sdc_manager.lambda, sdc_manager.check_bestfit_rate, sdc_manager.samp_distance);
	}
	else
	{
		sdc_manager.delta_coeff = (float) iniparser_getdouble(ini, "Detection:delta_coeff", 0);
		sdc_manager.errFeedback = (int) iniparser_getint(ini, "Detection:errFeedback", 0);	
		sdc_manager.samp_distance = (int) iniparser_getint(ini, "Detection:samp_distance", 0);	
		printf("[SDC] SDC Initialization: solution: %s , floor: %f , delta_coeff: %f, err feedback: %d\n", sdc_manager.sol_name, sdc_manager.floor, sdc_manager.delta_coeff, sdc_manager.errFeedback);
	}

    // Synchronize after config reading and free dictionary
    MPI_Barrier(SDC_COMM_WORLD);
    iniparser_freedict(ini);
    return 1;
}

/*-------------------------------------------------------------------------*/
/**
    @brief      It reads and tests the configuration given.
    @return     integer         1 if successfull.

    This function reads the configuration file. Then test that the
    configuration parameters are correct (including directories).

 **/
/*-------------------------------------------------------------------------*/
int SDC_LoadConf() {
    int res = SDC_ReadConf();
    if (res == 0)
    {
        printf("[SDC] ERROR: Impossible to read configuration.\n");
        return 0;
    }
    return 1;
}


