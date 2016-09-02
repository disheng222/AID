MODULE WRITEFILE
implicit none
INTEGER :: sdcFileID = 2001

INTERFACE open_File
        MODULE PROCEDURE open_File_name
        MODULE PROCEDURE open_File_id_name
END INTERFACE open_File

INTERFACE close_File
        MODULE PROCEDURE close_File_nopar
        MODULE PROCEDURE close_File_id
END INTERFACE close_File

INTERFACE write_File
        MODULE PROCEDURE write_File_INTEGER
        MODULE PROCEDURE write_File_INTEGER_D1
        MODULE PROCEDURE write_File_INTEGER_D2
        MODULE PROCEDURE write_File_INTEGER_D3
        MODULE PROCEDURE write_File_INTEGER_D4
        MODULE PROCEDURE write_File_INTEGER_D5
        MODULE PROCEDURE write_File_INTEGER_D6
        MODULE PROCEDURE write_File_INTEGER_D1_withSize4
        MODULE PROCEDURE write_File_INTEGER_D2_withSize4
        MODULE PROCEDURE write_File_INTEGER_D3_withSize4
        MODULE PROCEDURE write_File_INTEGER_D4_withSize4
        MODULE PROCEDURE write_File_INTEGER_D5_withSize4
        MODULE PROCEDURE write_File_INTEGER_D6_withSize4
        MODULE PROCEDURE write_File_INTEGER_D1_withSize8
        MODULE PROCEDURE write_File_INTEGER_D2_withSize8
        MODULE PROCEDURE write_File_INTEGER_D3_withSize8
        MODULE PROCEDURE write_File_INTEGER_D4_withSize8
        MODULE PROCEDURE write_File_INTEGER_D5_withSize8
        MODULE PROCEDURE write_File_INTEGER_D6_withSize8
        MODULE PROCEDURE write_File_REAL_K4
        MODULE PROCEDURE write_File_REAL_K4_D1
        MODULE PROCEDURE write_File_REAL_K4_D2
        MODULE PROCEDURE write_File_REAL_K4_D3
        MODULE PROCEDURE write_File_REAL_K4_D4
        MODULE PROCEDURE write_File_REAL_K4_D5
        MODULE PROCEDURE write_File_REAL_K4_D6
        MODULE PROCEDURE write_File_REAL_K4_D1_withSize4
        MODULE PROCEDURE write_File_REAL_K4_D2_withSize4
        MODULE PROCEDURE write_File_REAL_K4_D3_withSize4
        MODULE PROCEDURE write_File_REAL_K4_D4_withSize4
        MODULE PROCEDURE write_File_REAL_K4_D5_withSize4
        MODULE PROCEDURE write_File_REAL_K4_D6_withSize4
        MODULE PROCEDURE write_File_REAL_K4_D1_withSize8
        MODULE PROCEDURE write_File_REAL_K4_D2_withSize8
        MODULE PROCEDURE write_File_REAL_K4_D3_withSize8
        MODULE PROCEDURE write_File_REAL_K4_D4_withSize8
        MODULE PROCEDURE write_File_REAL_K4_D5_withSize8
        MODULE PROCEDURE write_File_REAL_K4_D6_withSize8
        MODULE PROCEDURE write_File_REAL_K8
        MODULE PROCEDURE write_File_REAL_K8_D1
        MODULE PROCEDURE write_File_REAL_K8_D2
        MODULE PROCEDURE write_File_REAL_K8_D3
        MODULE PROCEDURE write_File_REAL_K8_D4
        MODULE PROCEDURE write_File_REAL_K8_D5
        MODULE PROCEDURE write_File_REAL_K8_D6
        MODULE PROCEDURE write_File_REAL_K8_D1_withSize4
        MODULE PROCEDURE write_File_REAL_K8_D2_withSize4
        MODULE PROCEDURE write_File_REAL_K8_D3_withSize4
        MODULE PROCEDURE write_File_REAL_K8_D4_withSize4
        MODULE PROCEDURE write_File_REAL_K8_D5_withSize4
        MODULE PROCEDURE write_File_REAL_K8_D6_withSize4
        MODULE PROCEDURE write_File_REAL_K8_D1_withSize8
        MODULE PROCEDURE write_File_REAL_K8_D2_withSize8
        MODULE PROCEDURE write_File_REAL_K8_D3_withSize8
        MODULE PROCEDURE write_File_REAL_K8_D4_withSize8
        MODULE PROCEDURE write_File_REAL_K8_D5_withSize8
        MODULE PROCEDURE write_File_REAL_K8_D6_withSize8
        MODULE PROCEDURE write_File_CHARACTER
END INTERFACE write_File

