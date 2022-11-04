#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
#define NUM_THREADS 10


void assignImage(char* ptr,long ancho, long alto,unsigned char fotoB[][ancho], FILE *outputImage){
 for (int i = 0; i < alto*ancho; ++i) {
      fputc(ptr[i], outputImage);
      fputc(ptr[i+1], outputImage);
      fputc(ptr[i+2], outputImage);
    }

}

void flipImage(char* ptr,long ancho, long alto,unsigned char fotoB[][ancho], char inv){
    int count = 0;
    if(inv == 1){
    // Vertical flip
    #pragma omp single
    for(int i=alto; i>0;i--){
        for(int j=ancho; j>0;j--){
        ptr[count] = fotoB[i][j]; //b
        ptr[count+1] = fotoB[i][j]; //g
        ptr[count+2] = fotoB[i][j]; //r
        count++;
        }
    }
    //Horizontal flip
    }
    else if(inv == 2){
        #pragma omp single
        for(int i=0; i<alto;i++){
            for(int j=ancho; j>0;j--){
            ptr[count] = fotoB[i][j]; //b
            ptr[count+1] = fotoB[i][j]; //g
            ptr[count+2] = fotoB[i][j]; //r
            count++;
            }
        }
    }
    // Save Image
    count = 0;
    for(int i=0; i<alto;i++){
        for(int j=0; j<ancho;j++){
        fotoB[i][j] = ptr[count]; //b
        fotoB[i][j] = ptr[count+1]; //g
        fotoB[i][j] = ptr[count+2]; //r
        count++;
        }
    }

    }



int main()
{
  omp_set_num_threads(NUM_THREADS);
  FILE *image, *outputImage_0, *lecturas;
  image = fopen("7.bmp","rb");          //Imagen original a transformar
  outputImage_0 = fopen("imgs/0.bmp","wb");
  long ancho;
  long alto;
  unsigned char r, g, b;               //Pixel
  unsigned char* ptr;

  unsigned char xx[54];
  
  for(int i=0; i<54; i++) {
    xx[i] = fgetc(image);
    fputc(xx[i], outputImage_0); 
  }


  ancho = (long)xx[20]*65536+(long)xx[19]*256+(long)xx[18];
  alto = (long)xx[24]*65536+(long)xx[23]*256+(long)xx[22];
  printf("largo img %li\n",alto);
  printf("ancho img %li\n",ancho);

  ptr = (unsigned char*)malloc(alto*ancho*3* sizeof(unsigned char));
    
  unsigned char foto[alto][ancho], fotoB[alto][ancho];
  unsigned char pixel;
#pragma omp parallel for schedule (dynamic) collapse(2)
    for(int i=0; i<alto;i++){
      for(int j=0; j<ancho;j++){
        b = fgetc(image);
        g = fgetc(image);
        r = fgetc(image);

        pixel = 0.21*r+0.72*g+0.07*b;
        foto[i][j]=pixel;
        fotoB[i][j]=pixel;
      }
    }
  const double startTime = omp_get_wtime();  
  flipImage(ptr,ancho, alto,fotoB,1);
  flipImage(ptr,ancho, alto,fotoB,2);
  assignImage(ptr,ancho, alto,fotoB,outputImage_0);
  const double endTime = omp_get_wtime();

  free(ptr);
  fclose(image);
  fclose(outputImage_0);
  printf("Tiempo=%f", endTime-startTime);
  return 0;
}