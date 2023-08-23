// This program uses a single function call to return two normally 
// distributed (pseudo) random numbers to the main function.  Various 
// pieces of functionality are broken into separate functions to 
// facilitate their reuse in future programs. 
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
 
double xnorm(double u1, double u2);  // the three functions  
double ynorm(double u1, double u2);  // are used internally 
double rand0_1();                    // by norm2
 
// return 2 normally distributed variables
void norm2(double *n1, double *n2); 
 
int main(){
  double rann1, rann2; 
  int i, n68=0;
  const int NLOOPS=1000;
  int nvalues=NLOOPS*2;
 
  for (i=0; i<NLOOPS ; i++){
    norm2(&rann1,&rann2);
    if (fabs(rann1)<1.0) n68++;
    if (fabs(rann2)<1.0) n68++;
  }
  printf("%% values in +- 1 sigma = %5.2f%% \n",
	 (float)n68/(float)nvalues*100);
  return 0;
}
 
// return a normally distributed random number 
// based on two input numbers, uniformly distributed
// in the range (0:1]  (Method 1)
double xnorm(double u1, double u2){
  return sqrt(-2*log(u1))*cos(2*M_PI*u2);   // M_PI is defined in math.h
}         	                            // see file: /usr/include/math.h
                                            // or your Programmer's Ref.
 
// return a normally distributed random number
// based on two input numbers, uniformly distributed
// in the range (0:1] (Method 2)
double ynorm(double u1, double u2){
  return sqrt(-2*log(u1))*sin(2*M_PI*u2);   
}
 
double rand0_1(){                  // return a random number in range (0:1]
  double value;
  do { 
    value = rand()/(double)RAND_MAX;
  } while (!value);    // one way to make sure our return value is never 0
  return value;
}
 
// This is the function that we call in the main program above
// srand is only executed on the 1st call to this function
// this is simliar to the example given in lecture 4
 
void norm2(double *n1, double *n2){
  static bool first=true;       
  if (first){
    srand(time(NULL));		// initialize the rand() function
    first=false;
  }
  double u1,u2;
  u1 = rand0_1();
  u2 = rand0_1();
  *n1 = xnorm(u1,u2);
  *n2 = ynorm(u1,u2);
}

