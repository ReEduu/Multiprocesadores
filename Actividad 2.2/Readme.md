# Actividad 2.2

Se desarrolló un programa en C, el cual tiene el objetivo de aplicarle el efecto de desenfoque con diferentes intensidades a un par de imágenes bmp de diferente tamaño, así como invertir la imagen en determinados resultados. Esto se debe realizar tanto de manera paralelizada como sin paralelización con el fin de comparar los resultados obtenidos 


**Código**

Sólo se comentará el código paralelizado, ya que en funcionamiento, este y el no paralelizado son practicamente iguales, ademas el código utilizado es similar al de la actividad 2.1 en mayor medida, el cual ya se explicó anteriormente por lo que sólo se describirá brevemente, enfocandose en los cambios y añadidos que presenta este código con respecto al anterior  

La primera función que se encuentra en el programa es la de assignImage, lo que hace es escribirle 

``` C
void assignImage(char* ptr,long ancho, long alto,unsigned char fotoB[][ancho], FILE *outputImage,char inv){
int count = 0;
if(inv == 0){
  for(int i=0; i<alto;i++){
    for(int j=0; j<ancho;j++){
      ptr[count] = fotoB[i][j]; //b
      ptr[count+1] = fotoB[i][j]; //g
      ptr[count+2] = fotoB[i][j]; //r
      count++;
    }
  }
}
else{
 for(int i=0; i<alto;i++){
    for(int j=ancho; j>0;j--){
      ptr[count] = fotoB[i][j]; //b
      ptr[count+1] = fotoB[i][j]; //g
      ptr[count+2] = fotoB[i][j]; //r
      count++;
    }
  }
}
 for (int i = 0; i < alto*ancho; ++i) {
      fputc(ptr[i], outputImage);
      fputc(ptr[i+1], outputImage);
      fputc(ptr[i+2], outputImage);
    }

}
```
**Resultados**

Al ejecutar el programa, obtenemos las siguientes impresiones en consola, con el numero de thread ejecutando la instrucción

![Resultado](./Imagen2_2_1.png)

En las siguientes gráficas se puede observar qué thread fue el primero en ejecutar una instrucción printf en cada una de las 15 ejecuciones. Cabe destacar que este código hace uso de OpenMP para su ejecución y la numeración de los threads empieza desde 0

![Original 1](./7.bmp)

![Original 1](./8.bmp)

![Grafica 1](./imgGrandeSinParallel.gif.gif)

![Grafica 2](./imgGrandeConParallel.gif)

![Grafica 3](./imgPequeñaSinParallel.gif)

![Grafica 4](./imgPequeñaConParallel.gif)


De estas gráficas se puede concluir que, como era de esperar, el orden en el que se liberan los threads es aleatorio, y depende del SO en su totalidad, aunque por alguna razón en las pruebas realizadas se observó que los threads en liberarse primero son threads con una numeración baja, esto se nota más en las últimas pruebas donde en ningún momento empieza primero un threads más allá del número 7, puede que simplemente sea la aleatoriedad y con más pruebas sean distintos los threads que empiezan primero. 


También vale la pena mencionar que en ocasiones los printf no se ejecutaban en el orden en el que le corresponden, dando a entender que otro thread ejecutó su instrucción antes de que se terminarán de ejecutar los printf de un thread, en la siguiente captura se muestra un ejemplo de lo descrito.

![Resultado 2](./Imagen1_3_8.png)
