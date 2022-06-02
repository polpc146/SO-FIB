#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void error_y_exit (char* msg, int error_status) {
    
    perror (msg);
    exit(error_status);
}

int main (int argc, char* argv[]) {
    
    char buff[2];
    int fd, ret;
    if ((fd = open ("salida.txt", O_RDWR)) < 0) error_y_exit ("error al abrir el archivo", 1);
    lseek(fd, -1, SEEK_END);
    ret = read (fd, buff, 2*sizeof(char));
    lseek (fd, -1, SEEK_END);
    write (fd, "X", sizeof(char));
    write (fd, buff, ret);
}
