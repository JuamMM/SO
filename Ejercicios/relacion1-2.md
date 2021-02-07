1. **Cuestiones sobre procesos, y asignación de CPU:**

**a)¿Es necesario que lo último que haga todo proceso antes de finalizar sea una llamada al sistema para finalizar? ¿Sigue siendo esto cierto en sistemas monoprogramados?**

Es obligatorio que todo proceso indique que ha finalizado para que el SO pueda sustituirlo por otros procesos que requieran ejecutarse y realizar las tareas de limpieza propias cuando un proceso termina. En sistemas monoprogramados también para informar sobre la finalización del uso de la CPU.

**b)Cuando  un  proceso  se  bloquea,  ¿deberá  encargarse  él  directamente  de  cambiar  el valor de su estado en el descriptor de proceso o PCB?**

Cuando un proceso se bloquea el SO se encarga de alterar sus valores.

**c)¿Qué  debería  hacer  el  planificador  a  corto  plazo  cuando  es  invocado  pero  no  hay ningún proceso en la cola de ejecutables?**

---

**d)¿Qué algoritmos de planificación quedan descartados para ser utilizados en sistemas de tiempo compartido?**

Cualquier algoritmo no apropiativo no puede ser empleado en sistemas de tiempo compartido, ya que podríamos tener usuarios incapaces de acceder a recursos durante grandes periodos de tiempo.

2. **La representación gráfica del cociente [(tiempo_en_cola_ejecutables + tiempo_de_CPU) / tiempo_de_CPU ] frente a tiempo_de_CPU suele mostrar valores muy altos para ráfagas muy cortas en casi todos los algoritmos de asignación de CPU. ¿Por qué?**

Para ráfags muy cortas, los procesos han de pasar mucho tiempo esperando en la cola de ejectutables y muy poco tiempo ejecutando, luego es normal que el cociente sea elevado.


3. **Para cada una de las llamadas al sistema siguientes, especificar y explicar si su procesamiento por el sistema operativo requiere la invocación del planificador a corto plazo:**

	a) **Crear un proceso.**  No, si acaba de cerase no puede encontrase en la cola de ejecutables

	b) **Abortar un proceso, es decir, terminarlo forzosamente.** Sí, puesto que es necesario saber que proceso va a ejecutarse a continuación.

	c) **Suspender o bloquear un proceso.** Sí, ya que es necasaro saber quién lo va a sustituir.

	d) **Reanudar un proceso (inversa al caso anterior).** Es posible que que el proceso deba ejecutarse justo después de reanudarse.

	e) **Modificar la prioridad de un proceso.** Si, al igual que en el caso anterior es necesario puesto que la nueva prioridad puede causar que deje de ejecutarse o pase a ejecutarse.

4. **Sea un sistema multiprogramado que utiliza el algoritmo Por Turnos (Round-Robin). Sea S el tiempo que tarda el despachador en cada cambio de contexto. ¿Cuál debe ser el valor de quantum Q para que el porcentaje de uso de la CPU por los procesos de usuario sea del 80%?**

8*s.

5. **Sea un sistema multiprogramado que utiliza el algoritmo Por Turnos (Round-Robin). Sea S el tiempo que tarda el despachador en cada cambio de contexto, y N el número de procesos existente. ¿Cuál debe ser el valor de quantum Q para que se asegure que cada proceso “ve” la CPU al menos cada T segundos?**

Q = T/(N-1) -S.

6. **¿Tiene sentido mantener ordenada por prioridades la cola de procesos bloqueados? Si lo tuviera, ¿en qué casos sería útil hacerlo?**

La cola de bloqueados no tiene por que estar ordenada puesto que cuando dejen de estar bloqueados pasarán a la cola de preparados.

7. **¿Puede el procesador manejar una interrupción mientras está ejecutando un proceso si la política de planificación que utilizamos es no apropiativa?**

Se esperaría a completar el quantum o la ejecución del proceso para manejar la interrupción.