INTERFACE write_Title
        MODULE PROCEDURE write_Title_INTEGER
        MODULE PROCEDURE write_Title_INTEGER_D1
        MODULE PROCEDURE write_Title_INTEGER_D2
        MODULE PROCEDURE write_Title_INTEGER_D3
        MODULE PROCEDURE write_Title_INTEGER_D4
        MODULE PROCEDURE write_Title_INTEGER_D5
        MODULE PROCEDURE write_Title_INTEGER_D6
        MODULE PROCEDURE write_Title_INTEGER_D1_withSize4
        MODULE PROCEDURE write_Title_INTEGER_D2_withSize4
        MODULE PROCEDURE write_Title_INTEGER_D3_withSize4
        MODULE PROCEDURE write_Title_INTEGER_D4_withSize4
        MODULE PROCEDURE write_Title_INTEGER_D5_withSize4
        MODULE PROCEDURE write_Title_INTEGER_D6_withSize4
        MODULE PROCEDURE write_Title_INTEGER_D1_withSize8
        MODULE PROCEDURE write_Title_INTEGER_D2_withSize8
        MODULE PROCEDURE write_Title_INTEGER_D3_withSize8
        MODULE PROCEDURE write_Title_INTEGER_D4_withSize8
        MODULE PROCEDURE write_Title_INTEGER_D5_withSize8
        MODULE PROCEDURE write_Title_INTEGER_D6_withSize8
        MODULE PROCEDURE write_Title_REAL_K4
        MODULE PROCEDURE write_Title_REAL_K4_D1
        MODULE PROCEDURE write_Title_REAL_K4_D2
        MODULE PROCEDURE write_Title_REAL_K4_D3
        MODULE PROCEDURE write_Title_REAL_K4_D4
        MODULE PROCEDURE write_Title_REAL_K4_D5
        MODULE PROCEDURE write_Title_REAL_K4_D6
        MODULE PROCEDURE write_Title_REAL_K4_D1_withSize4
        MODULE PROCEDURE write_Title_REAL_K4_D2_withSize4
        MODULE PROCEDURE write_Title_REAL_K4_D3_withSize4
        MODULE PROCEDURE write_Title_REAL_K4_D4_withSize4
        MODULE PROCEDURE write_Title_REAL_K4_D5_withSize4
        MODULE PROCEDURE write_Title_REAL_K4_D6_withSize4
        MODULE PROCEDURE write_Title_REAL_K4_D1_withSize8
        MODULE PROCEDURE write_Title_REAL_K4_D2_withSize8
        MODULE PROCEDURE write_Title_REAL_K4_D3_withSize8
        MODULE PROCEDURE write_Title_REAL_K4_D4_withSize8
        MODULE PROCEDURE write_Title_REAL_K4_D5_withSize8
        MODULE PROCEDURE write_Title_REAL_K4_D6_withSize8
        MODULE PROCEDURE write_Title_REAL_K8
        MODULE PROCEDURE write_Title_REAL_K8_D1
        MODULE PROCEDURE write_Title_REAL_K8_D2
        MODULE PROCEDURE write_Title_REAL_K8_D3
        MODULE PROCEDURE write_Title_REAL_K8_D4
        MODULE PROCEDURE write_Title_REAL_K8_D5
        MODULE PROCEDURE write_Title_REAL_K8_D6
        MODULE PROCEDURE write_Title_REAL_K8_D1_withSize4
        MODULE PROCEDURE write_Title_REAL_K8_D2_withSize4
        MODULE PROCEDURE write_Title_REAL_K8_D3_withSize4
        MODULE PROCEDURE write_Title_REAL_K8_D4_withSize4
        MODULE PROCEDURE write_Title_REAL_K8_D5_withSize4
        MODULE PROCEDURE write_Title_REAL_K8_D6_withSize4
        MODULE PROCEDURE write_Title_REAL_K8_D1_withSize8
        MODULE PROCEDURE write_Title_REAL_K8_D2_withSize8
        MODULE PROCEDURE write_Title_REAL_K8_D3_withSize8
        MODULE PROCEDURE write_Title_REAL_K8_D4_withSize8
        MODULE PROCEDURE write_Title_REAL_K8_D5_withSize8
        MODULE PROCEDURE write_Title_REAL_K8_D6_withSize8
END INTERFACE write_Title

