#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>


int main(void){
	int fd;
	char buffer[80];
	int leidos;

	mkfifo(ARCHIVO_FIFO,06666);
	if((fd=open(ARCHIVO_FIFO,O_RDWR)) <0 ){
		perror("open");
		exit(EXIT_FAILURE);
	}

	while(1){
		leidos(read(fd,buffer,80));
		if(strcmp(buffer,"fin") == 0){
			close(fd);
			return(EXIT_SUCCESS);
		}
	}


	return EXIT_SUCCESS;
}
