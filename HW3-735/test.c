#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    #pragma omp parallel
    {
    int np = omp_get_num_threads();
    int myid = omp_get_thread_num();
    if (myid == 0)
        printf("I am master of %d threads\n", np);
    else
        printf("I am thread # %d\n", myid );
    }

    int i = 0;
    int id;
    #pragma omp parallel for private(i, id)
    for(i = 0; i < 4; i++){
        int id = omp_get_thread_num();
        printf("LOOP: thread # %d\n", id);
    }

    printf("Done with parallel region\n");
}