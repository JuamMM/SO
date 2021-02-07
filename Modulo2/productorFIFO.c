#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>

#define ARCHIVO_FIFO "ComunicacionFIFO"


int main(int argc, char *argv[]){
	int fd;

	if(argc != 2){
		printf("\nFalta un mensaje\n");
	}

	if((fd=open(ARCHIVO_FIFO,O_WRONLY)) <0 ){
		perror("open");
		exit(EXIT_FAILURE);
	}

	if(write(fd,argv[1],strlen(argv[1])+1) != strlen(argv[1])+1){
		perror("\nError al escribir en el fifo");
		return EXIT_FAILURE;
	}

	close(fd);

	return EXIT_SUCCESS;
}

