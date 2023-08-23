// fputc example: output anything in raw, binary form
#include <stdio.h>

typedef unsigned char BYTE;  // define a new name for unsigned char

// writes nbytes in raw binary form to *file starting from memory location
// given by *start
void write_out(BYTE *start, int nbytes, FILE *file){
  for (unsigned int i=0; i<nbytes; i++){
    fputc (*start, file);    // write 1 byte at a time to the file
    start++;
  }
}

int main () {
  BYTE characters[256];
  for (int i= 0 ; i <= 255 ; i++) characters[i]=i;

  FILE *cfile = fopen ("8bits.txt","w");
  write_out(characters, sizeof(characters), cfile);
  fclose(cfile);

  float array[]={-12.2356, 13e-12, 15, 123E23};

  FILE *out=fopen("out.dat","w");  
  write_out((BYTE *)&array, sizeof(array), out);
  fclose(out);
  return 0;
}
