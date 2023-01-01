#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define SEED 58674765

int main()
{
double z,pi,x,y,s,e;
int count, n_th,n,i;

printf("iter\t\t");
for (i=1;i<=8;i*=2)
{
printf("pi\t\t%d\t\t",i);
}
for(n=1000;n<=1000000;n*=10)
{
n_th=1;

printf("\n%d\t",n);
while(n_th<=8)
{

count=0;
srand(SEED);
s=omp_get_wtime();
omp_set_num_threads(n_th);

#pragma omp parallel for 
for(i=1;i<n;i++)
{
x=(double)rand()/RAND_MAX;
y=(double)rand()/RAND_MAX;

z=x*x+y*y;
if(z<=1)
count++;
}
pi=(double)count/n*4;
e=omp_get_wtime();
n_th*=2;
printf("%lf\t %lf \t",pi,e-s);
}
}
}
