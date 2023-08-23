// Program args.cpp
// example usage of argc, argv to read data from the command line 
// into your program 
// This program demonstrates the conversion of input data to internal
// variable types.
 
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]){ 
 
  int i;
  printf("%d arguments were entered at the command line\n\n",argc-1);
  // print all command line arguments as strings
  for (i=0; i<argc ;i++) 
    printf("argv[%d] = %s\n",i,argv[i]);
  printf("\n");
  // translate arguments into ints and print
  for (i=1; i<argc ;i++)
     printf("atoi(argv[%d]) = %d\n",i,atoi(argv[i]));
  printf("\n");
  // translate arguments into doubles and print
  for (i=1; i<argc ;i++)
    printf("atof(argv[%d]) = %lf\n",i,atof(argv[i]));
  return 0;
  
