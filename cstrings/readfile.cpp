/************************************************************************
 *
 * Purpose: To display a file on the screen  (Unix 'cat' command).
 *	    Version 1
 *
 * to do:   Read file name from command line.
 *
 * Author:  M J Leslie
 * Date:    06-Feb-94
 * Modified: 10-Mar-07 B. Hirosky
************************************************************************/

#include <stdio.h>

int main()
{
  int c;    // Character read from the file.	
  FILE *file_ptr;     // Pointer to the file. FILE is a
	              // structure  defined in <stdio.h>

// Open some file for read access - no error checking done
  file_ptr = fopen("/etc/hosts","r");

// Read one character at a time, checking 
// for the End of File. EOF is defined 
// in <stdio.h>  as -1 			

  while (1){
    c =  fgetc(file_ptr);
    if (c==EOF) break;
    printf("%c",c);
  }
  fclose(file_ptr);			//Close the file.

  return 0;
}

