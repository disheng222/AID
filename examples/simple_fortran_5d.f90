program p
        use mpi
	use sdc
        implicit none
        character(len=32) :: arg,argv
        real(kind=8), dimension(:,:,:,:,:), allocatable :: grid
        integer(kind=4) :: gridsize1,gridsize2,gridsize3,gridsize4,gridsize5
        real(kind=8) :: res=0
        integer :: i,steps
        integer(kind=4) :: ierr,ierr2
        gridsize1 = 6
        gridsize2 = 7
        gridsize3 = 8
        gridsize4 = 9
        gridsize5 = 10
        write (6,*) 'start....'
        allocate(grid(gridsize1,gridsize2,gridsize3,gridsize4,gridsize5))
     
        call mpi_init(ierr) 
        call getarg(1, arg)        
        call SDC_Init(arg,ierr)
	!call SDC_Protect_d4_Fortran("grid",gridsize1,gridsize2,gridsize3,gridsize4)
	call SDC_Protect("grid",grid)
        steps = 1000
        
        write(6,*) 'before loop.....'
        do i=0, steps, 1
                write (6,*) 'time step: ',i
                grid=i
                
                call SDC_Snapshot("grid",grid,ierr)
                call SDC_SetMark(i,ierr,ierr2)
                call SDC_Increase_Counter()
        end do
        write(6,*) 'end loop.....'
	call SDC_PrintDetectResult()
        ! Free memory
        deallocate(grid)
        write (6,*) 'done.'
        call MPI_Finalize(ierr)
	call SDC_Finalize()
end program p
