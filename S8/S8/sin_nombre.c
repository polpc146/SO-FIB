#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char* argv[]) {
    
    char buff[256];
    int p[2];
    pipe(p);
    int pid = fork();
    if (pid == 0) {
        
        close(0);
        dup2(p[0],0);
        close(p[0]);
        close(p[1]);
        execlp("cat", "cat", (char*)0);
    }
    else {
        
        close(p[0]);
        sprintf(buff, "Inicio\n");
        write(p[1], buff, strlen(buff));
        close(p[1]);
        waitpid(-1, NULL, 0);
        sprintf(buff, "Fin\n");
        write(1, buff, strlen(buff));
    }
}
