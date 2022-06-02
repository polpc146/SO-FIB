#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void halt(char c[]) {
	perror(c);
	exit(0);
}

void Usage(void) {
	char buff[] = "Usage: ./insertarx2 [arg1, arg2, arg3]";
	write(1, buff, strlen(buff));
}

int main(int argc, char **argv) {
	if (argc < 2) Usage();
	else {
		int pos = atoi(argv[2]);
		char c;
		int fd1, ini;
		char buff[128];
		if ((fd1 = open(argv[1], O_RDWR)) < 0) halt("open");
		if (lseek(fd1, 0, SEEK_END) < 0) halt("lseek");

		//sprintf(buff, "%d\n", fi);
		//write(1, buff, strlen(buff));

		lseek(fd1, -1, SEEK_END);
		ini = -2;
		while (read(fd1, &c, sizeof(char) > 0)) {
			write(fd1, &c, sizeof(char));
			if (lseek(fd1, ini, SEEK_END) < 0) return 1;
			--ini;
			if (lseek(fd1, 0, SEEK_CUR) == pos) {
				write(fd1, "X", sizeof(char));
				return 0;
			}
		}
	}
}
