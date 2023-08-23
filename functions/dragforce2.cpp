// Dragforce program with user defined finctions
 
#include <stdio.h>
 
// function prototypes
float sqft_to_sqm(float sqft);
float watt_to_hp(float watt);
float mph_to_mps(float mph);
float drag_force(float mps, float area, float coef);
 
int main() {
 
  float mph, area, coef;  // read from keyboard
  float mps, sq_m, force, power;
 
  /* we prompt the user for each piece of data and clear the input buffer
     after each read just in case someone enteres too much data for a 
     given request */
 
  printf("Enter Speed of object (mph): ");
  scanf("%f",&mph);
 
  printf("Enter Area of object (feet^2): ");
  scanf("%f",&area);
 
  printf("Enter Drag Coefficient of object (0.2-0.5): ");
  scanf("%f",&coef);
 
  // calculation of drag force F_D = (rho/2)*v^2*A*C_d (Newtons)
  mps = mph_to_mps(mph);       // speed in m/s 
  sq_m = sqft_to_sqm(area);    // area in m^2 
  force = drag_force(mps,sq_m,coef);
 
  // calculation of power to overcome drag P = F_D * v (Watts)
  power = force * mps;
 
  printf("\n\nTotal drag force = %6.2f (N)\n",force);
  printf("Horsepower needed to overcome drag = %6.2f (HP)\n",
	 watt_to_hp(power));
 
  return 0;
}
 
// Any "magic numbers defined below are confined to 1-line
// functions.  No readability issues here.
 
//convert feet^2 to meter^2
float sqft_to_sqm(float sqft) { return sqft * .09290; }
 
//convert watts to horsepower
float watt_to_hp(float watt) { return watt / 746.; }
 
//convert mph to meter/s
float mph_to_mps(float mph) { return mph * 0.447; }
 
//calculate drag force
float drag_force(float mps, float area, float coef){
  const float RHO = 1.23;   /* density of air, defined as a constant 
			       or "unalterable" value*/
  return RHO/2.0 * mps*mps * area * coef;  
}

