/*
 In a 2's complement number system x &= (x-1) deletes the rightmost 1-bit
 in x. Explain why. Use this observation to write a faster version of 
 bitcount
 */

#include <stdio.h>
#include <stdlib.h>
int bitcount( unsigned x);
int main(int argc, char* argv[]){
	
	printf("%u\n", bitcount( atoi(argv[1]) ));
	return 0;
}


/*
 Honestly, this was a cool/clever result that I'm happy I worked through. I 
 didn't fully understand what the problem meant until I did the math by 
 hand. Well played K&R.
 */
int bitcount(unsigned x){

	int i = 0;/* iterator */

	/* While x is not equal to zero, there remains a 1 bit in x. Every
	 time this loop is run the rightmost 1 bit is removed from x. The
	 iterator i will track how many 1 bits get removed. */
	for(i = 0; x != 0; i++){
	
		x &= (x-1);
	}

	return i;
}

