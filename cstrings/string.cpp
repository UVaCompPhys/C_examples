// example of various string functions
// Input: at least two text strings at the command line

#include <stdio.h>
#include <string.h>

int main(unsigned int argc, char *argv[]){
  char combi[41];
  char suffix1[4], suffix2[4];
  if (argc<3) {
    printf("run this program with at least two strings as input\n");
    return 1;
  }

  // print the length of all input strings
  for (unsigned int i=1; i<argc; i++)
    printf("strlen(\"%s\") = %d\n",argv[i],strlen(argv[i]));

  // test for equality between the 1st two input strings
  if (!strcmp(argv[1],argv[2])) printf("string1 = string2\n");
  else printf("string1 != string2\n");

  // copy a maximum of 20 characters from each of the 1st two 
  // input strings into the string "combi"
  strncpy(combi,argv[1],20);
  strncat(combi,argv[2],20);
  printf("Combined string = %s\n",combi);

  // test each string to see if it is at least 3 charcters long
  if ( strlen(argv[1])>=3 && strlen(argv[2])>=3 ) {

    // extract last three characters of strings 
    //  plus one extra character for the terminator...
    for (int i=strlen(argv[1])-3,index=0 ; i<=strlen(argv[1]) ; i++) {
      suffix1[index] = argv[1][i]; 
      index++;
    }
    for (int i=strlen(argv[2])-3,index=0 ; i<=strlen(argv[2]) ; i++) {
      suffix2[index] = argv[2][i]; 
      index++;
    }

    // print the last 3 characters the 1st two input strings
    printf("suffix 1/2 = %s/%s\n",suffix1,suffix2);

    // test these last three characters for equality
    if (!strcmp(suffix1,suffix2)) printf("suffix1 = suffix2\n");
    else printf("suffix1 != suffix2\n");

  } 
  


  return 0;
}








