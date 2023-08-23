// Examples of common i/o operations in C and C++ style
// Use this code as a template for your own programs

#include <stdio.h>    // header file for C-style i/o

#include <iostream>   // header and setup to
using namespace std;  // access C++ style i/o

int main(){
  // common variables types
  int ival;           // integer data
  float fval;         // float data
  double dval;        // double precision data
  char sval[100];     // a character string of size 100
                      // character strings are a little different
                      // we'll cover these in more detail later
  // assignments
  ival = 254;
  fval = 254.0;
  dval = 254.0;

  // printing various types of data
  printf("(1)**********\n");
  printf("ival = %d\n",ival);
  printf("fval = %f\n",fval);
  printf("dval = %lf\n",dval);
  printf("\n");

  // reading various data types
  printf("Please enter an integer\n");
  scanf("%d",&ival);
  printf("Please enter a decimal number\n");
  scanf("%f",&fval);
  printf("Please enter another decimal number \n");
  scanf("%lf",&dval);
  printf("Please enter a text string \n");
  scanf("%s",sval);  // !!! here we do not use the & character !!!
  printf("\n");

  // Print the new values
  printf("(2)**********\n");
  printf("ival = %d\n",ival);
  printf("fval = %f\n",fval);
  printf("dval = %lf\n",dval);
  printf("sval = %s\n",sval);
  printf("\n");

  // ***********
  // Now the same example using C++ style
  // ***********
  cout << "(3)**********" << endl;
  cout << "ival = " << ival << endl;
  cout << "fval = " << fval << endl;
  cout << "dval = " << dval << endl;
  cout << "sval = " << sval << endl;
  cout << endl;

  cout << "Please enter an integer" << endl;
  cin >> ival;
  cout << "Please enter a decimal number" << endl;
  cin >> fval;
  cout << "Please enter another decimal number" <<endl;
  cin >> dval;
  cout << "Please enter a text string" << endl;
  cin >> sval;
  cout << endl;

  cout << "(4)**********" << endl;
  cout << "ival = " << ival << endl;
  cout << "fval = " << fval << endl;
  cout << "dval = " << dval << endl;
  cout << "sval = " << sval << endl;
  cout << endl;

  return 0;  // return value, by convention 0 = SUCCESS
}
