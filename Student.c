#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main()
{
    struct scores
    {
     char name;
     int score;
     }student;

     float arryr[3];

     int size,rank=0,tag=5;

     // type creation
     const int items=2;
     int structtlen[2]={1,1};
     MPI_Datatype type[2]={MPI_CHAR,MPI_INT};
     MPI_Datatype studenttype;
     MPI_AINT offsets[2];
     offsets[0]=offsetof(student,name);
     offsets[1]=offsetof(student,score);
     MPI_Type_create_struct(items,structtlen,offsets,type,&studenttype);
     MPI_Type_commit(&student);

     MPI_Init(NULL,NULL);
     MPI_Comm_rank(MPI_COMM_WORLD,&rank);

     srand(0);

     for(int i=0;i<15;i++)
     {
         if (i%3==0)
         {
             student.name="a";
         }
         else if(i%3==1)
         {
             student.name="b";
         }
         else
         {
             student.name="c";
         }
         student.score=0+rand()21%;

         if(rank==0)
         {
             rank=1;
             student send;
             send.name;
             send.score;
             const int dest=1;
             MPI_Send(&send,1,studenttype,dest,tag,MPI_COMM_WORLD);
         }

         if(rank==1)
         {
             rank=0;
             MPI_Status status;
             const int src=0;
             student recv;
             MPI_Recv(&recv,1,studenttype,src,tag,MPI_COMM_WORLD,&status);
             if(recv.name=="a")
             {
                 arryr[0]=recv.score;
             }
             else if(recv.name=="b")
             {
                 arryr[1]=recv.score;
             }
             else if(recv.name=="c")
             {
                 arryr[2]=recv.score;
             }
         }

         for(int j==0;j<3;j
         {
             arryr[j]=arryr[j]/5;
             printf(arryr[j]);
         }

     }

         MPI_Type_free(studenttype);
         MPI_Finalize();


    return 0;
}
