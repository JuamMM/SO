1. **Si un computador no posee hardware de reubicación, e implementa intercambio (swapping), entonces el gestor de memoria necesita utilizar un cargador para recalcular las direcciones físicas de un proceso. ¿Sería posible para el sistema de intercambio reubicar los segmentos de datos y pila? Explica cómo funcionaría este sistema, o si es imposible que funcione.**

El cargador deberá encargarse de escribir los datos modificados y la pila en memoria secundaria cuando sea necesario desalojar el proceso.

2. **Considere un sistema con un espacio lógico de memoria de 128K páginas (máximo espacio de memoria virtual) con 8 KB cada una, una memoria física de 64 MB y direccionamiento al nivel de byte. ¿Cuántos bits hay en la dirección lógica? ¿Y en la física?**

83 bits la dirección lógica (128K = 2^7*2^10, 8K = 2^3+2^10 = 2^83b)

13 bits para la dirección física (64MB = 2^6*2^10*2^10, 8KB = 2^3*2^10, dividimos y obtenemos 2^6*2^7 = 2^13b).

3. **Considérese un sistema con memoria virtual en el que el procesador tiene una tasa de utilización del 15% y el dispositivo de paginación está ocupado el 97% del tiempo, ¿qué indican estas medidas? ¿Y si con el mismo porcentaje de uso del procesador el porcentaje de uso del dispositivo de paginación fuera del 15%?**

Nos indica que el procesador dedica mucho tiempo a resolver faltas de página.

En este caso habría pocos procesos en la cola.

4. **Sea un sistema de memoria virtual paginada con direcciones lógicas de 32 bits que proporciona un espacio virtual de 2^20 páginas y con una memoria física de 32 Mbytes ¿cuánta memoria requiere en total un proceso que tenga 453Kbytes, incluida su tabla de páginas cuyas entradas son de 32 bits?**

se requieren 20 bits para las páginas luego el tamaño de página es 2^12B = 4096B si tenemos 453KB = 453*2^10B. 453B/2^2B = 114 páginas = 3648b.

5. **Un ordenador tiene 4 marcos de página. En la siguiente tabla se muestran: el tiempo de carga, el tiempo del último acceso y los bits R y M para cada página (los tiempos está en tics de reloj). Responda a las siguientes cuestiones justificando su respuesta.**

|Página|Tiempo de carga| Tiempo ultima referencia | bit de referencia | bit de modificación |
|------|---------------|--------------------------|-------------------|---------------------|
|0|126|279|1|0|
|1|230|235|1|0|
|2|120|272|1|1|
|3|160|200|1|1|
|-|-|-|-|-|

**a) ¿Qué pagina se sustituye si se usa el algoritmo FIFO?**

La 1 puesto que FIFO reemplaza la más antigua y esta lleva 230 ticks desde que fue cargada.

**b) ¿Qué página se sustituye si se usa el algoritmo LRU?**

Se sustituiría la página 0 puesto que esta due referenciada hace más tiempo.

6. **¿Depende el tamaño del conjunto de trabajo de un proceso directamente del tamaño del programa ejecutable asociado a él? Justifique su respuesta.**

No puesto que el conjutno de trabajo varía durante su ejecución, al inicio de la vida del programa puede que tan sólo sean necesarias las páginas 1 y 2, mientras que al final del mismo se requieran: 0, 2, 4, 5. El tamaño del conjunto de trabajo depende exclusivamente del la sección que se esté ejecutando en ese momento.

7. **¿Por qué una cache (o la TLB) que se accede con direcciones virtuales puede producir incoherencias y requiere que el sistema operativo la invalide en cada cambio de contexto y, en cambio, una que se accede con direcciones físicas no lo requiere?**

Puesto que al trabajar con direcciones virtuales, estamo trabajando esencialmente sobre copias de recursos ubicados en memoria secundaria, si alteramos alguno de estos recursos y decidimos desalojar la página de memoria principal debemos guardar la los cambios realizados sobre la copia en memoria secundaria también. Cuando trabajmos sobre direcciónes físicas los cambios se realizan directamente sobre los datos originales y se modifican sobre memoria secundaria.

