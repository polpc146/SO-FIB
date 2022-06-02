#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main () {
    
    char buff[16];
    int fd, num;
    fd = open("foo.txt", O_RDONLY);
    read(fd, &num, sizeof(int));
    sprintf(buff, "%d\n", num);
    write(1, buff, strlen(buff));
}
