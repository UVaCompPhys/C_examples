/* 
************************************************************************
*  structest4.c: Same as structest2.c but now both inputs in the main  *
*  program are taken from the command line.  Run the program as        *
*                                                                      *
*      structest4  <radius>  <filename>                                *
*                                                                      *
*  If there is no second argument, standard output is used.            *
*                                                                      *
************************************************************************
*/
#include <stdio.h> 
#include <stdlib.h>       /* for abort() */
#include <math.h>

#define PI 3.1415926535897932385E0

typedef struct{
  double re;
  double im;
} complex;

/* rmul             - multiply real number and complex number         */
/* rdiv             - fivide complex number by real number            */
/* cmul, cadd, csub - multiply, add, or subtract two complex numbers  */
/* cnorm            - absolute value (modulus) of complex number      */

complex rmul(double lambda, complex y)
{
   complex ytemp;
   ytemp.re = lambda * y.re;
   ytemp.im = lambda * y.im;
   return ytemp;
}

complex rdiv(complex y, double lambda)
{
   complex ytemp;
   ytemp.re = y.re / lambda;
   ytemp.im = y.im / lambda;
   return ytemp;
}

complex cmul(complex x, complex y)
{
   complex z;
   z.re = x.re*y.re - x.im*y.im;
   z.im = x.re*y.im + x.im*y.re;
   return z;
}

complex cadd(complex a, complex b)
{
   complex c;
   c.re = a.re + b.re;
   c.im = a.im + b.im;
   return c;
}

complex csub(complex a, complex b)
{
   complex c;
   c.re = a.re - b.re;
   c.im = a.im - b.im;
   return c;
}

double cnorm(complex a)
{
   return sqrt((double)(a.re*a.re + a.im*a.im));
}


/* Example:
**   Output z^n for n = 0,1,...,119 for a complex number near the real axis
** whose modulus (radius) is input.
*/

int main(int argc, char *argv[])
{ 
   complex temp, z, prod;
   double radius;
   FILE *outfile;
   int n;

   if (argc < 2 || argc > 3) {
     printf("Usage: stuctest4 <radius> [outputfilename]\n");
     abort();
   }

   temp.re = 1.0; temp.im = .05; 
   z = rdiv(temp,cnorm(temp));

   prod.re = 1.0; prod.im = 0.0;
   
   sscanf(argv[1],"%lf", &radius);
   printf("radius = %f\n", radius);
   z = rmul(radius,z);

   if (argc < 3) {
     outfile = stdout;
   }
   else {
     printf("Data stored in %s\n", argv[2]); 
     outfile = fopen(argv[2], "w");
     if (outfile == NULL) {
       printf("Could not open output file.\n");
       abort();
     }
   }

   for(n=0; n<120; n++)
   {
      fprintf(outfile,"%f\t%f\n", prod.re, prod.im);  /* print results */    
      prod = cmul(prod, temp);
   } 

   return(0);
}
