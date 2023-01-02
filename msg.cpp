#include<stdio.h>
#include<string.h>
#include<mpi.h>
#include<stdlib.h>
#define BUFFSIZE 32
char *m[]={"hello","cse","rvce"};

int main(int argc,char *argv[])
{
int rank,root=0,tag=0,num,i;
char msg[BUFFSIZE];
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &num);

if(rank==0)
{
for(i=0;i<num;i++){
strcpy(msg,m[i-1]);
MPI_Send(&msg,BUFFSIZE,MPI_CHAR,i,tag,MPI_COMM_WORLD);
}
}
else
{
MPI_Status status;
MPI_Recv(&msg,BUFFSIZE,MPI_CHAR,i,tag,MPI_COMM_WORLD,&status);
printf("\n %d received from root=%d the message=%s",rank,root,msg);
}
MPI_Finalize();
}


