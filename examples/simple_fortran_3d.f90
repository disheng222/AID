program p
        use mpi
	use sdc
        implicit none
        character(len=32) :: arg,argv
        real(kind=4), dimension(:,:,:), allocatable :: grid
        integer(kind=4) :: gridsize1,gridsize2,gridsize3
        real(kind=8) :: res=0
        integer :: i,steps
        !integer:: SDC_COMM_WORLD
        integer(kind=4) :: ierr,ierr2
        gridsize1 = 10 !6
        gridsize2 = 10 !7
        gridsize3 = 10 !9
        write (6,*) 'start....'
        allocate(grid(gridsize1,gridsize2,gridsize3))
     
        call mpi_init(ierr) 
        call getarg(1, arg)        
        call SDC_Init(arg,ierr)
        !call SDC_Init_d4_Fortran()
	call SDC_Protect("grid",grid)
        steps = 1000
        
        write(6,*) 'before loop.....'
        do i=0, steps, 1
                write (6,*) 'time step: ',i
                grid=i
                
                call Cost_Start()
                call SDC_Snapshot("grid",grid,ierr)
                call SDC_SetMark(i,ierr,ierr2)
                call SDC_Increase_Counter()
                call Cost_End()
        end do
        write(6,*) 'end loop.....'
	call SDC_PrintDetectResult()
        ! Free memory
        deallocate(grid)
        write (6,*) 'done.'
	call SDC_Finalize()
        call MPI_Finalize(ierr)
        call print_Cost_Ratio()
end program p
