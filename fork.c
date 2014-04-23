#include<stdlib.h>
#include<stdio.h>

int main(){
    //fork() crea una copia del programa, el padre se le devuelve el PID del hijo, el hijo tiene 0
    
    /** Ejemplo simple */
    printf("Proceso Padre PID %d\n", getpid());
    int f = fork();
    printf("%d\n",f);
    if(f){
        printf("Padre : %d\n", getpid());
    }
    else{
        printf("Hijo %d\n",getpid());
    }
    sleep(100);
    /**********************************/
    
    //ejemplo mas complejo de fork()
    //Comparte memoria, es decir la variable i se pasa en el sgte proceso, por lo cual se ejecutarian 8 procesos en total
    // Porque? A i=0, crea B desde la linea que llamo a fork y reincia iteracion con i=1, y asi sucesivamente
    // El fork arranca una copia del programa, compartiendo la memoria(algunos datos no todos) desde la linea en que se le llamo.
    /**
    *           A
    *         / | \
    *        B  C D
    *       |\  |
    *       E F G
    *       |
    *       H
    */
    int i;
    pid_t childpid;

    for(i=0; i<3; i++)
    {
        childpid = fork();
        if(childpid == -1)
        {
            perror("Failed to Fork");
            return 1;
        }

        if(childpid == 0)
            printf("You are in Child: %ld\n", (long)getpid());
        else
            printf("You are in Parent: %ld\n", (long)getpid());
    }
    return 0;
}
