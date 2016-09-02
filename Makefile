##=======================================================================
###############################################
# COPYRIGHT: See COPYRIGHT.txt                #
# 2015 by MCS, Argonne National Laboratory.   #
###############################################
##=======================================================================

##=======================================================================
##   PLEASE SET THESE VARIABLES BEFORE COMPILING
##=======================================================================

AIDPATH         = [AID_INSTALL_PATH]
#AIDPATH         = /home/fti/AID/aid-0.2
#example: AIDPATH = /home/shdi/aid-0.1
MPIPATH		= [MPI_INSTALL_PATH]
#MPIPATH	= /home/fti/mpi_install
#example: MPIPATH = /home/shdi/mpi_install

##=======================================================================
##   DIRECTORY TREE
##=======================================================================

LIB 		= lib
OBJ		= obj
SRC		= src
DOC		= doc
INC		= include

##=======================================================================
##   COMPILERS
##=======================================================================

CC 		= gcc
MPICC 		= mpicc

##=======================================================================
##   FLAGS
##=======================================================================

SDCFLAGS	= -fPIC -g -Iinclude/ -c
MPIFLAGS	= -I$(MPIPATH)

##=======================================================================
##   TARGETS
##=======================================================================

## NOTE:
## If you are about to run Fortran with AID, you need to make sure the last line of OBJS is included.
## If you are going to run C program with AID, the last line of OBJS (ie. $(OBJ)/sdcf.o $(OBJ)/sdc_interface.o $(OBJ)/fort_writefile.o \) must be removed (or commented out).

OBJS		= $(OBJ)/dictionary.o $(OBJ)/iniparser.o \
		  $(OBJ)/conf.o $(OBJ)/tools.o\
		  $(OBJ)/sdc_memalloc.o $(OBJ)/sdc_datalist.o $(OBJ)/sdc_datasetlist.o $(OBJ)/sdc_solution.o $(OBJ)/sdc_detector.o \
		  #$(OBJ)/sdcf.o $(OBJ)/sdc_interface.o $(OBJ)/fort_writefile.o \

SHARED		= libsdc.so
STATIC		= libsdc.a

all: 		$(SHARED) $(STATIC)

doc:
		doxygen $(DOC)/Doxyfile

$(OBJ)/%.o:	$(SRC)/%.c
		$(MPICC) $(SDCFLAGS) $< -o $@
		#$(CC) $(SDCFLAGS) $< -o $@
		
$(OBJ)/fort_writefile.o:
		mpif90 -c $(SRC)/fort_writefile.F90 $(SDCFLAGS)
		mv fort_writefile.o $(OBJ)
		mv writefile.mod $(INC)

$(OBJ)/sdc_interface.o:
		mpif90 -c $(SRC)/sdc_interface.F90 $(SDCFLAGS)
		mv sdc_interface.o $(OBJ)
		mv sdc.mod $(INC)
	
$(SHARED):	$(OBJS)
		$(CC) $(MPIFLAGS) -shared -o $(LIB)/$(SHARED) $(OBJS) -lc

$(STATIC):	$(OBJS)
		$(AR) -cvq $(LIB)/$(STATIC) $(OBJS)
install:
		if [ ! -d "$(AIDPATH)/SDC" ]; then mkdir $(AIDPATH)/SDC; fi
		if [ ! -d "$(AIDPATH)/SDC/$(LIB)" ]; then mkdir $(AIDPATH)/SDC/$(LIB); fi
		if [ ! -d "$(AIDPATH)/SDC/$(INC)" ]; then mkdir $(AIDPATH)/SDC/$(INC); fi
		rm -f $(AIDPATH)/SDC/$(LIB)/* $(AIDPATH)/SDC/$(INC)/*
		cp $(INC)/* $(AIDPATH)/SDC/$(INC)/
		cp $(LIB)/* $(AIDPATH)/SDC/$(LIB)/

uninstall:
		rm -f $(AIDPATH)/SDC/$(LIB)/* $(AIDPATH)/SDC/$(INC)/*
		if [ -d "$(AIDPATH)/SDC/$(LIB)" ]; then rmdir $(AIDPATH)/SDC/$(LIB); fi
		if [ -d "$(AIDPATH)/SDC/$(INC)" ]; then rmdir $(AIDPATH)/SDC/$(INC); fi
		if [ -d "$(AIDPATH)/SDC" ]; then rmdir $(AIDPATH)/SDC; fi

clean:
		rm -f $(OBJ)/* $(LIB)/*

.PHONY:		$(SHARED) $(STATIC) doc install uninstall clean


