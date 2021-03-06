# AID
Adaptive Impact-driven Silent Data Corruption Detector for HPC applications

INSTALL:

(1) Modify Makefile as follows:

In Makefile, replace [AID_INSTALL_PATH] by AID path, and replace [MPI_INSTALL_PATH] by MPI installation directory.

For example,

AIDPATH         = /home/shdi/aid-0.2

MPIPATH         = /home/shdi/mpich-install

(2) set AID PATH as environment variable (such as in ~/.bashrc):

export SDCHOME=[AIDPATH]/SDC

You need to replace [AIDPATH] by your installation path of AID, such as /home/shdi/aid-0.1

(3) set LD_LIBRARY_PATH :

export LD_LIBRARY_PATH= $SDCHOME/lib:$LD_LIBRARY_PATH

(4) Go to the [AIDPATH], then run the following commands:

make

make install

Note: If your mpi application program is coded in Fortran, you don't have to modify Makefile any more. If your mpi application is coded in C, you need to comment out the following line in the Makefile.
                        $(OBJ)/sdcf.o $(OBJ)/sdc_interface.o $(OBJ)/fort_writefile.o \

Reference: 

Sheng Di, Franck Cappello, "Adaptive-Impact Driven Detection of Silent Data Corruption for HPC Applications, " in IEEE Transactions on Parallel and Distributed Computing (IEEE TPDS), 2016. http://www.mcs.anl.gov/~shdi/download/impact-driven-sdc.pdf

=====================================================================
TEST:

In the directory namely examples, you can find all the example source codes for testing the AID library.

Before testing, you need to modify the Makefile in [AIDPATH]/examples, as follows:

Replace [AID_INSTALL_PATH] by your own AID path, such as

SDCPATH         = /home/shdi/aid-0.1/SDC

Note: Don't miss the "SDC" in the end of the above SDCPATH.

Note: In order to reproduce the results in our TPDS paper, you need to use SDC_Increment_FPNum(). Please see Formula (6) of the TPDS paper for details, or user-guide.

------------------
