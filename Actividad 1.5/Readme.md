# Actividad 1.5

En esta actividad se tiene como objetivo comparar las diferentes velocidades de lecto-escritura de una computadora portátil; para realizar las mediciones, se desarrollaron tres diferentes programas en C, haciendo uso de la API de OpenMP. Los parámetros escogidos para realizar estas mediciones fueron prácticamente los mismos en cada programa, pero tomando en cuenta que el número de operaciones del primer programa se divide entre seis en los demás programas, esto se debe a que en el primer programa cada thread ejecuta cierto número de pasos del total, mientras que en los programas 2 y 3 cada thread ejecuta el número de pasos completo. 

A continuación, se muestran los parámetros usados:

- Numero de Threads: 6
- Operaciones (usado en el programa 1): 9999996
- Numero de Operaciones / 6 (usado en los programas 2 y 3): 1666666


**Códigos**

Como se mencionó, en esta actividad se utilizan tres programas distintos, sin embargo el primero es el mismo que el que se explica en la actividad 1.4, por lo que se omite la explicación

- Velocidad de la RAM (programa 2): Para obtener la velocidad de la memoria RAM, se usó el programa que calcula una ecuación diferencial por medio del método de Euler, en este caso tambien se hacen uso de threads, pero el programa funciona como un programa TLP, ya que cada hilo ejecuta una tarea diferente. Cabe destacar que para asegurar que el programa corra en la RAM, se hizo uso de arreglos para guardar los datos de los hilos, y el tiempo se midió hasta antes de escribir en los archivos .txt que genera el programa
  
  Se empiezan definiendo las librerias necesarias y declarando los arreglos donde se guardaran los resultados segun el numero de pasos y threads
  
  ``` C
  #include <stdio.h>
  #include <omp.h>
  #include <math.h>
  #define NUM_THREADS 6

     FILE *fptr;
     FILE *fptr1;
     FILE *fptr2;
     FILE *fptr3;
     FILE *fptr4;
     FILE *fptr5;
     double t[1666666][6];
     double w[1666666][6];
  ```

- Velocidad del disco duro (programa 3): este programa funciona de manera casi idéntica que el segundo, calculando una derivada parcial por medio del método de Euler y haciendo uso de threads, la diferencia principal está en que en este programa se van escribiendo los resultados en archivos .txt y el tiempo se acaba de medir hasta que se acaban de escribir, con lo que se asegura que se este calculando la velocidad del disco duro


``` C

```
**Resultados**

Al ejecutar el programa, obtenemos las siguientes impresiones en consola, con el numero de thread ejecutando la instrucción

![Resultado](./Imagen1_3_8.png)

En las siguientes gráficas se puede observar qué thread fue el primero en ejecutar una instrucción printf en cada una de las 15 ejecuciones. Cabe destacar que este código hace uso de OpenMP para su ejecución y la numeración de los threads empieza desde 0

![Grafica 1](./Imagen1_3_1.png)

![Grafica 2](./Imagen1_3_2.png)

![Grafica 3](./Imagen1_3_3.png)

![Grafica 4](./Imagen1_3_4.png)

![Grafica 5](./Imagen1_3_5.png)

![Grafica 5](./Imagen1_3_6.png)

De estas gráficas se puede concluir que, como era de esperar, el orden en el que se liberan los threads es aleatorio, y depende del SO en su totalidad, aunque por alguna razón en las pruebas realizadas se observó que los threads en liberarse primero son threads con una numeración baja, esto se nota más en las últimas pruebas donde en ningún momento empieza primero un threads más allá del número 7, puede que simplemente sea la aleatoriedad y con más pruebas sean distintos los threads que empiezan primero. 


También vale la pena mencionar que en ocasiones los printf no se ejecutaban en el orden en el que le corresponden, dando a entender que otro thread ejecutó su instrucción antes de que se terminarán de ejecutar los printf de un thread, en la siguiente captura se muestra un ejemplo de lo descrito.

![Resultado 2](./Imagen1_3_8.png)
