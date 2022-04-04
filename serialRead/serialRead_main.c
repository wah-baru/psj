#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void openFile(void);
void readFile(void);
int fd = 0;		//file descriptor

void readFile(void)
{
	unsigned char ichar;
	unsigned char dataread[2];
	//int i;
	int ifd;
	while (1)
	{
		ifd = read(fd, &ichar, 1);
		printf("%d\n", ichar);
		if (ichar == 343)
		{
			printf("Data pertama (1): ");
			ifd = read(fd, &dataread, 2);
			printf("%.2x%.2x\n", dataread[0], dataread[1]);
		}

		if (ichar == 512)
		{
			printf("Data kedua (2): ");
			ifd = read(fd, &dataread, 2);
			printf("%.2x%.2x\n", dataread[0], dataread[1]);
		}

		if (ichar == 729)
		{
			printf("Data ketiga (3): ");
			ifd = read(fd, &dataread, 2);
			printf("%.2x%.2x\n", dataread[0], dataread[1]);
		}

		sleep(1);
	}

	close(fd);
}

void openFile(void)
{
	if ((fd = open("/dev/ttyACM0", O_RDONLY)) < 0)
	{
		perror("Error Open File");
		exit(1);
	}
}

int main()
{
	openFile();
	readFile();
	return 0;
}