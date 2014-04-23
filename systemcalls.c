/**
*   System calls UNIX:
*   Son funciones básicas ya definidas en el Kernel de Linux y que podemos usar para crear otros programas
*
*   open (*Path, flags) --> abre archivo o directorio
*   fstat() --> obtiene info de un archivo
*   Ejemplo:
*/
    int file=0;
    if((file=open("/path",O_RDONLY)) < -1)
        return 1;
    struct stat fileStat;
    if(fstat(file,&fileStat) < 0)    
        return 1;
    
/**
*   read(int fd, struct, size) avanza la posicion del archivo el tamaño de size.
*   memmove(destino, src, tam)  copia memoria
*/

