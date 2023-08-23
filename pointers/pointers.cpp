// example of pointer usage in function call
// See Brooks Chapter 5, Exercise 3

#include <stdio.h>
#include <math.h>

void point_calcs (double x1, double y1, double x2, double y2, 
            double *distance, double *midpoint_x, double *midpoint_y) {
  *distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  *midpoint_x = 0.5 * (x1 + x2);
  *midpoint_y = 0.5 * (y1 + y2);
}


// performs are reflection operation on a vector
void mirrorme(double *x, double *y, double *z){
  *x = -1.0 * (*x);
  *y = -1.0 * (*y);
  *z = -1.0 * (*z);
}

int main () {
  double x1, x2, y1, y2, distance, midpoint_x, midpoint_y;
  printf("Enter the coordinates of the first point: x y \n");
  scanf("%lf %lf", &x1, &y1);
  printf("Enter the coordinates of the second point: x y \n");
  scanf("%lf %lf", &x2, &y2);
  point_calcs(x1, y1, x2, y2, &distance, &midpoint_x, &midpoint_y);
  printf("The distance between the points is: %.3lf\n", distance);
  printf("The midpoint is: (%.3lf, %.3lf)\n", midpoint_x, midpoint_y);
  printf("\n");
  double x=1.0, y=2.0, z=3.0;
  printf("My vector = (%lf,%lf,%lf)\n",x,y,z);
  mirrorme(&x,&y,&z);
  printf("My mirror vector = (%lf,%lf,%lf)\n",x,y,z);
}
