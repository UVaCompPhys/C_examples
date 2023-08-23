// Example use of conditionals and boolean variables

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
  srand((unsigned)time(NULL));
  double value = (double)rand()/RAND_MAX * 100;  // 0<=value<=100
  
  printf("\nRandom value = %lf\n",value);

  // simple condition and action
  if (value<10) printf("value < 10\n");

  // compound condition and code block
  if ( (value < 5) || (value > 10) ) {
    printf("(value < 5) || (value > 50)\n");
    printf("%d gnus in a herd\n",(int)value);
  }

  // if-else structure
  if (value < 25) 
    printf("value < 25\n");
  else if (value < 50)
    printf("value < 50\n");
  else printf("value >= 50\n");

  // storing a logical test in a bool variable
  bool test1 = (value<1) || (value>99);
  bool test2 = (value>50) && (value<60);
  bool pass = test1 || test2;
  if (pass) {
    printf("value passed: ");
    if (test1) printf("test1 ");
    if (test2) printf("test2");
    printf("\n");
  }
  printf("\n");
  return 0;
}
