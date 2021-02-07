#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>

char buf1[]="abcdefghij";
char buf2[]="12345678910";

int main(int argc, char *argv[]){
	int fd;
	if((fd=open("archivo",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR))<0){
		printf("\nError en open",errno);
		perror("\nError en  open");
		exit(EXIT_FAILURE);
	}
	write(fd,buf1,10);
	lseek(fd,40,SEEK_SET);
	write(fd,buf2,10);

	return EXIT_SUCCESS;
}
