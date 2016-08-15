#include <stdio.h>

/* Count characters in input; 1st version */

int main(){

	long nc;
	
	nc = 0;
	
	// while there is input count it	
	while( getchar() != EOF ){
		++nc;
	}	
	
	//print the number of characters counted
	printf( "%ld\n", nc);

}
