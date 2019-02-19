!  @file   sdc_interface.F90
!  @author Sheng Di (disheng222@gmail.com)
!  @date   Aug., 2014
!  @ Mathematics and Computer Science (MCS)
!  @ Argonne National Laboratory, Lemont, USA.
!  @brief  The key Fortran binding file to connect C language and Fortran (Fortran part)

MODULE SDC
	use :: ISO_C_BINDING

	INTERFACE SDC_Protect
		MODULE PROCEDURE SDC_Protect_d1_Fortran_var_INTEGER
		MODULE PROCEDURE SDC_Protect_d2_Fortran_var_INTEGER
		MODULE PROCEDURE SDC_Protect_d3_Fortran_var_INTEGER
		MODULE PROCEDURE SDC_Protect_d4_Fortran_var_INTEGER
		MODULE PROCEDURE SDC_Protect_d5_Fortran_var_INTEGER
		MODULE PROCEDURE SDC_Protect_d1_Fortran_var_REAL_K4
		MODULE PROCEDURE SDC_Protect_d2_Fortran_var_REAL_K4
		MODULE PROCEDURE SDC_Protect_d3_Fortran_var_REAL_K4
		MODULE PROCEDURE SDC_Protect_d4_Fortran_var_REAL_K4
		MODULE PROCEDURE SDC_Protect_d5_Fortran_var_REAL_K4
		MODULE PROCEDURE SDC_Protect_d1_Fortran_var_REAL_K8
		MODULE PROCEDURE SDC_Protect_d2_Fortran_var_REAL_K8
		MODULE PROCEDURE SDC_Protect_d3_Fortran_var_REAL_K8
		MODULE PROCEDURE SDC_Protect_d4_Fortran_var_REAL_K8
		MODULE PROCEDURE SDC_Protect_d5_Fortran_var_REAL_K8
	END INTERFACE SDC_Protect

	INTERFACE SDC_Snapshot
		MODULE PROCEDURE SDC_Snapshot_d1_Fortran_INTEGER
		MODULE PROCEDURE SDC_Snapshot_d2_Fortran_INTEGER
		MODULE PROCEDURE SDC_Snapshot_d3_Fortran_INTEGER
		MODULE PROCEDURE SDC_Snapshot_d4_Fortran_INTEGER
		MODULE PROCEDURE SDC_Snapshot_d5_Fortran_INTEGER
		MODULE PROCEDURE SDC_Snapshot_d1_Fortran_REAL_K4
		MODULE PROCEDURE SDC_Snapshot_d2_Fortran_REAL_K4
		MODULE PROCEDURE SDC_Snapshot_d3_Fortran_REAL_K4
		MODULE PROCEDURE SDC_Snapshot_d4_Fortran_REAL_K4
		MODULE PROCEDURE SDC_Snapshot_d5_Fortran_REAL_K4
		MODULE PROCEDURE SDC_Snapshot_d1_Fortran_REAL_K8
		MODULE PROCEDURE SDC_Snapshot_d2_Fortran_REAL_K8
		MODULE PROCEDURE SDC_Snapshot_d3_Fortran_REAL_K8
		MODULE PROCEDURE SDC_Snapshot_d4_Fortran_REAL_K8
		MODULE PROCEDURE SDC_Snapshot_d5_Fortran_REAL_K8
	END INTERFACE SDC_Snapshot

    CONTAINS

	SUBROUTINE SDC_Init(config_File,ierr)
		CHARACTER(len=32) :: config_File
		INTEGER :: l,ierr
		CALL SDC_Init_c(config_File,len(trim(config_File)),ierr)
	END SUBROUTINE SDC_Init

	SUBROUTINE SDC_Protect_d1_Fortran_var_INTEGER(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(KIND=4), DIMENSION(:) :: VAR
		INTEGER(kind=4) :: R1
		R1 = SIZE(VAR,1)
		CALL SDC_Protect_d1_Fortran(1, VARNAME,R1)
	END SUBROUTINE SDC_Protect_d1_Fortran_var_INTEGER

	SUBROUTINE SDC_Protect_d1_Fortran_var_REAL_K4(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(KIND=4), DIMENSION(:) :: VAR
		INTEGER(kind=4) :: R1
		R1 = SIZE(VAR,1)
		CALL SDC_Protect_d1_Fortran(2, VARNAME,R1)
	END SUBROUTINE SDC_Protect_d1_Fortran_var_REAL_K4

	SUBROUTINE SDC_Protect_d1_Fortran_var_REAL_K8(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(KIND=8), DIMENSION(:) :: VAR
		INTEGER(kind=4) :: R1
		R1 = SIZE(VAR,1)
		CALL SDC_Protect_d1_Fortran(3, VARNAME,R1)
	END SUBROUTINE SDC_Protect_d1_Fortran_var_REAL_K8

	SUBROUTINE SDC_Protect_d1_Fortran(DATA_TYPE, VARNAME, R1)
		implicit none
		INTEGER(kind=4) :: DATA_TYPE !1: INTEGER ; 2: FLOAT ; 3: DOUBLE
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(kind=4) :: R1
		INTEGER(kind=4) :: VARNAME_LEN
		VARNAME_LEN = LEN_TRIM(VARNAME)
		IF(DATA_TYPE==1) THEN
			CALL SDC_Protect_d1_Integer(VARNAME, VARNAME_LEN, R1)
		ELSE IF(DATA_TYPE==2) THEN
			CALL SDC_Protect_d1_Float(VARNAME, VARNAME_LEN, R1)
		ELSE IF(DATA_TYPE==3) THEN
			CALL SDC_Protect_d1_Double(VARNAME, VARNAME_LEN, R1)
		END IF
	END SUBROUTINE SDC_Protect_d1_Fortran

	SUBROUTINE SDC_Protect_d2_Fortran_var_INTEGER(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(KIND=4), DIMENSION(:,:) :: VAR
		INTEGER(kind=4) :: R1, R2
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		CALL SDC_Protect_d2_Fortran(1, VARNAME,R1,R2)
	END SUBROUTINE SDC_Protect_d2_Fortran_var_INTEGER

	SUBROUTINE SDC_Protect_d2_Fortran_var_REAL_K4(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(KIND=4), DIMENSION(:,:) :: VAR
		INTEGER(kind=4) :: R1, R2
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		CALL SDC_Protect_d2_Fortran(2, VARNAME,R1,R2)
	END SUBROUTINE SDC_Protect_d2_Fortran_var_REAL_K4

	SUBROUTINE SDC_Protect_d2_Fortran_var_REAL_K8(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(KIND=8), DIMENSION(:,:) :: VAR
		INTEGER(kind=4) :: R1, R2
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		CALL SDC_Protect_d2_Fortran(3, VARNAME,R1,R2)
	END SUBROUTINE SDC_Protect_d2_Fortran_var_REAL_K8

	SUBROUTINE SDC_Protect_d2_Fortran(DATA_TYPE, VARNAME, R1, R2) 
		implicit none
		INTEGER(kind=4) :: DATA_TYPE !1: INTEGER ; 2: FLOAT ; 3: DOUBLE
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(kind=4) :: R1, R2
		INTEGER(kind=4) :: VARNAME_LEN
		VARNAME_LEN = LEN_TRIM(VARNAME)
		IF(DATA_TYPE==1) THEN
			CALL SDC_Protect_d2_Integer(VARNAME, VARNAME_LEN, R1, R2)
		ELSE IF(DATA_TYPE==2) THEN
			CALL SDC_Protect_d2_Float(VARNAME, VARNAME_LEN, R1, R2)
		ELSE IF(DATA_TYPE==3) THEN
			CALL SDC_Protect_d2_Double(VARNAME, VARNAME_LEN, R1, R2)
		END IF
	END SUBROUTINE SDC_Protect_d2_Fortran

	SUBROUTINE SDC_Protect_d3_Fortran_var_INTEGER(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(KIND=4), DIMENSION(:,:,:) :: VAR
		INTEGER(kind=4) :: R1, R2, R3
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		R3 = SIZE(VAR,3)
		CALL SDC_Protect_d3_Fortran(1, VARNAME,R1,R2,R3)
	END SUBROUTINE SDC_Protect_d3_Fortran_var_INTEGER

	SUBROUTINE SDC_Protect_d3_Fortran_var_REAL_K4(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(KIND=4), DIMENSION(:,:,:) :: VAR
		INTEGER(kind=4) :: R1, R2, R3
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		R3 = SIZE(VAR,3)
		CALL SDC_Protect_d3_Fortran(2, VARNAME,R1,R2,R3)
	END SUBROUTINE SDC_Protect_d3_Fortran_var_REAL_K4
		
	SUBROUTINE SDC_Protect_d3_Fortran_var_REAL_K8(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(KIND=8), DIMENSION(:,:,:) :: VAR
		INTEGER(kind=4) :: R1, R2, R3
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		R3 = SIZE(VAR,3)
		CALL SDC_Protect_d3_Fortran(3, VARNAME,R1,R2,R3)
	END SUBROUTINE SDC_Protect_d3_Fortran_var_REAL_K8

	SUBROUTINE SDC_Protect_d3_Fortran(DATA_TYPE, VARNAME, R1, R2, R3) 
		implicit none
		INTEGER(kind=4) :: DATA_TYPE !1: INTEGER ; 2: FLOAT ; 3: DOUBLE
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(kind=4) :: R1, R2, R3
		INTEGER(kind=4) :: VARNAME_LEN
		VARNAME_LEN = LEN_TRIM(VARNAME)
		IF(DATA_TYPE==1) THEN
			CALL SDC_Protect_d3_Integer(VARNAME, VARNAME_LEN, R1, R2, R3)
		ELSE IF(DATA_TYPE==2) THEN
			CALL SDC_Protect_d3_Float(VARNAME, VARNAME_LEN, R1, R2, R3)
		ELSE IF(DATA_TYPE==3) THEN
			CALL SDC_Protect_d3_Double(VARNAME, VARNAME_LEN, R1, R2, R3)
		END IF
	END SUBROUTINE SDC_Protect_d3_Fortran       

	SUBROUTINE SDC_Protect_d4_Fortran_var_INTEGER(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(KIND=4), DIMENSION(:,:,:,:) :: VAR
		INTEGER(kind=4) :: R1, R2, R3, R4
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		R3 = SIZE(VAR,3)
		R4 = SIZE(VAR,4)
		CALL SDC_Protect_d4_Fortran(1, VARNAME,R1,R2,R3,R4)
	END SUBROUTINE SDC_Protect_d4_Fortran_var_INTEGER

	SUBROUTINE SDC_Protect_d4_Fortran_var_REAL_K4(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(KIND=4), DIMENSION(:,:,:,:) :: VAR
		INTEGER(kind=4) :: R1, R2, R3, R4
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		R3 = SIZE(VAR,3)
		R4 = SIZE(VAR,4)
		CALL SDC_Protect_d4_Fortran(2, VARNAME,R1,R2,R3,R4)
	END SUBROUTINE SDC_Protect_d4_Fortran_var_REAL_K4

	SUBROUTINE SDC_Protect_d4_Fortran_var_REAL_K8(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(KIND=8), DIMENSION(:,:,:,:) :: VAR
		INTEGER(kind=4) :: R1, R2, R3, R4
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		R3 = SIZE(VAR,3)
		R4 = SIZE(VAR,4)
		CALL SDC_Protect_d4_Fortran(3, VARNAME,R1,R2,R3,R4)
	END SUBROUTINE SDC_Protect_d4_Fortran_var_REAL_K8

	SUBROUTINE SDC_Protect_d4_Fortran(DATA_TYPE, VARNAME, R1, R2, R3, R4) 
		implicit none
		INTEGER(kind=4) :: DATA_TYPE !1: INTEGER ; 2: FLOAT ; 3: DOUBLE
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(kind=4) :: R1, R2, R3, R4
		INTEGER(kind=4) :: VARNAME_LEN
		VARNAME_LEN = LEN_TRIM(VARNAME)
		IF(DATA_TYPE==1) THEN
			CALL SDC_Protect_d4_Integer(VARNAME, VARNAME_LEN, R1, R2, R3, R4)
		ELSE IF(DATA_TYPE==2) THEN
			CALL SDC_Protect_d4_Float(VARNAME, VARNAME_LEN, R1, R2, R3, R4)
		ELSE IF(DATA_TYPE==3) THEN
			CALL SDC_Protect_d4_Double(VARNAME, VARNAME_LEN, R1, R2, R3, R4)
		END IF
	END SUBROUTINE SDC_Protect_d4_Fortran

	SUBROUTINE SDC_Protect_d5_Fortran_var_INTEGER(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(KIND=4), DIMENSION(:,:,:,:,:) :: VAR
		INTEGER(kind=4) :: R1, R2, R3, R4, R5
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		R3 = SIZE(VAR,3)
		R4 = SIZE(VAR,4)
		R5 = SIZE(VAR,5)
		CALL SDC_Protect_d5_Fortran(1, VARNAME,R1,R2,R3,R4,R5)
	END SUBROUTINE SDC_Protect_d5_Fortran_var_INTEGER

	SUBROUTINE SDC_Protect_d5_Fortran_var_REAL_K4(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(KIND=4), DIMENSION(:,:,:,:,:) :: VAR
		INTEGER(kind=4) :: R1, R2, R3, R4, R5
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		R3 = SIZE(VAR,3)
		R4 = SIZE(VAR,4)
		R5 = SIZE(VAR,5)
		CALL SDC_Protect_d5_Fortran(2, VARNAME,R1,R2,R3,R4,R5)
	END SUBROUTINE SDC_Protect_d5_Fortran_var_REAL_K4

	SUBROUTINE SDC_Protect_d5_Fortran_var_REAL_K8(VARNAME, VAR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(KIND=8), DIMENSION(:,:,:,:,:) :: VAR
		INTEGER(kind=4) :: R1, R2, R3, R4, R5
		R1 = SIZE(VAR,1)
		R2 = SIZE(VAR,2)
		R3 = SIZE(VAR,3)
		R4 = SIZE(VAR,4)
		R5 = SIZE(VAR,5)
		CALL SDC_Protect_d5_Fortran(3, VARNAME,R1,R2,R3,R4,R5)
	END SUBROUTINE SDC_Protect_d5_Fortran_var_REAL_K8

	SUBROUTINE SDC_Protect_d5_Fortran(DATA_TYPE, VARNAME, R1, R2, R3, R4, R5) 
		implicit none
		INTEGER(kind=4) :: DATA_TYPE !1: INTEGER ; 2: FLOAT ; 3: DOUBLE
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(kind=4) :: R1, R2, R3, R4, R5
		INTEGER(kind=4) :: VARNAME_LEN
		VARNAME_LEN = LEN_TRIM(VARNAME)
		IF(DATA_TYPE==1) THEN
			CALL SDC_Protect_d5_Integer(VARNAME, VARNAME_LEN, R1, R2, R3, R4, R5)
		ELSE IF(DATA_TYPE==2) THEN
			CALL SDC_Protect_d5_Float(VARNAME, VARNAME_LEN, R1, R2, R3, R4, R5)
		ELSE IF(DATA_TYPE==3) THEN
			CALL SDC_Protect_d5_Double(VARNAME, VARNAME_LEN, R1, R2, R3, R4, R5)
		END IF
	END SUBROUTINE SDC_Protect_d5_Fortran

	SUBROUTINE SDC_Snapshot_d1_Fortran_Integer(VARNAME, VAR, IERR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(kind=4), DIMENSION(:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN
		INTEGER(kind=4) :: IERR
		VARNAME_LEN = LEN_TRIM(VARNAME)

		call SDC_Snapshot_d1_1Var_Integer(VARNAME, VARNAME_LEN, VAR, IERR)
	END SUBROUTINE SDC_Snapshot_d1_Fortran_Integer

	SUBROUTINE SDC_Snapshot_d1_Fortran_REAL_K4(VARNAME, VAR, IERR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(kind=4), DIMENSION(:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN
		INTEGER(kind=4) :: IERR
		VARNAME_LEN = LEN_TRIM(VARNAME)

		call SDC_Snapshot_d1_1Var_Float(VARNAME, VARNAME_LEN, VAR, IERR)
	END SUBROUTINE SDC_Snapshot_d1_Fortran_REAL_K4

	SUBROUTINE SDC_Snapshot_d1_Fortran_REAL_K8(VARNAME, VAR, IERR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(kind=8), DIMENSION(:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN
		INTEGER(kind=4) :: IERR
		VARNAME_LEN = LEN_TRIM(VARNAME)

		call SDC_Snapshot_d1_1Var_Double(VARNAME, VARNAME_LEN, VAR, IERR)
	END SUBROUTINE SDC_Snapshot_d1_Fortran_REAL_K8

	SUBROUTINE SDC_Snapshot_d2_Fortran_Integer(VARNAME, VAR, IERR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		INTEGER(kind=4), DIMENSION(:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR) 
		VARNAME_LEN = LEN_TRIM(VARNAME)
		!the memory of reshape() can be released upon exit of this function.
		CALL SDC_Snapshot_d2_1Var_Integer(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)
	END SUBROUTINE SDC_Snapshot_d2_Fortran_Integer

	SUBROUTINE SDC_Snapshot_d2_Fortran_REAL_K4(VARNAME, VAR, IERR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(kind=4), DIMENSION(:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR) 
		VARNAME_LEN = LEN_TRIM(VARNAME)
		!the memory of reshape() can be released upon exit of this function.
		CALL SDC_Snapshot_d2_1Var_Float(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)
	END SUBROUTINE SDC_Snapshot_d2_Fortran_REAL_K4

	SUBROUTINE SDC_Snapshot_d2_Fortran_REAL_K8(VARNAME, VAR, IERR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(kind=8), DIMENSION(:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR) 
		VARNAME_LEN = LEN_TRIM(VARNAME)
		!the memory of reshape() can be released upon exit of this function.
		CALL SDC_Snapshot_d2_1Var_Double(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)
	END SUBROUTINE SDC_Snapshot_d2_Fortran_REAL_K8

	SUBROUTINE SDC_Snapshot_d3_Fortran_Integer(VARNAME, VAR, IERR)
		implicit none
			CHARACTER(LEN=*) :: VARNAME
		INTEGER(kind=4), DIMENSION(:,:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR) 
		VARNAME_LEN = LEN_TRIM(VARNAME)
		!the memory of reshape() can be released upon exit of this function.
		CALL SDC_Snapshot_d3_1Var_Integer(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)
	END SUBROUTINE SDC_Snapshot_d3_Fortran_Integer

	SUBROUTINE SDC_Snapshot_d3_Fortran_REAL_K4(VARNAME, VAR, IERR)
		implicit none
			CHARACTER(LEN=*) :: VARNAME
		REAL(kind=4), DIMENSION(:,:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR) 
		VARNAME_LEN = LEN_TRIM(VARNAME)
		!the memory of reshape() can be released upon exit of this function.
		CALL SDC_Snapshot_d3_1Var_Float(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)
	END SUBROUTINE SDC_Snapshot_d3_Fortran_REAL_K4

	SUBROUTINE SDC_Snapshot_d3_Fortran_REAL_K8(VARNAME, VAR, IERR)
		implicit none
			CHARACTER(LEN=*) :: VARNAME
		REAL(kind=8), DIMENSION(:,:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR) 
		VARNAME_LEN = LEN_TRIM(VARNAME)
		!the memory of reshape() can be released upon exit of this function.
		CALL SDC_Snapshot_d3_1Var_Double(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)
	END SUBROUTINE SDC_Snapshot_d3_Fortran_REAL_K8

	SUBROUTINE SDC_Snapshot_d4_Fortran_Integer(VARNAME, VAR, IERR)
		implicit none
			CHARACTER(LEN=*) :: VARNAME
		INTEGER(kind=4), DIMENSION(:,:,:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR) 
		VARNAME_LEN = LEN_TRIM(VARNAME)
		!the memory of reshape() can be released upon exit of this function.
		CALL SDC_Snapshot_d4_1Var_Integer(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)
	END SUBROUTINE SDC_Snapshot_d4_Fortran_Integer

	SUBROUTINE SDC_Snapshot_d4_Fortran_REAL_K4(VARNAME, VAR, IERR)
		implicit none
			CHARACTER(LEN=*) :: VARNAME
		REAL(kind=4), DIMENSION(:,:,:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR) 
		VARNAME_LEN = LEN_TRIM(VARNAME)
		!the memory of reshape() can be released upon exit of this function.
		CALL SDC_Snapshot_d4_1Var_Float(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)
	END SUBROUTINE SDC_Snapshot_d4_Fortran_REAL_K4

	SUBROUTINE SDC_Snapshot_d4_Fortran_REAL_K8(VARNAME, VAR, IERR)
		implicit none
		CHARACTER(LEN=*) :: VARNAME
		REAL(kind=8), DIMENSION(:,:,:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR) 
		VARNAME_LEN = LEN_TRIM(VARNAME)
		!the memory of reshape() can be released upon exit of this function.
		CALL SDC_Snapshot_d4_1Var_Double(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)
	END SUBROUTINE SDC_Snapshot_d4_Fortran_REAL_K8

	SUBROUTINE SDC_Snapshot_d5_Fortran_Integer(VARNAME, VAR, IERR)
		implicit none
			CHARACTER(LEN=*) :: VARNAME
		INTEGER(kind=4), DIMENSION(:,:,:,:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR)
		VARNAME_LEN = LEN_TRIM(VARNAME)

		CALL SDC_Snapshot_d5_1Var_Integer(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)

	END SUBROUTINE SDC_Snapshot_d5_Fortran_Integer

	SUBROUTINE SDC_Snapshot_d5_Fortran_REAL_K4(VARNAME, VAR, IERR)
		implicit none
			CHARACTER(LEN=*) :: VARNAME
		REAL(kind=4), DIMENSION(:,:,:,:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR)
		VARNAME_LEN = LEN_TRIM(VARNAME)

		CALL SDC_Snapshot_d5_1Var_Float(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)

	END SUBROUTINE SDC_Snapshot_d5_Fortran_REAL_K4

	SUBROUTINE SDC_Snapshot_d5_Fortran_REAL_K8(VARNAME, VAR, IERR)
		implicit none
			CHARACTER(LEN=*) :: VARNAME
		REAL(kind=8), DIMENSION(:,:,:,:,:) :: VAR
		INTEGER(kind=4) :: VARNAME_LEN, TOTAL_SIZE
		INTEGER(kind=4) :: IERR

		TOTAL_SIZE=size(VAR)
		VARNAME_LEN = LEN_TRIM(VARNAME)

		CALL SDC_Snapshot_d5_1Var_Double(VARNAME, VARNAME_LEN, reshape(VAR,(/TOTAL_SIZE/)), IERR)

	END SUBROUTINE SDC_Snapshot_d5_Fortran_REAL_K8

	SUBROUTINE SDC_PrintDetectResult()
		CALL SDC_PrintDetectResult_c()
	END SUBROUTINE SDC_PrintDetectResult

	SUBROUTINE SDC_SetMark(I, RES, IERR)
		INTEGER(KIND=4) :: I, RES, IERR
		CALL SDC_SetMark_c(I, RES, IERR)
	END SUBROUTINE SDC_SetMark

	SUBROUTINE SDC_Finalize()
		CALL SDC_Finalize_c()
	END SUBROUTINE SDC_Finalize

	SUBROUTINE SDC_Increase_Counter()
		CALL SDC_Increase_Counter_c()			
	END SUBROUTINE SDC_Increase_Counter

	!SUBROUTINE RAND_INT_Fortran(Target_, Start_, End_)
	!	INTEGER :: Target_, Start_, End_
	!	CALL Rand_Int(Target_, Start_, End_)
	!END SUBROUTINE RAND_INT_Fortran

	SUBROUTINE Cost_Start()
		implicit none
		call cost_start_c()
	END SUBROUTINE

	SUBROUTINE Cost_End()
		implicit none
		call cost_end_c()
	END SUBROUTINE

	SUBROUTINE Print_Cost_Ratio()
		implicit none
		call print_cost_ratio_c()
	END SUBROUTINE

	SUBROUTINE SDC_Increment_Fpnum()
		implicit none
		call sdc_increment_fpnum_c();
	END SUBROUTINE
END MODULE SDC
