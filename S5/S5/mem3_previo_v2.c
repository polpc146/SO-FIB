#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define REGION_SIZE		4096

int *p;

void func (int signal) {
    
    char buff[256];
    sprintf(buff, "Violación de segmento\n");
    write(1, buff, strlen(buff));
    exit(0);
}

int
main (int argc, char *argv[])
{
    
  struct sigaction sa;
  sa.sa_handler = &func;
  sa.sa_flags = 0;
  sigfillset(&sa.sa_mask);
  sigaction(SIGSEGV, &sa, NULL);
  char buff[256];

  sprintf (buff, "Addresses:\n");
  write (1, buff, strlen (buff));
  sprintf (buff, "\tp: %p\n", &p);
  write (1, buff, strlen (buff));

  *p = 5;

  sprintf (buff, "\tp Address: %p, p value: %p, *p: %d\n", &p, p, *p);
  write (1, buff, strlen (buff));

  exit (0);

}
