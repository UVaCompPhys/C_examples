// See Brooks Chapter 6, Exercise 3,
// Calculate the interpolated y-value between any two points in 
// the input data file.
//
// This program shows an example of simple array usage.
// The data file: interp2.dat is used as input
//
// Usage: interp2 [number]
// Reads in a data file of x,y coordinates.  Given an input value
// of x, use linear interpolation to estimate the corresponding y
// value

#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 100          // max size of arrays
#define DATAFILE "interp2.dat"  // name of data file

int main(int argc, char *argv[]){
  double xval,yval;
  FILE* tablep;
  int status;
  double x[MAX_POINTS], y[MAX_POINTS];
  double x1,y1,x2,y2;
  int npoints=0;  // number of points in the table
  int i;

  if (argc <2){
    printf("Error. Not enough arguments\n");
    printf("Usage: interp2 <float>\n");
    return 1;
  }
  xval = atof(argv[1]);
  
  // open file and check for success
  tablep = fopen(DATAFILE,"r");
  if (!tablep){
    printf("Unable to open data file\n");
    return 1;
  }
  
  // read entries from data file up to MAX_POINTS number defined above 
  //  We assume that the entris are ordered by increasing x values 
  for (i=0; i<MAX_POINTS; i++){
    status = fscanf(tablep,"%lf %lf",&x[i],&y[i]);
    if (status == EOF) break;
    npoints++;
  }
  fclose(tablep);

  // check for valid interpolation point and find surrounding points
  if (xval<x[0] || xval>x[npoints-1]){
    printf("Error: %f is out of range [%f:%f]\n",xval,x[0],x[npoints-1]);
    return 1;
  }

  // find pair of points for interpolation
  i=0;  // note x2 can NEVER be the 1st element of our array
  do {
    i++;
    x2 = x[i];
  } while (xval>x2);
  y2 = y[i];
  x1 = x[i-1];
  y1 = y[i-1];

  // do final calculation
  yval = y1 + (y2-y1) * (xval-x1) / (x2-x1);
  printf("Interpolated point = (%f,%f)\n",xval,yval);
  return 0;
}

