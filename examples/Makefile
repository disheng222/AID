## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
##   Makefile to test SDC library with the heat distribution program.

##   PLEASE SET THIS VARIABLE BEFORE COMPILING
SDCPATH		= /home/fti/AID/aid-0.2/SDC
#example: SDCPATH = /home/shdi/aid-0.1/SDC

##   COMPILERS
MPICC 		= mpicc
MPIRUN 		= mpirun

##   FLAGS
# Compiling using shared library
#SDCFLAG 	= -I$(SDCPATH)/include -L$(SDCPATH)/lib -lsdc -lm
# Compiling using static library
SDCFLAG 	= -I$(SDCPATH)/include $(SDCPATH)/lib/libsdc.a

##   TARGETS
all: 		hd simple_c_4d simple_fortran_5d simple_fortran_4d simple_fortran_3d simple_fortran_2d simple_fortran_1d

hd:		heatdis.c
		$(MPICC) -o hd heatdis.c $(SDCFLAG) #-DINTERACTIVE

simple_c_4d:	simple_c_4d.c
		$(MPICC) -g -o simple_c_4d simple_c_4d.c $(SDCFLAG)

sample:		sample.c
		$(MPICC) -g -o sample sample.c $(SDCFLAG)

hdt:
		$(MPIRUN) -np 4 ./hd 200 config.sdc

simple_fortran_5d:	simple_fortran_5d.f90
		mpif90 -g -o simple_fortran_5d simple_fortran_5d.f90 $(SDCFLAG)

simple_fortran_4d:	simple_fortran_4d.f90
		mpif90 -g -o simple_fortran_4d simple_fortran_4d.f90 $(SDCFLAG)

simple_fortran_3d:	simple_fortran_3d.f90
		mpif90 -g -o simple_fortran_3d simple_fortran_3d.f90 $(SDCFLAG)

simple_fortran_2d:	simple_fortran_2d.f90
		mpif90 -g -o simple_fortran_2d simple_fortran_2d.f90 $(SDCFLAG)

simple_fortran_1d:	simple_fortran_1d.f90
		mpif90 -g -o simple_fortran_1d simple_fortran_1d.f90 $(SDCFLAG)

hdv:
		./plot.sh

test_fortran_5d:
		$(MPIRUN) -np 8 ./simple_fortran_5d config.sdc

test_fortran_4d:
		$(MPIRUN) -np 8 ./simple_fortran_4d config.sdc

test_fortran_3d:
		$(MPIRUN) -np 8 ./simple_fortran_3d config.sdc

test_fortran_2d:
		$(MPIRUN) -np 8 ./simple_fortran_2d config.sdc

test_fortran_1d:
		$(MPIRUN) -np 8 ./simple_fortran_1d config.sdc

test_hd:
		$(MPIRUN) -np 8 ./hd 

clean:
		rm -f hd results/*;rm -f simple_fortran_5d;rm -f simple_fortran_4d;rm -f simple_fortran_3d;rm -rf simple_fortran_2d;rm -f simple_fortran_1d

.PHONY:		hd hdt hdv clean

