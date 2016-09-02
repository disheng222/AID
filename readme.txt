###############################################
# COPYRIGHT: See COPYRIGHT.txt                #
# 2015 by MCS, Argonne National Laboratory.   #
###############################################
=====================================================================
This is a document with a brief guide. The complete user guide is doc/aid-0.2-user-guide.pdf.
=====================================================================
INSTALL:
1. Modify Makefile as follows:
In Makefile, replace [AID_INSTALL_PATH] by AID path, and replace [MPI_INSTALL_PATH] by MPI installation directory.
For example, 
AIDPATH         = /home/shdi/aid-0.1
MPIPATH         = /home/shdi/mpich-install

2. set AID PATH as environment variable (such as in ~/.bashrc): 
export SDCHOME=[AIDPATH]/SDC
#You need to replace [AIDPATH] by your installation path of AID, such as /home/shdi/aid-0.1

3. set LD_LIBRARY_PATH :
export LD_LIBRARY_PATH= $SDCHOME/lib:$LD_LIBRARY_PATH
 
4. Go to the [AIDPATH], then run the following commands:
make
make install

Note: If your mpi application program is coded in Fortran, you don't have to modify Makefile any more. If your mpi application is coded in C, you need to comment out the following line in the Makefile.
			$(OBJ)/sdcf.o $(OBJ)/sdc_interface.o $(OBJ)/fort_writefile.o \


=====================================================================
TEST:
In the directory namely examples, you can find all the example source codes for testing the AID library.
Before testing, you need to modify the Makefile in [AIDPATH]/examples, as follows:
Replace [AID_INSTALL_PATH] by your own AID path, such as 
SDCPATH         = /home/shdi/aid-0.1/SDC

Note: Don't miss the "SDC" in the end of the above SDCPATH.

------------------
HeatDistribution:  
Get in the directory [AIDPATH]/examples, and run "make hd"

[source code: heatdis.c]

simple_fortran_1d:
Get in the [AIDPATH]/examples, and run "make simple_fortran_1d"

[source code: simple_fortran_1d.f90]

=====================================================================
CONFIGURATION

The configuration file is 'config.sdc", which can be found in the [AIDPATH]/examples
