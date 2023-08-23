// Calculate drag force on a body moving in air
// This version reads it inputs from a file
// spefified on the command line
 
#include <stdio.h>
 
// constant values used within the program
const double RHO=1.23;             // density of air kg m^-3
const double SQFT_TO_SQM=0.09290;  // conversion of feet^2 to m^2 
const double HP_TO_WATT=746;       // conversion for watts to horsepower 
const double MPH_TO_MPS=0.477;     // conversion miles/hr to meters/s 
 
int main(int argc, char *argv[]) {
 
  float mph, area, coef;    // read from a file
  float mps, sq_m, drag_force, power;

  if (argc<2) {
    printf("No input file name entered\n");
    printf("Usage: dragforce_fio2 [filename]\n");
    return 1;
  }
  else printf("Reading data from file: %s\n",argv[1]);
  FILE *fp;  // define a "file pointer" to represent the data file
  fp = fopen(argv[1],"r");  // open the file for reading
  
 
  fscanf(fp,"%f",&mph); 
  fscanf(fp,"%f",&area);
  fscanf(fp,"%f",&coef);
 
  printf("Read inputs: mph %f, area %f, coef %f\n",mph,area,coef);

  // calculation of drag force F_D = (RHO/2)*v^2*A*C_d (Newtons)
  
  mps = mph * MPH_TO_MPS;       // speed in m/s
  sq_m = area * SQFT_TO_SQM;    // area in m^2
  drag_force = (RHO/2.) * mps*mps * sq_m * coef;
 
  // calculation of power to overcome drag P = F_D * v (Watts)
 
  power = drag_force * mps;
 
  printf("\nTotal drag force = %6.2f (N)\n",drag_force);
  printf("Horsepower needed to overcome drag = %6.2f (HP)\n",
         power/HP_TO_WATT);
 
  return 0;
}
