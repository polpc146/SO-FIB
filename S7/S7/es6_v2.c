#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

void func (int signal) {
    
    char buff[128];
    sprintf(buff, "signal recibido\n");
    write (1, buff, strlen(buff));
}

int
main ()
{
    
  struct sigaction sa;
  sa.sa_handler = &func;
  sigfillset(&sa.sa_mask);
  sigaction(SIGINT, &sa, NULL);
  char c;
  char buff[128];

  int ret = read (0, &c, sizeof (char));
  if (ret >= 0) {
      
      sprintf(buff, "read correcto\n");
      write (1, buff, strlen(buff));
        write (1, &c, sizeof (char));
  }
  else {
      
      if (errno == EINTR) {
			sprintf(buff, "read interrumpido por signal\n");
			write(1,buff,strlen(buff));
		} else {
			sprintf(buff, "read con error\n");
			write(1,buff,strlen(buff));
		}
  }
}
