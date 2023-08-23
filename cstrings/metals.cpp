// Solution to Brooks Chapter 7, Problem 5
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
  char name[21];
  char symbol[3];
  float density;
} mdata;

// convert a string to lower case 
//   Note: this is a little dangerous - if a string does not contain 
//   a NULL terminator, the for loop may overwrite our other data!
void lower_case(char* str){
  unsigned int i;
  for (i=0; i<strlen(str); i++) str[i] = (char)tolower(str[i]);
  return;
}

int main(){
  const int MAX_ENTRIES=50;
  mdata metals[MAX_ENTRIES];  // array of MAX_ENTRIES structures
  FILE *data_f;
  int i, status, nelements=0;
  char lookup[21];

  // read data from file
  data_f=fopen("metals.dat","r");
  if ( data_f==NULL ){
    printf("Error: file not found!\n");
    return 1;
  }

  for (i=0 ; i<MAX_ENTRIES ; i++){
    status=fscanf(data_f,"%s %s %f",metals[i].name, 
		  metals[i].symbol, &(metals[i].density));
    if (status==EOF) break;
    lower_case(metals[i].name);
    nelements++;
  }
  printf("%d metals read from file\n",nelements);
  fclose(data_f);

  // user interaction loop
  while(1){
    printf("Which metal do you want me to lookup? [enter q to quit]\n");
    scanf("%s",lookup);
    lower_case(lookup);
    if (lookup[0]=='q') break;
    printf("data corresponding to \"%s\":\n",lookup);
    bool found=false;
    for (i=0; i<nelements ; i++){
      if (!strncmp(metals[i].name,lookup,strlen(lookup))) {
	printf("%20s %3s %5.2f[gm/cm^3]\n\n",
	       metals[i].name,metals[i].symbol,metals[i].density);
        found=true;
      }      
    }
    if (!found) printf("Sorry, data for \"%s\" not found\n\n",lookup);
  }
  return 0;
}
