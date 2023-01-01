#include<stdio.h>
#include<omp.h>
#include<stdlib.h>


int main() {
int size,n_t,i,j,k;

for(size=100;size<=500;size+=100)
{
printf("\nSIZE=%d\n",size);
n_t=1;
while(n_t<=8)
{
printf("\nthreads=%d\t\t",n_t);
	int *A = new int[size*size];
	int *B = new int[size*size];
	int *C = new int[size*size];
	double t = omp_get_wtime();
	omp_set_num_threads(n_t);
	#pragma omp parallel for private(i,j)
	for (i = 0; i < size;i++)
		for (j = 0; j < size;j++)
			for (k = 0; k < size;k++)
				// C[i][k] == C[size*i+k]
				C[size*i + k] += A[size*i + j] * B[size*j + k];

	t = omp_get_wtime() - t;
	printf("time=%lf",t);
n_t*=2;
}
}
}
