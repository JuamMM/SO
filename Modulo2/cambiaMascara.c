#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>


int main(int argc, char *argv[]){
	int fd_1, fd_2;
	struct stat atributos;

	if((fd_1=open("archivo1",O_CREAT|O_TRUNC|S_IRUSR|S_IWUSR))<0){
		printf("\nError en open %d",errno);
		perror("\nError en  open");
		exit(EXIT_FAILURE);
	}

	umask(0);

	if((fd_2=open("archivo2",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR))<0){
		printf("\nError en open %d",errno);
		perror("\nError en  open");
		exit(EXIT_FAILURE);
	}

	if(stat("archivo1",&atributos)<0){
		printf("\nError al intentar acceder a los atributos del archivo\n");
		perror("\nError en lstat");
		exit(EXIT_FAILURE);
	}

	if(chmod("archivo1",(atributos.st_mode & ~S_IXGRP) | S_ISGID) < 0){
		perror("\nError en chmod para archivo1");
		exit(EXIT_FAILURE);
	}
	if(chmod("archivo2",S_IRWXU | S_IRGRP | S_IWGRP | S_ISGID) < 0){
		perror("\nError en chmod para archivo2");
		exit(EXIT_FAILURE);
	}

	close(fd_1);
	close(fd_2);


	return EXIT_SUCCESS;
}
