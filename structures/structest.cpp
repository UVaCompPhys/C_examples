/* 
************************************************************************
*  structest.c: Program to illustrate use of C structure to            *
*  define complex numbers                                              *
*                                                                      *
*  compile with: g++ -Wall -O -o structest structest.c 		       *
*                                                                      *
************************************************************************
*/
#include <stdio.h> 
#include <math.h>


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
**   Output z^n for n = 0,1,...,119 for a complex number with unit modulus
**   that is close to one.
*/

int main()
{ 
   complex temp, z, prod;
   int n;

   temp.re = 1.0; temp.im = .05; 
   z = rdiv(temp,cnorm(temp));

   prod.re = 1.0; prod.im = 0.0;
    
   for(n=0; n<120; n++)
   {
      printf("%f\t%f\n", prod.re, prod.im);   /* print results */    
      prod = cmul(prod, z);
   }

   return(0);
}
