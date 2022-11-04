#include <stdio.h>
#include <omp.h>
#include <math.h>

static long num_pasos = 100;
double delta;

#define NUM_THREADS 6

int main(){

    int i, nthreads;
    double pi, resultado[NUM_THREADS],t1,t2,tiempo;
    delta = 1.0/num_pasos;
    omp_set_num_threads(NUM_THREADS);
    t1= omp_get_wtime();
    #pragma omp parallel
    {
        int i,id,nthrds;
        double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
    //printf("%d\n",id);
        if (id == 0) nthreads = nthrds;
        for(i = id, resultado[id]=0.0; i < num_pasos;i = i+nthrds){
        x = (i+0.5)*delta;
        printf("%f\n",x);
        resultado[id] += 4.0/(1.0+pow(x,2));
        } 
    }

    for(i=0,pi=0.0;i<nthreads;i++){
        pi+=resultado[i]*delta;
    }
    t2= omp_get_wtime();
    tiempo = t2 - t1;
    printf("pi = (%lf)\n",pi);
    printf("tomo = (%lf) segundos\n",tiempo);
    return 0;
} 