8. **Suponga que es responsable de diseñar e implementar un sistema operativo que va a utilizar una política de planificación apropiativa. Suponiendo que tenemos desarrollado el algoritmo de planificación a tal efecto, ¿qué otras partes del sistema operativo habría que modificar para implementar tal sistema? y ¿cuáles serían tales modificaciones?**

Es necesario modificar el sistema operativo para el manejo de interrupciones apropiado y asegurar que las tareas se reanudan en el estado en el que se encontraban antes de ser interrumpidas, salvar los PCB de cada proceso y distribuir adeacuadamente el uso de la CPU de cada uno de ellos.


9. **En el algoritmo de planificación FCFS, la penalización ( (t + tº de espera) / t ), ¿es creciente, decreciente o constante respecto a t (tiempo de servicio de CPU requerido por un proceso)? Justifique su respuesta.**

Es creciente puesto que el tiempo de espera del último proceso es igual al tiempo de servicio de CPU requerido por cada uno de los procesos anteriores.

10. **En la tabla siguiente se describen cinco procesos:**

|Proceso|Tiempo de creacion|Tiempo de CPU|
|-|-|-|
|A|4|1|
|B|0|5|
|C|1|4|
|D|8|3|
|E|12|2|

**Si suponemos que tenemos un algoritmo de planificación que utiliza una política FIFO (primero en llegar, primero en ser servido), calcula:**

|-|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|A| | | | | | | | | | |X| | | | | |
|B|X|X|X|X|X| | | | | | | | | | | |
|C| | | | | | |X|X|X|X| | | | | | |
|D| | | | | | | | | | | |X|X|X| | |
|E| | | | | | | | | | | | | | |X|X|

**a) Tiempo medio de respuesta** 2.2

**b) Tiempo medio de espera** 2.2

**c) La penalización, es decir, el cociente entre el tiempo de respuesta y el tiempo de CPU.** 1.81

11. **Utilizando los valores de la tabla del problema anterior, calcula los tiempos medios de espera y respuesta para los siguientes algoritmos:**

|Proceso|Tiempo de creacion|Tiempo de CPU|
|-|-|-|
|A|4|1|
|B|0|5|
|C|1|4|
|D|8|3|
|E|12|2|

**a) Por Turnos con quantum q=1**

|-|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|A| | | | | |X| | | | | | | | | | |
|B|X|X| |X| | |X| |X| | | | | | | |
|C| | |X| |X| | |X| | |X| | | | | |
|D| | | | | | | | | |X| |X|X| | | |
|E| | | | | | | | | | | | | |X|X| |

Tiempo de espera medio: 2.8s
tiempo de respuesta medio: 0.8s

**b) Por Turnos con quantum q=4**

|-|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|A| | | | | | | | | |X| | | | | | |
|B|X|X|X|X| | | | |X| | | | | | | |
|C| | | | |X|X|X|X| | | | | | | | |
|D| | | | | | | | | | |X|X|X| | | |
|E| | | | | | | | | | | | | |X|X| |

Tiempo de espera medio: 3s
tiempo de respuesta medio: 2.2s

**c) El más corto primero (SJF). Suponga que se estima una ráfaga igual a la real.**

Se asume que es apropiativo

|-|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|A| | | | | |X| | | | | | | | | | |
|B|X|X|X|X|X| | | | | | | | | | | |
|C| | | | | | |X|X|X|X| | | | | | |
|D| | | | | | | | | | |X|X|X| | | |
|E| | | | | | | | | | | | | |X|X| |

Tiempo de espera medio: 1.8s
tiempo de respuesta medio: 1.8s

12. **Calcula el tiempo de espera medio para los procesos de la tabla utilizando el algoritmo: el primero más corto apropiativo (o primero el de tiempo restante menor, SRTF).**

|Proceso|Tiempo de creacion|Tiempo de CPU|
|-|-|-|
|A|0|3|
|B|1|1|
|C|3|12|
|D|9|5|
|E|12|5|


