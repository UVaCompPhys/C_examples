// Exmaple of switch statement
// Lower/upper case A/B will fire one of the 1st code blocks
// Lower/upper case C's are treated differently
// Instead of charaster variables, integers may also be used in the 
// switch structure

#include <stdio.h>
int main(){
  char letter;
  printf ("Enter your favorite letter\n");
  scanf("%s", &letter);
  switch (letter) {
  case 'a':
  case 'A':
    printf("A is for Aardvark\n");
    break;
  case 'b':
  case 'B':
    printf("B is for Bear\n");
    break;
  case 'c':
    printf("c is for Cat\n");
    break;
  case 'C':
    printf("C is for Coelacanth\n");
    break;
  default:
    printf("I don't know that letter\n");
  }
}
