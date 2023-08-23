// examples of conditional loop constructs
// run the program several times, the second loop will not
// be entered if max_steps==0

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
  srand((unsigned)time(NULL));

  // quick and not so uniform method to get 0 <= random int <= 3
  int max_steps = (RAND_MAX/(rand()/17)) % 4;
  // do while loop always runs at least once
  printf("\nInitial value of steps= %d\n",max_steps);

  int steps = max_steps;
  do {
    printf("In Do-While Loop: steps= %d\n",steps);
    steps--;
  } while (steps > 0);

  // while loop is not guaranteed to run at all
  steps = max_steps;
  while (steps > 0 ){
    printf("While Loop: steps= %d\n",steps);
    steps--;
  }
  printf("\n");
  return 0;
}
