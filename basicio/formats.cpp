// Examples of formatted output

#include <stdio.h>
#include <math.h>

int main() {
 
  //
  // integers
  //
  printf("default        :%d|\n",123);
  printf("default        :%d|\n",1234);
  printf("default        :%d|\n",12345);

  // fixed column width, right aligned
  printf("10 column RA   :%10d|\n",123);
  printf("10 column RA   :%10d|\n",1234);
  printf("10 column RA   :%10d|\n",12345);

  // left aligned
  printf("10 column LA   :%-10d|\n",123);
  printf("10 column LA   :%-10d|\n",1234);
  printf("10 column LA   :%-10d|\n",12345);

  //
  // integers floating point data
  //
  printf("default        :%f|\n",123.);
  printf("default        :%f|\n",1234.);
  printf("default        :%f|\n",12345.);
  // fixed column width, right aligned, 2 decimal places shown
  printf("10 column RA   :%10.2f|\n",123.);
  printf("10 column RA   :%10.2f|\n",1234.);
  printf("10 column RA   :%10.2f|\n",12345.);
  // use engineering notation
  printf("10 column RA   :%10.2e|\n",123.);
  printf("10 column RA   :%10.2e|\n",1234.);
  printf("10 column RA   :%10.2e|\n",12345.);
  return 0;
}
