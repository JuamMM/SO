1. **Sea un Sistema Operativo que sólo soporta un directorio (es decir, todos los archivos existentes estarán al mismo nivel), pero permite que los nombres de archivo sean de longitud variable. Apoyándonos únicamente en los servicios proporcionados por este Sistema Operativo, deseamos construir una "utilidad" que "simule" un sistema jerárquico de archivos. ¿Es esto posible? ¿Cómo?**

Vamos a tomar como ejemplo los archivos A.txt ,B.txt y los directorios Uno y Dos. Como los nombres pueden ser de longitud variable para si deseamos indicar que el archivo A.txt se encuentra en el directorio Uno basta con cambiarle el nombre del archivo a Uno/A.txt. Ahora para simular que el archivo B.txt se encuentra en Dos que a su vez se encuentra en Uno realizaríamos los siguientes cambios de nombre: B.txt pasa a ser Uno/Dos/B.txt y Dos pasa a ser Uno/Dos.

2. **En un entorno multiusuario, cada usuario tiene un directorio inicial al entrar en el sistema a partir del cual puede crear archivos y subdirectorios. Surge, entonces, la necesidad de limitar el tamaño de este directorio para impedir que el usuario consuma un espacio de disco excesivo. ¿De qué forma el Sistema Operativo podría implementar la limitación de tamaño de un directorio?**

Es posible alterar el descriptor de archivo de los directorios para cambiar el tamaño máximo que puede alcanzar.

3. **En la siguiente figura se representa una tabla FAT. Al borde de sus entradas se ha escrito, como ayuda de referencia, el número correspondiente al bloque en cuestión. También se ha representado la entrada de cierto directorio. Como simplificación del ejemplo, suponemos que en cada entrada del directorio se almacena: Nombre de archivo/directorio, el tipo (F=archivo, D=directorio), la fecha de creación y el número del bloque inicial.**

**Tenga en cuenta que:**

- **el tamaño de bloque es de 512 bytes**

- **el FIN indica último bloque**

- **todo lo que está en blanco en la figura está libre.**

**a) Creación del archivo DATOS1 con fecha 1-3-90, y tamaño de 10 bytes.**

**b) Creación del archivo DATOS2 con fecha 2-3-90, y tamaño 1200 bytes.**

**c) El archivo DATOS aumenta de tamaño, necesitando 2 bloques más.**

**d) Creación del directorio D, con fecha 3-3-90, y tamaño 1 bloque.**

**e) Creación del archivo CARTAS con fecha 13-3-90 y tamaño 2 kBytes.**

**Importante** en la relación de ejercicios original hay un erro y datos aparecen en el bloque 2 cuando debería aparecer en el 3, aquí se ha corregido. Los datos de las tablas en negrita son aquellos que se daban con el ejercicio.

|Nombre|Tipo|Fecha|Nº Bloque|
|-|-|-|-|
| **DATOS** | **F** | **8-2-90** | **3** |
| DATOS1 | F | 1-3-90 |1|
| DATOS2 | F | 2-3-90 |2|
| D | D | 3-3-90 |6|
| CARTAS | F | 13-3-90 |7|

|Nº bloque|referencia|Nº bloque|referencia|
|-|-|-|-|
| **1** | FIN | **10**| FIN |
| **2** | 4 | **11**| |
| **3** |15 | **12**| |
| **4** | 5 | **13**| |
| **5** | FIN | **14**| |
| **6** | FIN | **15**|16 |
| **7** | 8 | **16**|17 |
| **8** | 9 | **17**|FIN |
| **9** |10 | **18**| |

4. **Si usamos un Mapa de Bits para la gestión del espacio libre, especifique la sucesión de bits que contendría respecto a los 18 bloques del ejercicio anterior.**

|1|1|1|1|1|1|1|1|1|1|0|0|0|0|1|1|1|0|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|

7. **Entre los posibles atributos de un archivo, existe un bit que marca un archivo como temporal y por lo tanto esta sujeto a destrucción automática cuando el proceso acaba ¿Cuál es la razón de esto? Después de todo un proceso siempre puede destruir sus archivos, si así lo decide.**

Un programa puede crear un archivo y bloquerarse o terminar forzosamente su ejecución sin llegar a la sección de código dónde se elimina el archivo. También aunque un proceso puede destruir sus archivos siempre es posible que se nos olvide añadir la línea de código para hacerlo, marcando un archivo como temporal nos aseguramos de que pase lo que pase dicho archivo desaparecerá.



