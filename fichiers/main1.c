#include <stdio.h>   
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h>  
#include <string.h>  
#include <sys/ioctl.h>
#include <stdint.h> 
#include "serie.h"

int main(int argc, char **argv)
{
    char buffer[100];                   // un buffer
    int manet;

    // ouverture du port à 115200 bauds
    int fd = serialport_init("/dev/ttyUSB0", 9600);
    if (fd==-1) return -1;

    // boucle
    for ( ; ; ){
        //  lecture d'une ligne
        serialport_read_until(fd, buffer, '\r', 99, 10000);

        // suppression de la fin de ligne
        for (manet=0 ; buffer[manet]!='\r' && manet<100 ; manet++);
        buffer[manet] = 0;

        // écriture du résultat
        printf("%s", buffer);
    }

    // fermeture du port
    serialport_flush(fd);
    serialport_close(fd);

    return 0;
}
