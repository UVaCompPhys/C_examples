// calculate the amount of an elemental radioactive material that 
//   remains after a certain number of halflife times 

#include<stdio.h>
#include <math.h>

double undecayed(double num_half_lifes);

int main(){
  int i;
  float half_lifes;
  FILE *outp;

  outp = fopen("decay.dat","w");  // check for successfull file
  if (!outp) {                    // system access
    printf("file error\n");
    return 1;
  }

  printf("#t/t_half  fraction remaining\n");
  for (i=0 ; i<11 ; i++) {
    half_lifes = (double)i;
    printf("%9.2f %6.3f\n", half_lifes, undecayed(half_lifes));
    fprintf(outp,"%5.2f %6.3f\n", half_lifes, undecayed(half_lifes));
  }

  fclose(outp);
  return 0;
}

// return fraction of material remaining after num_half_lifes

double undecayed(double num_half_lifes) {
  return pow(0.5, num_half_lifes);
}
