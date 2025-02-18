/* 
 * race.c - demonstrates a race condition
 */
/* $begin race */
/* WARNING: This code is buggy! */
#include "csapp.h"
#define N 4

void *thread(void *vargp);

int main()
{
    pthread_t tid[N];
    int *arg; // Pointer to hold dynamically allocated memory

    for (int i = 0; i < N; i++) {
        arg = Malloc(sizeof(int));
        *arg = i;                 
        Pthread_create(&tid[i], NULL, thread, arg);
    }

    for (int i = 0; i < N; i++) {
        Pthread_join(tid[i], NULL);
    }

    exit(0);
}

/* Thread routine */
void *thread(void *vargp) 
{
    int myid = *((int *)vargp);  //line:conc:race:derefarg
    printf("Hello from thread %d\n", myid);
    Free(vargp); //free the allocated memory
    return NULL;
}
/* $end race */
