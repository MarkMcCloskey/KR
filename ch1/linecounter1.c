#include <stdio.h>

/* Count lines in input. */

int main(){
	
	int c, nl;

	nl = 0;

	/* while reading input */	
	while( ( c = getchar() ) != EOF ){
		/* if a newline is encountered, count it */
		if( c == '\n' ){
			++nl;
		}
		
	}
	
	//print the number of lines counted
	printf( "%d\n", nl);

}	
