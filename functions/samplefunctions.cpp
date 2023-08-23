// Samples of various function prototypes, any number of inputs may 
// be spefified.  A maximum of one value may be returned.
 
#include <stdio.h> 
#include <math.h>
 
// inputs: two ints
// returns: int
int func1(int i, int j);
 
// inputs: double and int
// returns: double
double func2(double radius, int dim);
 
// inputs: void
// returns: void
void func3();
 
 
// main is a function
int main(){  // here it takes a void argument and returns an int
  int i=1, j=2;
  printf("func1(%d,%d)=%d\n",i,j,func1(i,j));
  int dim=3;
  double volume=func2(1.0,dim);
  printf("Volume of unit %d-sphere: %lf\n",dim,volume);
  func3();
  return 0;
}
 
// simple adder
int func1(int i, int j){
  return i+j;
}
 
// calculate volume of n-sphere
double func2(double radius, int dim){
  double exponent=dim/2.;
  // M_PI defined in math.h
  double k=pow(M_PI,exponent) / tgamma(exponent+1.0);
  return k*pow(radius,dim);
}
 
// this function just prints ack
void func3(){
  printf("ack!\n");
}

