/*
 Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted, leaving the others unchanged.
 */

#include <stdio.h>
#include <stdlib.h>
unsigned int invert(unsigned int x, int p, int n);

int main(int argc, char* argv[]){

	/* just call function from command line and output is printed */
	printf("%u\n",invert( atoi(argv[1]), atoi(argv[2]), atoi(argv[3]) ));
	return 0;
}


/*
 To accomplish this, a simple XOR should do the trick with a mask of 1 bits
 over the p+n - 1 bits.
 */
unsigned int invert(unsigned int x, int p, int n){
	
	unsigned int mask = 0;/* contains the mask of 1 bits */
	int i = 0; 
	
	/* Create an n bit mask */
	for( i = 0; i < n; i++){
		mask <<= 1;
		mask +=1;
	}

	mask <<= (p - n + 1);/* shift the mask to the correct place */
	
	return x ^ mask;/* return x with the bits inverted */ 
}


