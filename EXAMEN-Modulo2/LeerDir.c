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

/*
 * Juan Mota Martínez
 */

int main(int argc, char *argv[]){
	int fd;
	int arch_leidos;
	int n = 1;
	DIR *directorio;
	struct dirent *arch;
	struct stat atributos;

	if(argc != 2){
		printf("Es necesario suministrar un pathname");
		exit(EXIT_FAILURE);
	}
	else{
		char *path = argv[1];
		int bytes = 80;

		/*
		 * Creamos el archivo
		 */

		if((fd=open("archivoEnlace",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP))<0){
				perror("Error");
				exit(EXIT_FAILURE);
			}

		printf("\nIntroduce un valor: ");
		scanf("%d",&n);

		while(n != 0){
			arch_leidos = 0;

			/* Comprobamos que el directorio no es nulo y accedemos a leer sus archivos*/

			if((directorio=opendir(path)) == NULL){
				perror("\nError en open directorio\n");
				exit(EXIT_FAILURE);
			}

			/*Mientras el número de archivos leidos sea menor que n seguimos buscando*/
			while(((arch=readdir(directorio)) != NULL) && (arch_leidos<n)){

				arch_leidos++;
				chdir(path);

				if(stat(arch->d_name,&atributos) < 0){
					perror("Error en open stat");
					exit(EXIT_FAILURE);
				}

				if(arch_leidos == n){
					/*
					 * Imprimimos
					 */
					printf("\nNombre: %s",arch->d_name);
					printf("\nNumero de enlaces duros: %i",atributos.st_nlink);
					printf("\nTamaño: %d",atributos.st_size);
					printf("\nTipo: %i",atributos.st_mode);
					rewinddir(directorio);
					closedir(directorio);
					chdir("..");
				}
				else{
					/*
					 * Guardamos en el archivo si se da la condicion
					 */
					if(atributos.st_nlink > 1){
						write(fd,arch->d_name,bytes);
						write(fd,"\n",1);
					}

				}

			}


			printf("\nIntroduce un valor: ");
			scanf("%d",&n);

		}

		printf("\nHas introducido %d, Cerrando... \n",n);
		return EXIT_SUCCESS;

	}
}
