// cstring example
// manipulation of null-terminated strings
 
#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[]){
  if (argc<2) {
    printf("Usage: cstrings [textstring1] <textstring2> ...\n");
    return 1;
  }
  printf("Number of strings entered: %d\n",argc-1); // argv[0] is program name
 
  for (int i=1; i<argc; i++){
    // printf figures the length of the string to print
    printf("string %d: %s, length %d\n",i,argv[i],strlen(argv[i]));
 
    // here we print the string by hand, stopping at the nul character
    char *str=argv[i];
    int idx=0;
    while (1){
      if (str[idx] == '\0') break;   // or simply (str[idx] == 0)
      printf("%c",str[idx]);
      idx++;
    } 
    printf("\n");
  }
 
  return 0;

