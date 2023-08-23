// fgetc example: input anything in raw, binary form
#include <stdio.h>

typedef unsigned char BYTE;  // define a new name for unsigned char

int main () {
  FILE *file1;
  file1 = fopen ("8bits.txt","r");
  
  BYTE c;
  int count=0;
  while(1){
    c=fgetc(file1);          // read in 1 byte at a time
    if (feof(file1)) break;  // check OS for end of file signal
    count++;
    printf("%3d ",c);        // output the data as an integer
    //    printf("%c ",c);   // or as a character (if possible)
    if (count%16 ==0) printf("\n");
  }

  fclose(file1);
  return 0;
}
