// usage of arrays example
// simple 1 and 2-d array example

#include <stdio.h>
#include <math.h>

// a fuction to clear an arbitrary length array of doubles to 0.0
void clear(double a[], int size);
// or
// void clear(double *a, int size);

int main(){
  const int SIZE=6;
  const int NR=3;
  const int NC=4;
  double a[SIZE];  // declare an array of doubles
  int ab[NR][NC];  // declare a 2D array

  // fill the 1d array with some data
  for (int i=0; i<SIZE; i++){
    a[i] = sqrt(i);
    printf("%lf\n",a[i]);
  }
  printf("--\n");

  // clear the 1D array and print it again
  clear(a,SIZE);
  for (int i=0; i<SIZE; i++) printf("%lf\n",a[i]);
  printf("--\n");

  // fill the 2D array with some data
  for (int nr=0; nr<NR; nr++){
    for (int nc=0; nc<NC; nc++){
      ab[nr][nc]=nr*1000+nc;
    }
  }
  // print the 2D array
   for (int nr=0; nr<NR; nr++){
    for (int nc=0; nc<NC; nc++){
      printf("%04d  ",ab[nr][nc]);
    }
    printf("\n");
  } 

  return 0;
}

void clear(double a[], int size){
  for (int i=0; i<size; i++) a[i]=0.0;
}
