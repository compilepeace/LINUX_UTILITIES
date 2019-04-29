// Author : Abhinav Thakur
// Email  : compilepeace@gmail.com

#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "color.h"


char *get_timestamp()
{
	time_t current = time(NULL);
	
	return asctime(localtime (&current));
}


int main(int argc, char *argv[])
{
	int fd = 0;
	char buffer[100];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;


	if (argc < 2)
	{
		fprintf(stderr, RED"[-] "RESET"Usage: %s <filename> \n", argv[0]);
	}

	char *filename = argv[1];

	// Create file
	fd = open( filename, O_WRONLY | O_CREAT | O_APPEND , mode);

	sprintf(buffer, "Current time :"YELLOW" %s\n"RESET, get_timestamp());
	printf("Writing %s--> "MAGENTA"%s\n"RESET, buffer, filename);
	write(fd, buffer, strlen(buffer));

	close(fd);	

return 0;	
}

