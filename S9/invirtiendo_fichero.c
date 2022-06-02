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
    
    char c;
    int fd, ret, fi, cr;
    if ((fd = open("file", O_RDONLY)) < 0) error_y_exit ("error en open", 1);
    if ((fi = lseek(fd, 0, SEEK_END)) < 0) error_y_exit ("error en lseek", 1);
    int ini = 1;
    if ((cr = creat("file.out", O_CREAT|O_TRUNC|0600)) < 0) error_y_exit ("error en creat", 1);
    lseek(fd, -ini, SEEK_END);
    while((ret = read(fd, &c, 1)) > 0) {
        
        write (cr, &c, 1);
        ++ini;
        if(lseek(fd, -ini, SEEK_END) < 0) return 1;
    }
}