8. **Un ordenador proporciona un espacio de direccionamiento lógico (virtual) a cada proceso de 65536 bytes de espacio dividido en páginas de 4096 bytes. Cierto programa tiene un tamaño de región de texto de 32768 bytes, un tamaño de región de datos de 16386 bytes y tamaño de región de pila de 15878. ¿Cabría este programa en el espacio de direcciones? (Una página no puede ser utilizada por regiones distintas). Si no es así, ¿cómo podríamos conseguirlo, dentro del esquema de paginación?**

Como tenemos 65536B y páginas de 4096B tenemos un total de 16 páginas en memoria virtual.

32768/4096 = 8, luego la región de texto ocupa 8 páginas.

16386/4096 = 4.0004 luego la región de texto datos de 5 páginas.

15878/4096 = 3.87 ergo 4 páginas.

En total se requieren de 17 y tan sólo tenemos 16, no es posible albergar toda la totalidad del programa en el esquema de paginación. Sería posible si reducimos el tamaño de las páginas como se ha visto la región de datos ocupa una ínfima parte de su última página, la cuál podría emplearse para albergar la región de pila.

9. **Analice qué puede ocurrir en un sistema que usa paginación por demanda si se recompila un programa mientras se está ejecutando. Proponga soluciones a los problemas que pueden surgir en esta situación.**

Puede que una de las páginas que se están empleando se vean alteradas, de forma que cuando la copia que se guarda en memoria principal se devuelva a memoria secundaria no se corresponda con la nueva recompilación.

10. **Para cada uno de los siguientes campos de la tabla de páginas, se debe explicar si es la MMU o el sistema operativo quién los lee y escribe (en éste último caso si se activa o
desactiva), y en qué momentos:**

**a) Número de marco**  MMU

**b) Bit de presencia** MMU

**c) Bit de protección** SO

**d) Bit de modificación** MMU

**e) Bit de referencia** MMU


11. **Suponga que la tabla de páginas para el proceso actual se parece a la de la figura. Todos los números son decimales, la numeración comienza en todos los casos desde cero, y todas las direcciones de memoria son direcciones en bytes. El tamaño de página es de 1024 bytes.**

|Número de página virtual|Bit de presencia|Bit de refencia|Bit de modificación|Número de marco de página|
|-|-|-|-|-|
|0|0|1|0|4|
|1|1|1|1|7|
|2|1|0|0|1|
|3|1|0|0|2|
|4|0|0|0|X|
|5|1|0|1|0|

**¿Qué direcciones físicas, si existen, corresponderán con cada una de las siguientes direcciones virtuales? (no intente manejar ninguna falta de página, si las hubiese)**

**a) 999** Se encuenta en la página 0 pero al no estar presente en memoria principal no tiene traducción a memoria física.

**b) 2121** Se encuentra en el marco 7, luego 7*1024+1095 = 8263.

**c) 5400** Está en la página 5 luego marco 0 y su desplazamiento es 280, lo que equivale a su dirección física.

12. **Sea la siguiente secuencia de números de página referenciados: 1,2,3,4,1,2,5,1,2,3,4,5 Calcula el número de faltas de página que se producen utilizando el algoritmo FIFO y considerando que el número de marcos de página de que disfruta nuestro proceso es de**

**a) 3 marcos**

|1|2|3|4|1|2|5|1|2|3|4|5|
|-|-|-|-|-|-|-|-|-|-|-|-|
|1|1|1|4|4|4|5|5|5|5|5|5|
| |2|2|2|1|1|1|1|1|3|3|3|
| | |3|3|3|2|2|2|2|2|4|4|
|X|X|X|X|X|X|X| | |X|X| |

9 faltas de página

**a) 4 marcos**

|1|2|3|4|1|2|5|1|2|3|4|5|
|-|-|-|-|-|-|-|-|-|-|-|-|
|1|1|1|1|1|1|5|5|5|5|4|4|
| |2|2|2|2|2|2|1|1|1|1|5|
| | |3|3|3|3|3|3|2|2|2|2|
| | | |4|4|4|4|4|4|3|3|3|
|X|X|X|X| | |X|X|X|X|X|X|

