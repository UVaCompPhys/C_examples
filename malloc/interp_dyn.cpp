// Calculate the interpolated y-value between any two points in 
// the input data file.
// Usage: interp_dyn [number], where number is a value xmin<x<xmax
//        with respect to the input file, random.csv
 
 
#include <stdio.h>
#include <stdlib.h>
 
const char *DATAFILE="random.csv";
const int MAX_ALLOC=1000;
 
int readData(double *x, double *y);
double interpolate(double *x, double *y, int npoints, double xval);
 
int main(int argc, char *argv[]){
  double xval,yval;
  double *x;
  double *y;
  int npoints=0;  // number of points in the table
 
  if (argc <2){
    printf("Error. Not enough arguments\n");
    printf("Usage: interp <float>\n");
    return 1;
  }
  xval = atof(argv[1]);
 
  /*************************
  How big do the arrays need to be?
  There are many ways to approach this problem:
  1) Use file system calls to figure out how many lines are 
     in the file
  2) Read through the file to determine how many lines are present
  3) Use fseek/ftell to determine the file length 
  4) Start with arrays of some initial size, say 100 elements.
     Then use realloc to lenghten the arrays as needed until
     all data are read.
     ...
  We will use the 'big enough' approach here and simply allocate an
  array of MAX_ALLOC entires dynamically to keep the example simple
  **************************/
 
  // Dynamically creating x,y arrays to be MAX_ALLOC elements
  // Nasty magic number used!  For demonstration purposes only!
  x = (double*)malloc(sizeof(double)*MAX_ALLOC);
  y = (double*)malloc(sizeof(double)*MAX_ALLOC);
 
 
  // get data table
  npoints=readData(x, y);
  if (npoints<0) return 1;
 
  // check for valid interpolation point and find surrounding points
  if (xval<x[0] || xval>x[npoints-1]){
    printf("Error: %f is out of range [%f:%f]\n",xval,x[0],x[npoints-1]);
    return 1;
  }
 
  yval=interpolate(x, y, npoints, xval);
 
  printf("Interpolated point = (%f,%f)\n",xval,yval);
 
  // release memory back to the OS when we are finished
  free((void*) x);
  free((void*) y);
}
 
int readData(double *x, double *y){
  FILE* tablep=fopen(DATAFILE,"r");
  if (!tablep) {
    printf("Error: Unable to open data file\n");
    return -1;
  }
  // read entries from data file up to MAX_POINTS number defined above 
  //  We assume that the entris are ordered by increasing x values 
  int npoints=0;
  for (int i=0; i<MAX_ALLOC; i++){
    int status = fscanf(tablep,"%lf %lf",&x[i],&y[i]);
    if (status == EOF) break;
    npoints++;
  }
  fclose(tablep);
  return npoints;
}
 
 
double interpolate(double *x, double *y, int npoints, double xval){
  int i;
  double x1,y1,x2,y2;
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
  return  y1 + (y2-y1) * (xval-x1) / (x2-x1);
}

