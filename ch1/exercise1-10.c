/* Exercise 1-10:  Write a program that prints its input to its output, 
   replacing each tab by \t, each backspace by \b, and each backslash by \\.
   this makes tabs and backspaces visible in an unambigous way.  */

#include <stdio.h>

int main(){
	int c;//input
	
	//While we haven't received end of file indicator get input
	while( ( c = getchar() ) != EOF){
		
		//if input is a tab, replace with \t
		if( c == '\t'){
			printf("\\t");

		/*Honestly, I'm not sure how to do the backspace thing as 
		  the terminal seems to handle it. */
	/*	}else if(c == 'BS'){
			putchar('\\b');

		//if input is a backslash, replace with \\
	*/	}else if(c == '\\'){
			printf("\\\\");
		
		//otherwise just print what is input.
		}else{
			putchar(c);
		}
	} 
}
