
// Calculate the interpolated y-value between any two points in 
// the input data file.
// Usage: interp [number], where number is a value xmin<x<xmax
//        with respect to the input file, interp.dat


#include <stdio.h>
#include <stdlib.h>

// Here use fix the array size to a number that's 'big enough'
// to handle out input file.  This obviously will fail if the
// input file contains >MAX_POINTS entries.
const int MAX_POINTS=100;
const char *DATAFILE="interp.dat";

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
    printf("Usage: interp <float>\n");
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
}









