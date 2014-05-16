#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

int contador;
sem_t semA,semB,semC,semBB;

void * imprimirA()
{
    while(1)
    {
        sem_wait(&semA);
        printf("A\n");
        sleep(1);
        sem_post(&semB);
        sem_post(&semB);
    }
}

void * imprimirB()
{
    while(1)
    {
        sem_wait(&semB);
        printf("B\n");
        sleep(1);
        int vB;
        sem_getvalue(&semB,&vB);
        if(vB==0) {
            sem_post(&semC);
            sem_post(&semC);
            sem_post(&semC);
        }
    }
}

void * imprimirC()
{
    while(1)
    {
        sem_wait(&semC);
        printf("C\n");
        sleep(1);
        int vC;
        sem_getvalue(&semC,&vC);
        if(vC==0) sem_post(&semA);
    }
}
 
int main()
{
    contador = 0;

    pthread_t tA,tB,tC;
    pthread_t thread_productor;

    sem_init(&semA, 0, 1);
    sem_init(&semB, 0, 0);
    sem_init(&semC, 0, 0);

    pthread_create(&tA, NULL, imprimirA, NULL);
    pthread_create(&tB, NULL, imprimirB, NULL);
    pthread_create(&tC, NULL, imprimirC, NULL);

    sleep(3000);
 
    return 0;
}

