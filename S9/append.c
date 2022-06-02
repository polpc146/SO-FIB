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
    
    char buff[256];
    int fd, ret;
    if ((fd = open("file", O_RDWR)) < 0) error_y_exit ("error en open", 1);
    while ((ret = read(fd, buff, sizeof(buff))) > 0) {
        
        lseek(fd, 0, SEEK_END);
        write(fd, buff, strlen(buff));
    }
}
