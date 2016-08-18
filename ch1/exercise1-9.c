#include <stdio.h>

/* Write a program to copy its input to its ouput replacing one or more blanks
  with a single blank. 
  
  Although I'm not super happy with this in its current state, for being quick
  and dirty it seems to work.

  Undefined behavior: how should it handle tabs?  Are tabs not three blanks?
  Easily fixed I think with a check == '\t' if necessary.
*/

int main(){
	
	int character;
	
	//while the input isn't the end of file
	while( (character = getchar()) != EOF ){
		
		//if we encounter a blank
		if( character == ' ' ){
			
			//print the first blank
			putchar(character);
			
			//if more blanks come
			while( ( character = getchar() ) == ' '){ 
				//do nothing
			}

			/*print when you find a non blank and then start the
			 process over */
			putchar(character); 
		
		//otherwise just print what was input
		}else{
		
			putchar(character);
	
		}	
	}
}
