// compile with: g++ -o gpa gpa.cpp
// this program needs the file called grades.dat to be 
// in the same directory where you run the program

#include <stdio.h>

int main() {

  FILE *inFile;
  int idnum;
  float gpa, credits, new_credits, new_grade;
  int status;
  char title[100];  // a string with 100 storage elements

  inFile = fopen("grades.dat","r");   // open the grades file
  if (inFile==NULL) {                 // exit program if file not found
    printf("Error: grades.dat not found!!\n");
    return 1;
  }

  // read the 1st line into a string, fgets as called below places
  // up to 80 characters from the 1st line of this file into the "title"
  // string.
  fgets(title,80,inFile);

  // The following loop structure is ahead of the material we're covering 
  // in class this week, but you should find this easy to modify for 
  // your own needs

  printf("ID #        GPA   Credits  New Credits  New Grade\n");
  while (1) {                         // read the lines of data
    status = fscanf(inFile,"%d %f %f %f %f",
                    &idnum,&gpa,&credits,&new_credits,&new_grade);
    if (status==EOF) break;
    printf("%9d %6.2f %7.1f %12.1f %9.2f\n",idnum,gpa, 
	   credits, new_credits, new_grade);
  }

  fclose(inFile);
  return 0;
}
