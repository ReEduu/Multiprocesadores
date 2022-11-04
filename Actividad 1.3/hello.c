    #include <stdio.h>
    #include "omp.h"
    #define NUM_THREADS 18
    int main()
    {
        omp_set_num_threads(NUM_THREADS);
        #pragma omp parallel
        {
            int ID = omp_get_thread_num();
            printf("Procesadores(%d)",ID);
            printf("Multiples(%d)",ID);
            printf("en accion(%d) --- %d\n",ID);
        }
    }

    
    //Los threads salen segun se liberan por el SO, por lo que son aleatorios 

    //Threads fisicos son de hardware, pero tambien hay virtuales, según el SO 
