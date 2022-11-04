#include <stdio.h>
#include <stdlib.h>
#include<omp.h>



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


void flipImage(long ancho, long alto, unsigned char foto [][ancho], unsigned char fotoC [][ancho]){
  for (int i=0;i<alto;i++){
    for (int j = 0; j< ancho;j++){
      fotoC[i][j] = foto[alto-i][ancho-j];
    }
  }
}

void printMatrix(long ancho, long alto, unsigned char foto [][ancho]){
  for (int i=0;i<alto;i++){
    for (int j = 0; j< ancho;j++){
      printf("%d ",foto[i][j]);
    }
    printf("\n");
  }
}

void blurrring(long ancho, long alto, int kernelSize, unsigned char foto [][ancho], unsigned char fotoB [][ancho], char* ptr, FILE *outputImage,char inv){
    int inicioX,inicioY,cierreX,cierreY,ladoX,ladoY;
    long cuenta = 0;
    long sum;
    for(int i=0;i<alto;i++){
    for(int j=0;j<ancho;j++){
      if(i<kernelSize){
        inicioX=0;
        cierreX=i+kernelSize;
        ladoX=i+kernelSize;
      } else if(i>=alto-kernelSize){
        inicioX=i-kernelSize;
        cierreX=alto;
        ladoX=alto-i+kernelSize;
      }else{
        inicioX=i-kernelSize;
        cierreX=i+kernelSize;
        ladoX=kernelSize*2+1;
      }
  
      if(j<kernelSize){
        inicioY=0;
        cierreY=j+kernelSize;
        ladoY=j+kernelSize;
      }else if(j>=ancho-kernelSize){
        inicioY=j-kernelSize;
        cierreY=ancho;
        ladoY=ancho-j+kernelSize;
      }else{
        inicioY=j-kernelSize;
        cierreY=j+kernelSize;
        ladoY=kernelSize*2+1;
      }
      sum=0;
      for(int x=inicioX;x<cierreX;x++){
        for(int y=inicioY;y<cierreY;y++){
          sum+=foto[x][y];
        }
      }
      sum=sum/(ladoX*ladoY);
      fotoB[i][j]=sum;
    }
  }
  assignImage(ptr,ancho, alto,fotoB,outputImage,inv);
}