contains

        FUNCTION construct_File(log_dir,log_index,log_rank,log_ext)
           IMPLICIT NONE
           INTEGER , INTENT(in):: log_index,log_rank
           CHARACTER(len=*), INTENT(in) :: log_dir,log_ext
           CHARACTER(len=10) :: log_index_str,log_rank_str
           CHARACTER(len=50) :: construct_File
           INTEGER*4  access, status
           status = access ( log_dir, ' ' )    ! blank mode
           if ( status .ne. 0 ) then 
              call system('mkdir '//trim(log_dir))
           end if
           write (log_index_str,"(I5.5)") log_index
           write (log_rank_str,"(I4.4)") log_rank
           construct_File=trim(log_dir)//"/"//trim(log_index_str)//"-"//trim(log_rank_str)//trim(log_ext)
           RETURN
        END FUNCTION

        SUBROUTINE open_File_name(FILE_NAME)
           IMPLICIT NONE
           CHARACTER(len=*) :: FILE_NAME
           open(unit=sdcFileID, file=FILE_NAME)
           return
        END SUBROUTINE

        SUBROUTINE open_File_id_name(id,FILE_NAME)
           IMPLICIT NONE
           INTEGER :: id
           CHARACTER(len=*) :: FILE_NAME
           sdcFileID=id
           open(unit=sdcFileID, file=FILE_NAME)
           return
        END SUBROUTINE

        SUBROUTINE close_File_nopar()
           close(sdcFileID)
        END SUBROUTINE

        SUBROUTINE close_File_id(id)
           IMPLICIT NONE
           INTEGER :: id
           close(id)
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER(data)
           IMPLICIT NONE
           INTEGER :: data
           write(sdcFileID, *) data
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D1(data)
           IMPLICIT NONE
           INTEGER , DIMENSION(:) :: data
           INTEGER :: SIZE1
           INTEGER :: i
           SIZE1 = size(data)
           do i=1,SIZE1
                write(sdcFileID, *) data(i)
           enddo
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D2(data)
           IMPLICIT NONE
           INTEGER , DIMENSION(:,:) :: data
           INTEGER :: SIZE1, SIZE2
           INTEGER :: i1,i2
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           do i2=1,SIZE2
              do i1=1,SIZE1
                 write(sdcFileID, *) data(i1,i2)
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D3(data)
           IMPLICIT NONE
           INTEGER , DIMENSION(:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3
           INTEGER :: i1,i2,i3
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           do i3=1,SIZE3
              do i2=1,SIZE2
                 do i1=1,SIZE1
                    write(sdcFileID, *) data(i1,i2,i3)
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D4(data)
           INTEGER , DIMENSION(:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4
           INTEGER :: i1,i2,i3,i4
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           SIZE4=size(data,4)
           do i4=1,SIZE4
              do i3=1,SIZE3
                 do i2=1,SIZE2
                    do i1=1,SIZE1
                       write(sdcFileID, *) data(i1,i2,i3,i4)
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D5(data)
           INTEGER , DIMENSION(:,:,:,:,:) :: data
           INTEGER :: SIZE1, SIZE2,SIZE3,SIZE4,SIZE5
           INTEGER :: i1,i2,i3,i4,i5
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           SIZE4=size(data,4)
           SIZE5=size(data,5)
           do i5=1,SIZE5
              do i4=1,SIZE4
                 do i3=1,SIZE3
                    do i2=1,SIZE2
                       do i1=1,SIZE1
                          write(sdcFileID, *) data(i1,i2,i3,i4,i5)
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D6(data)
           INTEGER , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           INTEGER :: i1,i2,i3,i4,i5,i6
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           SIZE4=size(data,4)
           SIZE5=size(data,5)
           SIZE6=size(data,6)
           do i6=1,SIZE6
              do i5=1,SIZE5
                 do i4=1,SIZE4
                    do i3=1,SIZE3
                       do i2=1,SIZE2
                          do i1=1,SIZE1
                             write(sdcFileID, *) data(i1,i2,i3,i4,i5,i6)
                          enddo
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE
        
        SUBROUTINE write_FILE_INTEGER_D1_withSize4(data, SIZE1)
           IMPLICIT NONE
           INTEGER , DIMENSION(:) :: data
           INTEGER(KIND=4) :: SIZE1
           INTEGER :: i
           do i=1,SIZE1
                write(sdcFileID, *) data(i)
           enddo
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D2_withSize4(data, SIZE1, SIZE2)
           IMPLICIT NONE
           INTEGER , DIMENSION(:,:) :: data
           INTEGER(KIND=4) :: SIZE1, SIZE2
           INTEGER :: i1,i2
           do i2=1,SIZE2
              do i1=1,SIZE1
                 write(sdcFileID, *) data(i1,i2)
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D3_withSize4(data, SIZE1, SIZE2, SIZE3)
           IMPLICIT NONE
           INTEGER , DIMENSION(:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3
           INTEGER :: i1,i2,i3
           do i3=1,SIZE3
              do i2=1,SIZE2
                 do i1=1,SIZE1
                    write(sdcFileID, *) data(i1,i2,i3)
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D4_withSize4(data, SIZE1, SIZE2, SIZE3, SIZE4)
           INTEGER , DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4
           INTEGER :: i1,i2,i3,i4
           do i4=1,SIZE4
              do i3=1,SIZE3
                 do i2=1,SIZE2
                    do i1=1,SIZE1
                       write(sdcFileID, *) data(i1,i2,i3,i4)
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D5_withSize4(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           INTEGER , DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1, SIZE2,SIZE3,SIZE4,SIZE5
           INTEGER :: i1,i2,i3,i4,i5
           do i5=1,SIZE5
              do i4=1,SIZE4
                 do i3=1,SIZE3
                    do i2=1,SIZE2
                       do i1=1,SIZE1
                          write(sdcFileID, *) data(i1,i2,i3,i4,i5)
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D6_withSize4(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           INTEGER , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           INTEGER :: i1,i2,i3,i4,i5,i6
           do i6=1,SIZE6
              do i5=1,SIZE5
                 do i4=1,SIZE4
                    do i3=1,SIZE3
                       do i2=1,SIZE2
                          do i1=1,SIZE1
                             write(sdcFileID, *) data(i1,i2,i3,i4,i5,i6)
                          enddo
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D1_withSize8(data, SIZE1)
           IMPLICIT NONE
           INTEGER , DIMENSION(:) :: data
           INTEGER(KIND=8) :: SIZE1
           INTEGER :: i
           do i=1,SIZE1
                write(sdcFileID, *) data(i)
           enddo
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D2_withSize8(data, SIZE1, SIZE2)
           IMPLICIT NONE
           INTEGER , DIMENSION(:,:) :: data
           INTEGER(KIND=8) :: SIZE1, SIZE2
           INTEGER :: i1,i2
           do i2=1,SIZE2
              do i1=1,SIZE1
                 write(sdcFileID, *) data(i1,i2)
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D3_withSize8(data, SIZE1, SIZE2, SIZE3)
           IMPLICIT NONE
           INTEGER , DIMENSION(:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3
           INTEGER :: i1,i2,i3
           do i3=1,SIZE3
              do i2=1,SIZE2
                 do i1=1,SIZE1
                    write(sdcFileID, *) data(i1,i2,i3)
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D4_withSize8(data, SIZE1, SIZE2, SIZE3, SIZE4)
           INTEGER , DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4
           INTEGER :: i1,i2,i3,i4
           do i4=1,SIZE4
              do i3=1,SIZE3
                 do i2=1,SIZE2
                    do i1=1,SIZE1
                       write(sdcFileID, *) data(i1,i2,i3,i4)
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D5_withSize8(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           INTEGER , DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1, SIZE2,SIZE3,SIZE4,SIZE5
           INTEGER :: i1,i2,i3,i4,i5
           do i5=1,SIZE5
              do i4=1,SIZE4
                 do i3=1,SIZE3
                    do i2=1,SIZE2
                       do i1=1,SIZE1
                          write(sdcFileID, *) data(i1,i2,i3,i4,i5)
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_INTEGER_D6_withSize8(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           INTEGER , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           INTEGER :: i1,i2,i3,i4,i5,i6
           do i6=1,SIZE6
              do i5=1,SIZE5
                 do i4=1,SIZE4
                    do i3=1,SIZE3
                       do i2=1,SIZE2
                          do i1=1,SIZE1
                             write(sdcFileID, *) data(i1,i2,i3,i4,i5,i6)
                          enddo
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

!process real values 
        SUBROUTINE write_FILE_REAL_K4(data)
           REAL(KIND=4) :: data
           write(sdcFileID, *) data
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D1(data)
           REAL(KIND=4), DIMENSION(:) :: data
           INTEGER :: SIZE1
           INTEGER :: i
           SIZE1=size(data)
           do i=1,SIZE1
                write(sdcFileID, *) data(i)
           enddo
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D2(data)
           REAL(KIND=4), DIMENSION(:,:) :: data
           INTEGER :: SIZE1,SIZE2
           INTEGER :: i1,i2
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           do i2=1,SIZE2
              do i1=1,SIZE1
                 write(sdcFileID, *) data(i1,i2)
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D3(data)
           REAL(KIND=4), DIMENSION(:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3
           INTEGER :: i1,i2,i3
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           do i3=1,SIZE3
              do i2=1,SIZE2
                 do i1=1,SIZE1
                    write(sdcFileID, *) data(i1,i2,i3)
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D4(data)
           REAL(KIND=4) , DIMENSION(:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4
           INTEGER :: i1,i2,i3,i4
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           SIZE4=size(data,4)
           do i4=1,SIZE4
              do i3=1,SIZE3
                 do i2=1,SIZE2
                    do i1=1,SIZE1
                       write(sdcFileID, *) data(i1,i2,i3,i4)
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D5(data)
           REAL(KIND=4) , DIMENSION(:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           INTEGER :: i1,i2,i3,i4,i5
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           SIZE4=size(data,4)
           SIZE5=size(data,5)
           do i5=1,SIZE5
              do i4=1,SIZE4
                 do i3=1,SIZE3
                    do i2=1,SIZE2
                       do i1=1,SIZE1
                          write(sdcFileID, *) data(i1,i2,i3,i4,i5)
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D6(data)
           REAL(KIND=4) , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           INTEGER :: i1,i2,i3,i4,i5,i6
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           SIZE4=size(data,4)
           SIZE5=size(data,5)
           SIZE6=size(data,6)
           do i6=1,SIZE6
              do i5=1,SIZE5
                 do i4=1,SIZE4
                    do i3=1,SIZE3
                       do i2=1,SIZE2
                          do i1=1,SIZE1
                             write(sdcFileID, *) data(i1,i2,i3,i4,i5,i6)
                          enddo
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D1_withSize4(data, SIZE1)
           REAL(KIND=4), DIMENSION(:) :: data
           INTEGER(KIND=4) :: SIZE1
           INTEGER :: i
           do i=1,SIZE1
                write(sdcFileID, *) data(i)
           enddo
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D2_withSize4(data, SIZE1, SIZE2)
           REAL(KIND=4), DIMENSION(:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2
           INTEGER :: i1,i2
           do i2=1,SIZE2
              do i1=1,SIZE1
                 write(sdcFileID, *) data(i1,i2)
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D3_withSize4(data, SIZE1, SIZE2, SIZE3)
           REAL(KIND=4), DIMENSION(:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3
           INTEGER :: i1,i2,i3
           do i3=1,SIZE3
              do i2=1,SIZE2
                 do i1=1,SIZE1
                    write(sdcFileID, *) data(i1,i2,i3)
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D4_withSize4(data, SIZE1, SIZE2, SIZE3, SIZE4)
           REAL(KIND=4) , DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4
           INTEGER :: i1,i2,i3,i4
           do i4=1,SIZE4
              do i3=1,SIZE3
                 do i2=1,SIZE2
                    do i1=1,SIZE1
                       write(sdcFileID, *) data(i1,i2,i3,i4)
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D5_withSize4(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           REAL(KIND=4) , DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           INTEGER :: i1,i2,i3,i4,i5
           do i5=1,SIZE5
              do i4=1,SIZE4
                 do i3=1,SIZE3
                    do i2=1,SIZE2
                       do i1=1,SIZE1
                          write(sdcFileID, *) data(i1,i2,i3,i4,i5)
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D6_withSize4(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           REAL(KIND=4) , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           INTEGER :: i1,i2,i3,i4,i5,i6
           do i6=1,SIZE6
              do i5=1,SIZE5
                 do i4=1,SIZE4
                    do i3=1,SIZE3
                       do i2=1,SIZE2
                          do i1=1,SIZE1
                             write(sdcFileID, *) data(i1,i2,i3,i4,i5,i6)
                          enddo
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D1_withSize8(data, SIZE1)
           REAL(KIND=4), DIMENSION(:) :: data
           INTEGER(KIND=8) :: SIZE1
           INTEGER :: i
           do i=1,SIZE1
                write(sdcFileID, *) data(i)
           enddo
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D2_withSize8(data, SIZE1, SIZE2)
           REAL(KIND=4), DIMENSION(:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2
           INTEGER :: i1,i2
           do i2=1,SIZE2
              do i1=1,SIZE1
                 write(sdcFileID, *) data(i1,i2)
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D3_withSize8(data, SIZE1, SIZE2, SIZE3)
           REAL(KIND=4), DIMENSION(:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3
           INTEGER :: i1,i2,i3
           do i3=1,SIZE3
              do i2=1,SIZE2
                 do i1=1,SIZE1
                    write(sdcFileID, *) data(i1,i2,i3)
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D4_withSize8(data, SIZE1, SIZE2, SIZE3, SIZE4)
           REAL(KIND=4) , DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4
           INTEGER :: i1,i2,i3,i4
           do i4=1,SIZE4
              do i3=1,SIZE3
                 do i2=1,SIZE2
                    do i1=1,SIZE1
                       write(sdcFileID, *) data(i1,i2,i3,i4)
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D5_withSize8(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           REAL(KIND=4) , DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           INTEGER :: i1,i2,i3,i4,i5
           do i5=1,SIZE5
              do i4=1,SIZE4
                 do i3=1,SIZE3
                    do i2=1,SIZE2
                       do i1=1,SIZE1
                          write(sdcFileID, *) data(i1,i2,i3,i4,i5)
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K4_D6_withSize8(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           REAL(KIND=4) , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           INTEGER :: i1,i2,i3,i4,i5,i6
           do i6=1,SIZE6
              do i5=1,SIZE5
                 do i4=1,SIZE4
                    do i3=1,SIZE3
                       do i2=1,SIZE2
                          do i1=1,SIZE1
                             write(sdcFileID, *) data(i1,i2,i3,i4,i5,i6)
                          enddo
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

!process real(kind=8) values 
        SUBROUTINE write_FILE_REAL_K8(data)
           REAL(KIND=8) :: data
           write(sdcFileID, *) data
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D1(data)
           REAL(KIND=8), DIMENSION(:) :: data
           INTEGER :: SIZE1
           INTEGER :: i
           SIZE1=size(data)
           do i=1,SIZE1
                write(sdcFileID, *) data(i)
           enddo
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D2(data)
           REAL(KIND=8), DIMENSION(:,:) :: data
           INTEGER :: SIZE1,SIZE2
           INTEGER :: i1,i2
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           do i2=1,SIZE2
              do i1=1,SIZE1
                 write(sdcFileID, *) data(i1,i2)
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D3(data)
           REAL(KIND=8), DIMENSION(:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3
           INTEGER :: i1,i2,i3
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           do i3=1,SIZE3
              do i2=1,SIZE2
                 do i1=1,SIZE1
                    write(sdcFileID, *) data(i1,i2,i3)
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D4(data)
           REAL(KIND=8) , DIMENSION(:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4
           INTEGER :: i1,i2,i3,i4
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           SIZE4=size(data,4)
           do i4=1,SIZE4
              do i3=1,SIZE3
                 do i2=1,SIZE2
                    do i1=1,SIZE1
                       write(sdcFileID, *) data(i1,i2,i3,i4)
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D5(data)
           REAL(KIND=8) , DIMENSION(:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           INTEGER :: i1,i2,i3,i4,i5
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           SIZE4=size(data,4)
           SIZE5=size(data,5)
           do i5=1,SIZE5
              do i4=1,SIZE4
                 do i3=1,SIZE3
                    do i2=1,SIZE2
                       do i1=1,SIZE1
                          write(sdcFileID, *) data(i1,i2,i3,i4,i5)
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D6(data)
           REAL(KIND=8) , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           INTEGER :: i1,i2,i3,i4,i5,i6
           SIZE1=size(data,1)
           SIZE2=size(data,2)
           SIZE3=size(data,3)
           SIZE4=size(data,4)
           SIZE5=size(data,5)
           SIZE6=size(data,6)
           do i6=1,SIZE6
              do i5=1,SIZE5
                 do i4=1,SIZE4
                    do i3=1,SIZE3
                       do i2=1,SIZE2
                          do i1=1,SIZE1
                             write(sdcFileID, *) data(i1,i2,i3,i4,i5,i6)
                          enddo
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D1_withSize4(data, SIZE1)
           REAL(KIND=8), DIMENSION(:) :: data
           INTEGER(KIND=4) :: SIZE1
           INTEGER :: i
           do i=1,SIZE1
                write(sdcFileID, *) data(i)
           enddo
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D2_withSize4(data, SIZE1, SIZE2)
           REAL(KIND=8), DIMENSION(:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2
           INTEGER :: i1,i2
           do i2=1,SIZE2
              do i1=1,SIZE1
                 write(sdcFileID, *) data(i1,i2)
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D3_withSize4(data, SIZE1, SIZE2, SIZE3)
           REAL(KIND=8), DIMENSION(:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3
           INTEGER :: i1,i2,i3
           do i3=1,SIZE3
              do i2=1,SIZE2
                 do i1=1,SIZE1
                    write(sdcFileID, *) data(i1,i2,i3)
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D4_withSize4(data, SIZE1, SIZE2, SIZE3, SIZE4)
           REAL(KIND=8) , DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4
           INTEGER :: i1,i2,i3,i4
           do i4=1,SIZE4
              do i3=1,SIZE3
                 do i2=1,SIZE2
                    do i1=1,SIZE1
                       write(sdcFileID, *) data(i1,i2,i3,i4)
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D5_withSize4(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           REAL(KIND=8) , DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           INTEGER :: i1,i2,i3,i4,i5
           do i5=1,SIZE5
              do i4=1,SIZE4
                 do i3=1,SIZE3
                    do i2=1,SIZE2
                       do i1=1,SIZE1
                          write(sdcFileID, *) data(i1,i2,i3,i4,i5)
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D6_withSize4(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           REAL(KIND=8) , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           INTEGER :: i1,i2,i3,i4,i5,i6
           do i6=1,SIZE6
              do i5=1,SIZE5
                 do i4=1,SIZE4
                    do i3=1,SIZE3
                       do i2=1,SIZE2
                          do i1=1,SIZE1
                             write(sdcFileID, *) data(i1,i2,i3,i4,i5,i6)
                          enddo
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D1_withSize8(data, SIZE1)
           REAL(KIND=8), DIMENSION(:) :: data
           INTEGER(KIND=8) :: SIZE1
           INTEGER :: i
           do i=1,SIZE1
                write(sdcFileID, *) data(i)
           enddo
           return
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D2_withSize8(data, SIZE1, SIZE2)
           REAL(KIND=8), DIMENSION(:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2
           INTEGER :: i1,i2
           do i2=1,SIZE2
              do i1=1,SIZE1
                 write(sdcFileID, *) data(i1,i2)
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D3_withSize8(data, SIZE1, SIZE2, SIZE3)
           REAL(KIND=8), DIMENSION(:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3
           INTEGER :: i1,i2,i3
           do i3=1,SIZE3
              do i2=1,SIZE2
                 do i1=1,SIZE1
                    write(sdcFileID, *) data(i1,i2,i3)
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D4_withSize8(data, SIZE1, SIZE2, SIZE3, SIZE4)
           REAL(KIND=8) , DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4
           INTEGER :: i1,i2,i3,i4
           do i4=1,SIZE4
              do i3=1,SIZE3
                 do i2=1,SIZE2
                    do i1=1,SIZE1
                       write(sdcFileID, *) data(i1,i2,i3,i4)
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D5_withSize8(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           REAL(KIND=8) , DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           INTEGER :: i1,i2,i3,i4,i5
           do i5=1,SIZE5
              do i4=1,SIZE4
                 do i3=1,SIZE3
                    do i2=1,SIZE2
                       do i1=1,SIZE1
                          write(sdcFileID, *) data(i1,i2,i3,i4,i5)
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

        SUBROUTINE write_FILE_REAL_K8_D6_withSize8(data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           REAL(KIND=8) , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           INTEGER :: i1,i2,i3,i4,i5,i6
           do i6=1,SIZE6
              do i5=1,SIZE5
                 do i4=1,SIZE4
                    do i3=1,SIZE3
                       do i2=1,SIZE2
                          do i1=1,SIZE1
                             write(sdcFileID, *) data(i1,i2,i3,i4,i5,i6)
                          enddo
                       enddo
                    enddo
                 enddo
              enddo
           enddo
        END SUBROUTINE

!process character string values 
        SUBROUTINE write_FILE_CHARACTER(data)
           CHARACTER(len=*) :: data
           write(sdcFileID, *) data
           return
        END SUBROUTINE

!write titles
        SUBROUTINE write_Title_INTEGER(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER :: data
           INTEGER :: dimen
           write(sdcFileID, *) trim(string)//" INTEGER 0"
           return
        END SUBROUTINE

        SUBROUTINE write_Title_INTEGER_D1(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:) :: data
           INTEGER :: SIZE1
           CHARACTER(len=50) :: str_SIZE1
           SIZE1 = size(data)
           write(str_SIZE1,"(I9)") SIZE1
           write(sdcFileID, *) trim(string)//" INTEGER 1 "//trim(str_SIZE1)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_INTEGER_D2(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:) :: data
           INTEGER :: SIZE1,SIZE2
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(sdcFileID, *) trim(string)//" INTEGER 2 "//trim(str_SIZE1)//" "//trim(str_SIZE2)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_INTEGER_D3(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2,str_SIZE3
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(str_SIZE3,"(I9)") SIZE3
           write(sdcFileID, *) trim(string)//" INTEGER 3 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_INTEGER_D4(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4
           CHARACTER(len=60) :: str_tmp
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           SIZE4 = size(data,4)
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_tmp, *) trim(string)//" INTEGER 4 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_INTEGER_D5(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5
           CHARACTER(len=60) :: str_tmp
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           SIZE4 = size(data,4)
           SIZE5 = size(data,5)
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_tmp, *) trim(string)//" INTEGER 5 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_INTEGER_D6(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_SIZE6
           CHARACTER(len=60) :: str_tmp
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           SIZE4 = size(data,4)
           SIZE5 = size(data,5)
           SIZE6 = size(data,6)
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_SIZE6,"(I5)") SIZE6
           write(str_tmp, *) trim(string)//" INTEGER 6 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)//" "//trim(str_SIZE6)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_INTEGER_D1_withSize4(string,data,SIZE1)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:) :: data
           INTEGER(KIND=4) :: SIZE1
           CHARACTER(len=50) :: str_SIZE1
           write(str_SIZE1,"(I9)") SIZE1
           write(sdcFileID, *) trim(string)//" INTEGER 1 "//trim(str_SIZE1)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_INTEGER_D2_withSize4(string, data, SIZE1, SIZE2)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(sdcFileID, *) trim(string)//" INTEGER 2 "//trim(str_SIZE1)//" "//trim(str_SIZE2)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_INTEGER_D3_withSize4(string, data, SIZE1, SIZE2, SIZE3)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER(KIND=4) , DIMENSION(:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2,str_SIZE3
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(str_SIZE3,"(I9)") SIZE3
           write(sdcFileID, *) trim(string)//" INTEGER 3 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_INTEGER_D4_withSize4(string, data, SIZE1, SIZE2, SIZE3, SIZE4)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_tmp, *) trim(string)//" INTEGER 4 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_INTEGER_D5_withSize4(string, data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_tmp, *) trim(string)//" INTEGER 5 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_INTEGER_D6_withSize4(string, data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_SIZE6
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_SIZE6,"(I5)") SIZE6
           write(str_tmp, *) trim(string)//" INTEGER 6 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)//" "//trim(str_SIZE6)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_INTEGER_D1_withSize8(string,data,SIZE1)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:) :: data
           INTEGER(KIND=8) :: SIZE1
           CHARACTER(len=50) :: str_SIZE1
           write(str_SIZE1,"(I9)") SIZE1
           write(sdcFileID, *) trim(string)//" INTEGER 1 "//trim(str_SIZE1)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_INTEGER_D2_withSize8(string, data, SIZE1, SIZE2)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(sdcFileID, *) trim(string)//" INTEGER 2 "//trim(str_SIZE1)//" "//trim(str_SIZE2)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_INTEGER_D3_withSize8(string, data, SIZE1, SIZE2, SIZE3)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER(KIND=8) , DIMENSION(:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2,str_SIZE3
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(str_SIZE3,"(I9)") SIZE3
           write(sdcFileID, *) trim(string)//" INTEGER 3 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_INTEGER_D4_withSize8(string, data, SIZE1, SIZE2, SIZE3, SIZE4)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_tmp, *) trim(string)//" INTEGER 4 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_INTEGER_D5_withSize8(string, data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_tmp, *) trim(string)//" INTEGER 5 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_INTEGER_D6_withSize8(string, data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           INTEGER , DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_SIZE6
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_SIZE6,"(I5)") SIZE6
           write(str_tmp, *) trim(string)//" INTEGER 6 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)//" "//trim(str_SIZE6)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K4(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4) :: data
           INTEGER :: dimen
           write(sdcFileID, *) trim(string)//" REAL_K4 0"
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K4_D1(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:) :: data
           INTEGER :: SIZE1
           CHARACTER(len=50) :: str_SIZE1
           SIZE1 = size(data)
           write(str_SIZE1,"(I9)") SIZE1
           write(sdcFileID, *) trim(string)//" REAL_K4 1 "//trim(str_SIZE1)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K4_D2(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:) :: data
           INTEGER :: SIZE1,SIZE2
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(sdcFileID, *) trim(string)//" REAL_K4 2 "//trim(str_SIZE1)//" "//trim(str_SIZE2)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K4_D3(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2,str_SIZE3
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(str_SIZE3,"(I9)") SIZE3
           write(sdcFileID, *) trim(string)//" REAL_K4 3 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K4_D4(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4
           CHARACTER(len=60) :: str_tmp
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           SIZE4 = size(data,4)
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_tmp, *) trim(string)//" REAL_K4 4 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K4_D5(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           CHARACTER(len=60) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_tmp
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           SIZE4 = size(data,4)
           SIZE5 = size(data,5)
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_tmp, *) trim(string)//" REAL_K4 5 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K4_D6(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           CHARACTER(len=60) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_SIZE6,str_tmp
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           SIZE4 = size(data,4)
           SIZE5 = size(data,5)
           SIZE6 = size(data,6)
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_SIZE6,"(I5)") SIZE6
           write(str_tmp, *) trim(string)//" REAL_K4 6 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)//" "//trim(str_SIZE6)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K4_D1_withSize4(string,data, SIZE1)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:) :: data
           INTEGER(KIND=4) :: SIZE1
           CHARACTER(len=50) :: str_SIZE1
           write(str_SIZE1,"(I9)") SIZE1
           write(sdcFileID, *) trim(string)//" REAL_K4 1 "//trim(str_SIZE1)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K4_D2_withSize4(string,data, SIZE1, SIZE2)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(sdcFileID, *) trim(string)//" REAL_K4 2 "//trim(str_SIZE1)//" "//trim(str_SIZE2)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K4_D3_withSize4(string,data, SIZE1, SIZE2, SIZE3)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2,str_SIZE3
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(str_SIZE3,"(I9)") SIZE3
           write(sdcFileID, *) trim(string)//" REAL_K4 3 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K4_D4_withSize4(string,data,SIZE1, SIZE2, SIZE3, SIZE4)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_tmp, *) trim(string)//" REAL_K4 4 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K4_D5_withSize4(string,data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_tmp, *) trim(string)//" REAL_K4 5 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K4_D6_withSize4(string,data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_SIZE6
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_SIZE6,"(I5)") SIZE6
           write(str_tmp, *) trim(string)//" REAL_K4 6 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)//" "//trim(str_SIZE6)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K4_D1_withSize8(string,data, SIZE1)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:) :: data
           INTEGER(KIND=8) :: SIZE1
           CHARACTER(len=50) :: str_SIZE1
           write(str_SIZE1,"(I9)") SIZE1
           write(sdcFileID, *) trim(string)//" REAL_K4 1 "//trim(str_SIZE1)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K4_D2_withSize8(string,data, SIZE1, SIZE2)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(sdcFileID, *) trim(string)//" REAL_K4 2 "//trim(str_SIZE1)//" "//trim(str_SIZE2)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K4_D3_withSize8(string,data, SIZE1, SIZE2, SIZE3)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2,str_SIZE3
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(str_SIZE3,"(I9)") SIZE3
           write(sdcFileID, *) trim(string)//" REAL_K4 3 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K4_D4_withSize8(string,data,SIZE1, SIZE2, SIZE3, SIZE4)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_tmp, *) trim(string)//" REAL_K4 4 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K4_D5_withSize8(string,data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_tmp, *) trim(string)//" REAL_K4 5 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K4_D6_withSize8(string,data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=4), DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_SIZE6
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_SIZE6,"(I5)") SIZE6
           write(str_tmp, *) trim(string)//" REAL_K4 6 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)//" "//trim(str_SIZE6)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K8(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8) :: data
           INTEGER :: dimen
           write(sdcFileID, *) trim(string)//" REAL_K8 0"
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K8_D1(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:) :: data
           INTEGER :: SIZE1
           CHARACTER(len=50) :: str_SIZE1
           SIZE1 = size(data)
           write(str_SIZE1,"(I9)") SIZE1
           write(sdcFileID, *) trim(string)//" REAL_K8 1 "//trim(str_SIZE1)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K8_D2(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:) :: data
           INTEGER :: SIZE1,SIZE2
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(sdcFileID, *) trim(string)//" REAL_K8 2 "//trim(str_SIZE1)//" "//trim(str_SIZE2)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K8_D3(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2,str_SIZE3
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(str_SIZE3,"(I9)") SIZE3
           write(sdcFileID, *) trim(string)//" REAL_K8 3 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K8_D4(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4
           CHARACTER(len=60) :: str_tmp
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           SIZE4 = size(data,4)
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           
           write(str_tmp, *) trim(string)//" REAL_K8 4 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K8_D5(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5
	   CHARACTER(len=60) :: str_tmp
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           SIZE4 = size(data,4)
           SIZE5 = size(data,5)
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_tmp, *) trim(string)//" REAL_K8 5 "//trim(str_SIZE1)//" "//trim(str_SIZE2)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE3)//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K8_D6(string,data)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:,:,:,:) :: data
           INTEGER :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_SIZE6
           CHARACTER(len=60) :: str_tmp
           SIZE1 = size(data,1)
           SIZE2 = size(data,2)
           SIZE3 = size(data,3)
           SIZE4 = size(data,4)
           SIZE5 = size(data,5)
           SIZE6 = size(data,6)
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_SIZE6,"(I5)") SIZE6
           write(str_tmp, *) trim(string)//" REAL_K8 6 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)//" "//trim(str_SIZE6)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K8_D1_withSize4(string,data,SIZE1)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:) :: data
           INTEGER(KIND=4) :: SIZE1
           CHARACTER(len=50) :: str_SIZE1
           write(str_SIZE1,"(I9)") SIZE1
           write(sdcFileID, *) trim(string)//" REAL_K8 1 "//trim(str_SIZE1)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K8_D2_withSize4(string,data, SIZE1, SIZE2)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(sdcFileID, *) trim(string)//" REAL_K8 2 "//trim(str_SIZE1)//" "//trim(str_SIZE2)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K8_D3_withSize4(string,data, SIZE1, SIZE2, SIZE3)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2,str_SIZE3
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(str_SIZE3,"(I9)") SIZE3
           write(sdcFileID, *) trim(string)//" REAL_K8 3 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K8_D4_withSize4(string,data, SIZE1, SIZE2, SIZE3, SIZE4)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4
           CHARACTER(len=10) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4
           CHARACTER(len=60) :: str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_tmp, *) trim(string)//" REAL_K8 4 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K8_D5_withSize4(string,data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           CHARACTER(len=60) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_tmp, *) trim(string)//" REAL_K8 5 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K8_D6_withSize4(string,data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=4) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           CHARACTER(len=60) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_SIZE6,str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_SIZE6,"(I5)") SIZE6
           write(str_tmp, *) trim(string)//" REAL_K8 6 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)//" "//trim(str_SIZE6)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K8_D1_withSize8(string,data,SIZE1)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:) :: data
           INTEGER(KIND=8) :: SIZE1
           CHARACTER(len=60) :: str_SIZE1
           write(str_SIZE1,"(I9)") SIZE1
           write(sdcFileID, *) trim(string)//" REAL_K8 1 "//trim(str_SIZE1)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K8_D2_withSize8(string,data, SIZE1, SIZE2)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2
           CHARACTER(len=60) :: str_SIZE1,str_SIZE2
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(sdcFileID, *) trim(string)//" REAL_K8 2 "//trim(str_SIZE1)//" "//trim(str_SIZE2)
           return
        END SUBROUTINE

        SUBROUTINE write_Title_REAL_K8_D3_withSize8(string,data, SIZE1, SIZE2, SIZE3)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3
           CHARACTER(len=60) :: str_SIZE1,str_SIZE2,str_SIZE3
           write(str_SIZE1,"(I9)") SIZE1
           write(str_SIZE2,"(I9)") SIZE2
           write(str_SIZE3,"(I9)") SIZE3
           write(sdcFileID, *) trim(string)//" REAL_K8 3 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K8_D4_withSize8(string,data, SIZE1, SIZE2, SIZE3, SIZE4)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_tmp, *) trim(string)//" REAL_K8 4 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K8_D5_withSize8(string,data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5
           CHARACTER(len=50) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_tmp, *) trim(string)//" REAL_K8 5 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)
           return
        END SUBROUTINE
        
        SUBROUTINE write_Title_REAL_K8_D6_withSize8(string,data, SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6)
           IMPLICIT NONE
           CHARACTER(len=*) :: string
           REAL(KIND=8), DIMENSION(:,:,:,:,:,:) :: data
           INTEGER(KIND=8) :: SIZE1,SIZE2,SIZE3,SIZE4,SIZE5,SIZE6
           CHARACTER(len=60) :: str_SIZE1,str_SIZE2,str_SIZE3,str_SIZE4,str_SIZE5,str_SIZE6,str_tmp
           write(str_SIZE1,"(I5)") SIZE1
           write(str_SIZE2,"(I5)") SIZE2
           write(str_SIZE3,"(I5)") SIZE3
           write(str_SIZE4,"(I5)") SIZE4
           write(str_SIZE5,"(I5)") SIZE5
           write(str_SIZE6,"(I5)") SIZE6
           write(str_tmp, *) trim(string)//" REAL_K8 6 "//trim(str_SIZE1)//" "//trim(str_SIZE2)//" "//trim(str_SIZE3)
           write(sdcFileID, *) str_tmp//" "//trim(str_SIZE4)//" "//trim(str_SIZE5)//" "//trim(str_SIZE6)
           return
        END SUBROUTINE
END MODULE
