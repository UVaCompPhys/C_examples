// simple example of binary read/write operations

#include <stdio.h>

typedef struct{
  double re;
  double im;
}complex;

int main(){
  const int SIZE=100;
  float array1[SIZE];
  float array2[SIZE];
  for (int i=0; i<SIZE; i++){
    array1[i] = 3.14159*i;
    array2[i] = i*i;
  }

  FILE *bfp=fopen("temp.out","wb");      // open for binary write mode
  // write the entire array1 to the file
  fwrite((void *)array1, sizeof(float), SIZE, bfp);
  // write the entire array2 to the file
  fwrite((void *)array2, sizeof(int), SIZE, bfp);

  // with fwrite, you can write any data to a file
  complex a;
  a.re=12345;
  a.im=67890;
  fwrite((void *)&a, sizeof(complex), 1, bfp);
  // or an array of any data
  complex c[SIZE];
  for (int i=0; i<SIZE; i++){
    c[i].re=i;
    c[i].im=-i;
  }
  fwrite((void *)&c, sizeof(complex), SIZE, bfp);

  fclose(bfp);

  bfp=fopen("temp.out","rb");      // open for binary read mode
  // read the entire array1 from file
  fread((void *)array2, sizeof(float), SIZE, bfp);
  // write the entire array2 to the file
  fread((void *)array1, sizeof(int), SIZE, bfp);
  fclose(bfp);
  
  // we have just performed a swap operation

  return 0;
}