int main()
{
  FILE *image, *outputImage_0,*outputImage_1, *outputImage_2, *outputImage_3, *outputImage_4, *outputImage_5, *outputImage_6, *outputImage_7, *outputImage_8, *outputImage_9, *outputImage_10, *outputImage_11, *outputImage_12, *outputImage_13, *outputImage_14, *outputImage_15, *outputImage_16, *outputImage_17, *outputImage_18, *outputImage_19, *lecturas;
  image = fopen("7.bmp","rb");          //Imagen original a transformar
  outputImage_0 = fopen("imgs/0.bmp","wb");
  outputImage_1 = fopen("imgs/1.bmp","wb");
  outputImage_2 = fopen("imgs/2.bmp","wb");
  outputImage_3 = fopen("imgs/3.bmp","wb");
  outputImage_4 = fopen("imgs/4.bmp","wb");
  outputImage_5 = fopen("imgs/5.bmp","wb");
  outputImage_6 = fopen("imgs/6.bmp","wb");
  outputImage_7 = fopen("imgs/7.bmp","wb");
  outputImage_8 = fopen("imgs/8.bmp","wb");
  outputImage_9 = fopen("imgs/9.bmp","wb");
  outputImage_10 = fopen("imgs/10.bmp","wb");
  outputImage_11 = fopen("imgs/11.bmp","wb");
  outputImage_12 = fopen("imgs/12.bmp","wb");
  outputImage_13 = fopen("imgs/13.bmp","wb");
  outputImage_14 = fopen("imgs/14.bmp","wb");
  outputImage_15 = fopen("imgs/15.bmp","wb");
  outputImage_16 = fopen("imgs/16.bmp","wb");
  outputImage_17 = fopen("imgs/17.bmp","wb");
  outputImage_18 = fopen("imgs/18.bmp","wb");
  outputImage_19 = fopen("imgs/19.bmp","wb");
  long ancho;
  long alto;
  unsigned char r, g, b;               //Pixel
  unsigned char* ptr;

  unsigned char xx[54];
  
  for(int i=0; i<54; i++) {
    xx[i] = fgetc(image);
    fputc(xx[i], outputImage_0); 
    fputc(xx[i], outputImage_1); 
    fputc(xx[i], outputImage_2);
    fputc(xx[i], outputImage_3); 
    fputc(xx[i], outputImage_4);
    fputc(xx[i], outputImage_5); 
    fputc(xx[i], outputImage_6);
    fputc(xx[i], outputImage_7); 
    fputc(xx[i], outputImage_8);
    fputc(xx[i], outputImage_9); 
    fputc(xx[i], outputImage_10);
    fputc(xx[i], outputImage_11); 
    fputc(xx[i], outputImage_12);
    fputc(xx[i], outputImage_13); 
    fputc(xx[i], outputImage_14);
    fputc(xx[i], outputImage_15); 
    fputc(xx[i], outputImage_16);
    fputc(xx[i], outputImage_17); 
    fputc(xx[i], outputImage_18);
    fputc(xx[i], outputImage_19); 
  }


  ancho = (long)xx[20]*65536+(long)xx[19]*256+(long)xx[18];
  alto = (long)xx[24]*65536+(long)xx[23]*256+(long)xx[22];
  printf("largo img %li\n",alto);
  printf("ancho img %li\n",ancho);

  ptr = (unsigned char*)malloc(alto*ancho*3* sizeof(unsigned char));
    
  unsigned char foto[alto][ancho], fotoB[alto][ancho];
  unsigned char pixel;
  
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
  blurrring(ancho, alto, 1, foto , fotoB , ptr, outputImage_1,0);
  blurrring(ancho, alto, 2, foto , fotoB , ptr, outputImage_2,0);
  blurrring(ancho, alto, 3, foto , fotoB , ptr, outputImage_3,0);
  blurrring(ancho, alto, 4, foto , fotoB , ptr, outputImage_4,0);
  blurrring(ancho, alto, 5, foto , fotoB , ptr, outputImage_5,0);
  blurrring(ancho, alto, 6, foto , fotoB , ptr, outputImage_6,0);
  blurrring(ancho, alto, 7, foto , fotoB , ptr, outputImage_7,0);
  blurrring(ancho, alto, 8, foto , fotoB , ptr, outputImage_8,0);
  blurrring(ancho, alto, 9, foto , fotoB , ptr, outputImage_9,0); 
  blurrring(ancho, alto, 10, foto , fotoB , ptr, outputImage_10,1);
  blurrring(ancho, alto, 9, foto , fotoB , ptr, outputImage_11,1);    
  blurrring(ancho, alto, 8, foto , fotoB , ptr, outputImage_12,1);    
  blurrring(ancho, alto, 7, foto , fotoB , ptr, outputImage_13,1);    
  blurrring(ancho, alto, 6, foto , fotoB , ptr, outputImage_14,1);    
  blurrring(ancho, alto, 5, foto , fotoB , ptr, outputImage_15,1);    
  blurrring(ancho, alto, 4, foto , fotoB , ptr, outputImage_16,1);    
  blurrring(ancho, alto, 3, foto , fotoB , ptr, outputImage_17,1);    
  blurrring(ancho, alto, 2, foto , fotoB , ptr, outputImage_18,1);    
  blurrring(ancho, alto, 1, foto , fotoB , ptr, outputImage_19,1);         

  const double endTime = omp_get_wtime();

  assignImage(ptr,ancho, alto,fotoB,outputImage_0,0);

  free(ptr);
  fclose(image);
  fclose(outputImage_0);
  fclose(outputImage_1);
  fclose(outputImage_2);
  fclose(outputImage_3);
  fclose(outputImage_4);
  fclose(outputImage_5);
  fclose(outputImage_6);
  fclose(outputImage_7);
  fclose(outputImage_8);
  fclose(outputImage_9);
  fclose(outputImage_10);
  fclose(outputImage_11);
  fclose(outputImage_12);
  fclose(outputImage_13);
  fclose(outputImage_14);
  fclose(outputImage_15);
  fclose(outputImage_16);
  fclose(outputImage_17);
  fclose(outputImage_18);
  fclose(outputImage_19);

  printf("Tiempo=%f", endTime-startTime);
  return 0;
}