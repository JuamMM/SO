#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

char buf1[80];
char bloque[30];

int main(int argc, char *argv[]){
	int fd_r, fd_w;
	int bytes;
	int numero = 1;

	if((fd_r=open(argv[1],O_RDONLY,S_IRUSR|S_IWUSR))<0){
		printf("\nError en open %d",errno);
		perror("\nError en  open");
		exit(EXIT_FAILURE);
	}

	if((fd_w=open("archivo",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR))<0){
		printf("\nError en open %d",errno);
		perror("\nError en  open");
		exit(EXIT_FAILURE);
	}

	while((bytes =read(fd_r,buf1,80))>0){
		sprintf(bloque, "\nBloque %d:\n",numero);
		write(fd_w, bloque, sizeof(bloque));

		write(fd_w,buf1,bytes);

		numero++;
	}

	write(fd_w,"\n",1);

	return EXIT_SUCCESS;
}
