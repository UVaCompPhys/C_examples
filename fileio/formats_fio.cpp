// Examples of formatted output to a file
 
#include <stdio.h>
#include <math.h>
 
int main() {
 
  const char* fileName="numbers.dat";  // file name string
  printf("Output is in: %s\n",fileName);
  FILE *fp;  // define a "file pointer" to represent the data file
  fp = fopen(fileName,"w");  // open a file for writing
 
  //
  // integers
  //
  fprintf(fp, "default        :%d|\n",123);
  fprintf(fp, "default        :%d|\n",1234);
  fprintf(fp, "default        :%d|\n",12345);
 
  // fixed column width, right aligned
  fprintf(fp, "10 column RA   :%10d|\n",123);
  fprintf(fp, "10 column RA   :%10d|\n",1234);
  fprintf(fp, "10 column RA   :%10d|\n",12345);
 
  // left aligned
  fprintf(fp, "10 column LA   :%-10d|\n",123);
  fprintf(fp, "10 column LA   :%-10d|\n",1234);
  fprintf(fp, "10 column LA   :%-10d|\n",12345);
 
  //
  // integers floating point data
  //
  fprintf(fp, "default        :%f|\n",123.);
  fprintf(fp, "default        :%f|\n",1234.);
  fprintf(fp, "default        :%f|\n",12345.);
  // fixed column width, right aligned, 2 decimal places shown
  fprintf(fp, "10 column RA   :%10.2f|\n",123.);
  fprintf(fp, "10 column RA   :%10.2f|\n",1234.);
  fprintf(fp, "10 column RA   :%10.2f|\n",12345.);
  // use engineering notation
  fprintf(fp, "10 column RA   :%10.2e|\n",123.);
  fprintf(fp, "10 column RA   :%10.2e|\n",1234.);
  fprintf(fp, "10 column RA   :%10.2e|\n",12345.);
  return 0;
}
