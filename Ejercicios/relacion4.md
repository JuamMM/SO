1. **Sea un Sistema Operativo que sólo soporta un directorio (es decir, todos los archivos existentes estarán al mismo nivel), pero permite que los nombres de archivo sean de longitud variable. Apoyándonos únicamente en los servicios proporcionados por este Sistema Operativo, deseamos construir una "utilidad" que "simule" un sistema jerárquico de archivos. ¿Es esto posible? ¿Cómo?**

Vamos a tomar como ejemplo los archivos A.txt ,B.txt y los directorios Uno y Dos. Como los nombres pueden ser de longitud variable para si deseamos indicar que el archivo A.txt se encuentra en el directorio Uno basta con cambiarle el nombre del archivo a Uno/A.txt. Ahora para simular que el archivo B.txt se encuentra en Dos que a su vez se encuentra en Uno realizaríamos los siguientes cambios de nombre: B.txt pasa a ser Uno/Dos/B.txt y Dos pasa a ser Uno/Dos.

2. **En un entorno multiusuario, cada usuario tiene un directorio inicial al entrar en el sistema a partir del cual puede crear archivos y subdirectorios. Surge, entonces, la necesidad de limitar el tamaño de este directorio para impedir que el usuario consuma un espacio de disco excesivo. ¿De qué forma el Sistema Operativo podría implementar la limitación de tamaño de un directorio?**

Es posible alterar el descriptor de archivo de los directorios para cambiar el tamaño máximo que puede alcanzar.

7. **Entre los posibles atributos de un archivo, existe un bit que marca un archivo como temporal y por lo tanto esta sujeto a destrucción automática cuando el proceso acaba ¿Cuál es la razón de esto? Después de todo un proceso siempre puede destruir sus archivos, si así lo decide.**

Un programa puede crear un archivo y bloquerarse o terminar forzosamente su ejecución sin llegar a la sección de código dónde se elimina el archivo. También aunque un proceso puede destruir sus archivos siempre es posible que se nos olvide añadir la línea de código para hacerlo, marcando un archivo como temporal nos aseguramos de que pase lo que pase dicho archivo desaparecerá.
