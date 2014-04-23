/**
*   Estado de los procesos:
*       zombie : si el hijo muere y el padre no se entera, una forma de verlo es con este programa
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int pid;

     /* let's create a child process */
    pid = fork();
    if (!pid) {
         /* this is a child: dies immediately and becomes zombie */
        exit(0);
    }

     /* parent process: just asks for the user input */
     printf("Please, press enter after looking at the zombie process...");
     (void)getchar();
}
/**
*   Sin ingresar ningun dato ver los procesos ps aux
*   El hijo muere inmediatamente pero el padre no se entera, o no sabe como reaccionar
*   Entonces el proceso hijo se vuelve zombie
*/
