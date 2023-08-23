/* 
************************************************************************
*  structest3.c: Same as structest2.c but, in the main routine, the    *
*  filename is now chosen automatically, in a way that encodes the     *
*  input radius of z.                                                  *
*                                                                      *
************************************************************************
*/
#include <stdio.h> 
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

int main()
{ 
   complex temp, z, prod;
   double radius;
   FILE *outfile;
   int n;
   char filename[100];

   temp.re = 1.0; temp.im = .05; 
   z = rdiv(temp,cnorm(temp));

   prod.re = 1.0; prod.im = 0.0;
   
   printf("Enter radius parameter:\n");
   scanf("%lf", &radius);
   printf("radius = %f\n", radius);
   z = rmul(radius,z);

   sprintf(filename,"cmultest_r%.2f.dat", radius);
   printf("Data stored in %s\n", filename); 
   outfile = fopen(filename, "w");

   for(n=0; n<120; n++)
   {
      fprintf(outfile,"%f\t%f\n", prod.re, prod.im);  /* print results */    
      prod = cmul(prod, z);
   } 

   return(0);
}
