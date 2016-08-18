#include <stdio.h>

/* Exercise 1-12:  Write a program that prints its input one word per line. */

int main(){

	int c;
	
	/* While receiving input and the file hasn't ended*/
	while( ( c = getchar() ) != EOF){

		/* if we see any type of space */
		if( c == ' ' || c == '\n' || c == '\t' ){
			
			printf("\n");//finish the line and print a newline	
		
		//otherwise continue printing a word
		}else{
			putchar(c);
		}
	}
	
}
