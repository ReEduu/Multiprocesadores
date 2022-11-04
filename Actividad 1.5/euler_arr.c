#include <stdio.h>
#include <omp.h>
#include <math.h>
#define NUM_THREADS 6

   FILE *fptr;
   FILE *fptr1;
   FILE *fptr2;
   FILE *fptr3;
   FILE *fptr4;
   FILE *fptr5;
   double t[1666666][6];
   double w[1666666][6];

void iteracion(int numP,int N,FILE *x);

int main()
{  omp_set_num_threads(NUM_THREADS);
   double t1,t2;
   int N = 1666666;
   fptr=fopen("Euler_n_0.txt","w");
   fptr1=fopen("Euler_n_1.txt","w");
   fptr2=fopen("Euler_n_2.txt","w");
   fptr3=fopen("Euler_n_3.txt","w");
   fptr4=fopen("Euler_n_4.txt","w");
   fptr5=fopen("Euler_n_5.txt","w");

   t1= omp_get_wtime();
   #pragma omp parallel
{
     #pragma omp sections
    {
       #pragma omp section
         (void)iteracion(0,N,fptr);//20//2000900
       #pragma omp section
         (void)iteracion(1,N,fptr1);//200//2000400
       #pragma omp section
         (void)iteracion(2,N,fptr2);//2000//2000700
       #pragma omp section
         (void)iteracion(3,N,fptr3);//20000//2000800
       #pragma omp section
         (void)iteracion(4,N,fptr4);//200000//2000500
       #pragma omp section
         (void)iteracion(5,N,fptr5);//2000000//2000100
   }
}

  t2= omp_get_wtime();
   printf("tomo = (%lf) segundos\n",t2-t1); 
   for(int i=0;i<N;i++){
        fprintf(fptr, "%f\t %f\t  numero de thread:%d\n", t[i][0], w[i][0], 0);
    }

    for(int i=0;i<N;i++){
        fprintf(fptr1, "%f\t %f\t  numero de thread:%d\n", t[i][1], w[i][1], 1);
    }

    for(int i=0;i<N;i++){
        fprintf(fptr2, "%f\t %f\t  numero de thread:%d\n", t[i][2], w[i][2], 2);
    }

    for(int i=0;i<N;i++){
        fprintf(fptr3, "%f\t %f\t  numero de thread:%d\n", t[i][3], w[i][3], 3);
    }

    for(int i=0;i<N;i++){
        fprintf(fptr4, "%f\t %f\t  numero de thread:%d\n", t[i][4], w[i][4], 4);
    }

    for(int i=0;i<N;i++){
        fprintf(fptr5, "%f\t %f\t  numero de thread:%d\n", t[i][5], w[i][5], 5);
    }  
  
   fclose(fptr);
   fclose(fptr1);
   fclose(fptr2);
   fclose(fptr3);
   fclose(fptr4);
   fclose(fptr5);
   return (0);
   
   }
void iteracion(int numP,int N, FILE *x)
{
	fprintf(x, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
    double h,ab;
    double w0=0.5,a=0,b=2;
    int i;
    fprintf(x, "%f\t %f\n", a, w0);
    h=(b-a)/N;
    w[0][numP] = w0;
    t[0][numP] = a;
    for(i=0;i<N;i++){
        t[i][numP]=a+(h*i);
        w[i][numP]=w[i-1][numP]+h*(1+sqrt(t[i-1][numP]*t[i-1][numP]-w[i-1][numP]));
       } 
         }

//Area bajo la curva --> Threads, numero de operaciones, cache
//Euler --> usar el mismo numero de threads que en el primero, tambien el mismonumero de operaciones 
// El de la RAM es el de los arreglos, permanecen a la RAM hasta que 
//en w1 se añaden las operaciones, seno, coseno, 