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

5. **Si se pierde el primer puntero de la lista de espacio libre, ¿podría el Sistema Operativo reconstruirla? ¿Cómo?**

Habria que buscar entre los bloque libres aquél que apunte a otro bloque pero no sea apuntado por ningún otro.

6. **El espacio libre en disco puede ser implementado usando una lista encadenada con agrupación o un mapa de bits. La dirección en disco requiere D bits. Sea un disco con B bloques, en que F están libres. ¿En qué condición la lista usa menos espacio que el mapa de bits?**

En el caso de mapa de bits este va a ocupar B bits, en la caso de la lista va a ocupar F * D bits luego siempre que F * D sea menor que B la lista encadenada ocupará menos espacio.

7. **Entre los posibles atributos de un archivo, existe un bit que marca un archivo como temporal y por lo tanto esta sujeto a destrucción automática cuando el proceso acaba ¿Cuál es la razón de esto? Después de todo un proceso siempre puede destruir sus archivos, si así lo decide.**

Un programa puede crear un archivo y bloquerarse o terminar forzosamente su ejecución sin llegar a la sección de código dónde se elimina el archivo. También aunque un proceso puede destruir sus archivos siempre es posible que se nos olvide añadir la línea de código para hacerlo, marcando un archivo como temporal nos aseguramos de que pase lo que pase dicho archivo desaparecerá.

8. **Algunos SO proporcionan una llamada al sistema (RENAME) para dar un nombre nuevo a un archivo existente ¿Existe alguna diferencia entre utilizar esta llamada para renombrar un archivo y copiar el archivo a uno nuevo, con el nuevo nombre y destruyendo el antiguo?**

La llamada RENAME conserva los enlaces duros y simbólicos del archivo.

9. **Un i-nodo de UNIX tiene 10 direcciones de disco para los diez primeros bloques de datos, y tres direcciones más para realizar una indexación a uno, dos y tres niveles. Si cada bloque índice tiene 256 direcciones de bloques de disco, cuál es el tamaño del mayor archivo que puede ser manejado, suponiendo que 1 bloque de disco es de 1KByte?**

Las primeras 10 direcciones apuntan a los 10 primeros bloques de datos luego tenemos un total de 10KB.
Como disponemos de indexación a 1,2 y3 niveles tenemos en total 256KB + 256^2KB + 256^3KB de espacio, en total: 16GB.

10. **Sobre conversión de direcciones lógicas dentro de un archivo a direcciones físicas de disco. Estamos utilizando la estrategia de indexación a tres niveles para asignar espacio en disco. Tenemos que el tamaño de bloque es igual a 512 bytes, y el tamaño de puntero es de 4 bytes. Se recibe la solicitud por parte de un proceso de usuario de leer el carácter número N de determinado archivo. Suponemos que ya hemos leído la entrada del directorio asociada a este archivo, es decir, tenemos en memoria los datos PRIMER- BLOQUE y TAMAÑO. Calcule la sucesión de direcciones de bloque que se leen hasta llegar al bloque de datos que posee el citado carácter.**

Como cada bloque almacena 512 bytes y un puntero son 4 bytes cada bloque puede almacenar un máximo de 128 punteros, es decir puede redireccionar 128 bloques.

N'   = N   % 512*128*128
N''  = N'  % 512*128
N''' = N'' % 512

Se leen un total de N'+N''+N''' bloques.

11. **¿Qué método de asignación de espacio en un sistema de archivos elegiría para maximizar la eficiencia en términos de velocidad de acceso, uso del espacio de almacenamiento y facilidad de modificación (añadir/borrar /modificar), cuando los datos son:**

**a) modificados infrecuentemente, y accedidos frecuentemente de forma aleatoria** Contiguo puesto que permite un acceso sencillo y rápido a los datos.

**b) modificados con frecuencia, y accedidos en su totalidad con cierta frecuencia** Enlazados ya que vamos a accederlos todos con frecuencia y al ser modificados frecuentemente vamos a tener que expandir su tamaño en ocasiones. Mediante los bloques libres del enlazado no sería necesaria compactación.

**c) modificados frecuentemente y accedidos aleatoriamente y frecuentemente** Indexado al ser modificados frecuentemente nos interesa poder aumentar su espacio de forma sencilla y como serán accedidos aleatoriamente nos interesa indexación que no ofrece un acceso directo más efectivo que el enlazado.

12. **¿Cuál es el tamaño que ocupan todas las entradas de una tabla FAT32 que son necesarias para referenciar los cluster de datos, cuyo tamaño es de 16 KB, de una partición de 20 GB ocupada exclusivamente por la propia FAT32 y dichos cluster de datos?**

Se asume que FAT32 es una lista enlazada, luego al ser 32b disponemos de 4B por entrada. Si tenemos 20GB sólo para la FAT y el cluster de datos eso quiere decir que 20GB = (4B+16KB)*nº entradas. Luego el número de entradas es igual a 20GB/(4B+16KB), lo que nos da un total de 1310400 entradas si cada entrada son 4B tenemos que ocupan un total de 5MB aproximadamente.

13. **Cuando en un sistema Unix/Linux se abre el archivo /usr/ast/work/f, se necesitan varios accesos a disco. Calcule el número de accesos a disco requeridos (como máximo) bajo la suposición de que el i-nodo raíz ya se encuentra en memoria y que todos los directorios necesitan como máximo 1 bloque para almacenar los datos de sus archivos.**

Sería necesario un acceso a disco para acceder al inodo y otro acceso a disco para cargar el único bloque de datos, luego tendríamos que leer el inodo de usr y luego su bloque, lo mismo para ast y work, es decir serían necesarios un total de 6 accesos a disco.