|-|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|A|X| |X|X| | | | | | | | | | | | | | | | | | | | | | |
|B| |X| | | | | | | | | | | | | | | | | | | | | | | | |
|C| | | | |X|X|X|X|X| | | | | | | | | | |X|X|X|X|X|X|X|
|D| | | | | | | | | |X|X|X|X|X| | | | | | | | | | | | |
|E| | | | | | | | | | | | | | |X|X|X|X|X| | | | | | | |

Tiempo de espera medio: 2.6s

13. **Utilizando la tabla del ejercicio anterior, dibuja el diagrama de ocupación de CPU para el caso de un sistema que utiliza un algoritmo de colas múltiples con realimentación con las siguientes colas:**

|Proceso|Tiempo de creacion|Tiempo de CPU|
|-|-|-|
|A|0|3|
|B|1|1|
|C|3|12|
|D|9|5|
|E|12|5|

|Cola|Prioridad|Quantum|
|-|-|-|
|1|1|1|
|2|2|2|
|3|3|4|
**y suponiendo que:**

**(a) Todos los procesos inicialmente entran en la cola de mayor prioridad (menor valor numérico). Cada cola se gestiona mediante la política Por Turnos.

(b) la política de planificación entre colas es por prioridades no apropiativo.

(c) un proceso en la cola i pasa a la cola i+1 si consume un quantum completo sin bloquearse.

(d) cuando un proceso llega a la cola de menor prioridad, permanece en ella hasta que finalice.**


|-|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|A|X| |X|X| | | | | | | | | | | | | | | | | | | | | | |
|B| |X| | | | | | | | | | | | | | | | | | | | | | | | |
|C| | | | |X|X|X|X|X|X|X| | | | | | |X|X|X|X| | | |X| |
|D| | | | | | | | | | | |X|X|X| | | | | | | |X|X| | | |
|E| | | | | | | | | | | | | | |X|X|X| | | | | | |X| | |
|Cola1|A|B| |C|C| | | | |D|D| |E|E| | | | | | | | | | |
|Cola2| |A|A|A| |C| | | | | |D|D| |E|E|E| | | | | | | |
|Cola3| | | | | | |C|C|C|C|C|C|C|CD|CD|CD|CDE|CDE|CDE|CDE|DEC|DEC|EC|C |

14. **Suponga que debe maximizar la eficiencia de un sistema multiusuario y que está recibiendo quejas de muchos usuarios sobre los pobres tiempos de respuesta (o tiempos de vuelta) de sus procesos. Los resultados obtenidos con una herramienta de monitorización del sistema nos muestran que la CPU se utiliza al 99'9% de su tiempo y que los procesadores de E/S están activos solo un 10% de su tiempo. ¿Cuales pueden ser las razones de estos tiempos de respuesta pobres y por qué?**

**a) El quantum en la planificación Round-Robin es muy pequeño.** En este caso todos los procesos deberían ejecutarse de forma regular y el porcentaje del uso de E/S sería mayor.

**b) La memoria principal es insuficiente.**

**c) El sistema operativo tiene que manejar mucha memoria principal por lo que las rutinas de gestión de memoria están consumiendo todos los ciclos de CPU.**

**d) La CPU es muy lenta.**

**e) El quantum en la planificación Round-Robin es muy grande.** Es posible ya que un único porceso de ususario podría acaparla CPU durante lasrgos periodos de tiempo.

16. **¿El planificador CFS de Linux favorece a los procesos limitados por E/S (cortos) frente a los procesos limitados por CPU (largos)? Explique cómo lo hace.**

El planificador completamente justo se basa en elaborar un árbol de búsqueda en el que se almacenan las futuras tareas, las hojas son procesos sueltos, mientras que los nodos son conjuntos de tareas, de entre los nodos selecciona aquél que tenga menor runtime para el nivel que se está explorando y lo expande. Si se trata de un nodo hoja (proceso) selecciona ese proceso para ejecutar y actualiza el árbol.
