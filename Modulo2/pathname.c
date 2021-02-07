#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>

int num_archivos = 0;
char padre[] = "..";
char mismo[] = ".";

void RecorreDirectorio(char *path){
	DIR *directorio;
	struct dirent *arch;
	struct stat atributos;
	char nombredir[30];

	if((directorio=opendir(path)) == NULL){
		printf("\nNo se ha podido abrir el directorio %s",directorio);
		perror("Error en open");
	}
	else{
		while((arch=readdir(directorio)) != NULL){
			chdir(path);

			if(stat(arch->d_name,&atributos) < 0){
				printf("\nError %d al leer los atributos del archivo %s", errno, arch->d_name);
				perror("Error en open");
			}
			else{
				if(S_ISDIR(atributos.st_mode) && (strcmp(arch->d_name,padre) != 0) && (strcmp(arch->d_name,mismo) != 0)){
					sprintf(nombredir,"./%s",arch->d_name);
					printf(nombredir);
					RecorreDirectorio(nombredir);
					chdir("..");
				}
				else{
					if(S_ISREG(atributos.st_mode) && (atributos.st_mode & S_IXGRP) && (atributos.st_mode & S_IXOTH))
						num_archivos++;
				}
			}

		}
	}
}

int main(int argc, char *argv[]){
	struct dirent *fd;

	int permisos_antiguos, permisos_nuevos;

	if(argc != 2){
		printf("\nNo funciona asi compañero");
		exit(EXIT_FAILURE);
	}

	RecorreDirectorio(argv[1]);

	printf("\nNumero archivos: %d \n", num_archivos);

	return EXIT_SUCCESS;
}