10 faltas de página.

**¿Se corresponde esto con el comportamiento intuitivo de que disminuirá el número de faltas de página al aumentar el tamaño de memoria de que disfruta el proceso?**

No puesto que el problema no es la memoria sino el algoritmo de sustitución.

13. **¿Por qué la localidad no es un factor que se tiene en cuenta en los sistemas con segmentación?**

Porque la memoria virtual no se agrupa contiguamente en el caso de segmentación, luego no podemos basarnos en la cercanía para tratar de averiguar que sección se ejecutará después.

14. **En la gestión de memoria en un sistema paginado, ¿qué estructura/s de datos necesitará mantener el Sistema Operativo para administrar el espacio libre?**

Se deberá emplear una estructura de datos que sirva de representación de las páginas, y nos indique dónde están ubicadas, y si son limpias o sucias.

15. **¿Cuánto puede avanzar como máximo la aguja del algoritmo de reemplazo de páginas del reloj durante la selección de una página?**
Hasta da una vuelta completa y volver a la primera página que se comprobó, es decir, supongamos que es la primera vez que ejecutamos el algoritmo, en este caso todas las páginas tienen su bit de referencia (R) a 1. Conforme la recorra irá modificando R para que valga 0 pero deberá recorré todas las páginas.

16. **Situándonos en un sistema paginado, donde cada proceso tiene asignado un número fijo de marcos de páginas. Supongamos la siguiente situación: existe un proceso con 7 páginas y tiene asignados 5 marcos de página. Indica el contenido de la memoria después de cada referencia a una página si como algoritmo de sustitución de página utilizamos el LRU (la página no referenciada hace más tiempo). La secuencia de referencias es la indicada en la figura.**

|2|1|3|4|1|5|6|4|5|7|4|2|
|-|-|-|-|-|-|-|-|-|-|-|-|
|2|2|2|2|2|2|6|6|6|6|6|6|
| |1|1|1|1|1|1|1|1|1|1|2|
| | |3|3|3|3|3|3|3|7|7|7|
| | | |4|4|4|4|4|4|4|4|4|
| | | | | |5|5|5|5|5|5|5|
|X|X|X|X| |X|X| | |X| |X|

Se producen 8 faltas de página.

17. **¿Cuál es la ventaja del algoritmo de faltas de página sobre el algoritmo basado en el modelo del conjunto de trabajo utilizando el tamaño de ventana w? ¿Cuál es la desventaja?**

FFP elimina aquellas páginas que no se referenciasen en el intervalo entre la actual falta de página, luego mientras no se produzcan faltas de página FFP no eliminará ningna página al contrario que WS. Sin embargo si se producen 2 faltas de página en un intervalo de tiempo pequeño FFP eliminará una gran cantidad de páginas.

18. **Supongamos que tenemos un proceso ejecutándose en un sistema paginado, con gestión de memoria basada en el algoritmo de sustitución frecuencia de faltas de página. El proceso tiene 5 páginas ( 0, 1, 2, 3, 4 ). Represente el contenido de la memoria real para ese proceso (es decir, indique que páginas tiene cargadas en cada momento) y cuándo se produce una falta de página. Suponga que, inicialmente, está cargada la página 2, el resto de páginas están en memoria secundaria y que no hay restricciones en cuanto al número de marcos de página disponibles. La cadena de referencias a página es: 0 3 1 1 1 3 4 4 2 2 4 0 0 0 0 3 y el parámetro es τ=3.**

|0|3|1|1|1|3|4|4|2|2|4|0|0|0|0|3|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|2|3|3|3|3|3|3|3|2|2|2|2|2|2|2|3|
|0|0|1|1|1|1|1|1| | | |0|0|0|0|0|
| | | | | | |4|4|4|4|4|4|4|4|4| |
|X|X|X| | | |X| |X| | |X| | | |X|
