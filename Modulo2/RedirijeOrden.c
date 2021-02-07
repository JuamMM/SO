#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[]){
	int fd;

	if(argc != 4){
		printf("\nNo funciona asi compañero");
		exit(EXIT_FAILURE);
	}
	else{

		if(strcmp(argv[2],"<") == 0){

			if((fd=open(argv[3],O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR))<0){
				perror("Error");
				exit(EXIT_FAILURE);
				}

				dup2(fd,STDOUT_FILENO);
				dup2(fd,STDERR_FILENO);
				close(fd);

		}
		else{
			printf("\nDebe emplease > o <\n");
			exit(EXIT_FAILURE);
		}


		if(execlp(argv[1],argv[1],NULL) < 0){
			perror("\nFallo exec\n");
			exit(EXIT_FAILURE);
		}


		return EXIT_SUCCESS;
	}
}
