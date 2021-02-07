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
	int pipefd[2];
	int n = 1,c;
	pid_t pid1, pid2;

	if(argc != 2){
		printf("Es necesario suministrar un pathname");
		exit(EXIT_FAILURE);
	}
	else{
		char *path = argv[1];
		int bytes = 80;

		pipe(pipefd);

		/*
		 * Creamos el primer proceso Hijo
		 */
		pid1 = fork();

		/*
		 * Comprobamos que somos el padre y creamos el segundo
		 */

		if(pid1 == 0){
			while(n>0 && n<10){
				/*Cerramos el cauce de lectura para el segundo hijo */
				close(pipefd[0]);

				printf("\nIntroduce un valor: ");
				scanf("%d",&n);

				/*Escribimos el valor en el cauce*/
				write(pipefd[1],n,1);
			}
		}
		else{

			pid2 = fork();

			if(pid2 == 0){

				/*Cerramos el cauce de lectura para el primer hijo*/
				close(pipefd[1]);

				/* No he conseguido que esta parte se ejecute y no sé el problema pero el ejericio debería leer el cauce realizar la ejecución de la orde
			 	* con lo leído como argumento y esperar a que se mande otro.
			 	*/
				read(pipefd[0],c,1);
				printf(c);

				if(c!=0){
					char *argumento = c;
					execlp("./LeerDir",argumento,NULL);
					c = 0;
				}
			}
		/*Esperamos a que los hijos terminen de ejecutarse*/

			if(pid2 != 0){
				waitpid(pid1);
				waitpid(pid2);
				printf("Completada ejecucion\n");
			}
			exit(EXIT_SUCCESS);
		}




	}
}
