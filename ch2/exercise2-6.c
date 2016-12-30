/*
 Write a function, setbits(x,p,n,y), that returns x with the n bits that
 begin at position p set to the rightmost n bits of y, leaving the other
 bits unchanged.
 */

#include <stdio.h>
#include <stdlib.h>

int setbits(unsigned int x, int p, int n, int y);

int main(int argc, char* argv[]){
	/*int x = 0;i
	x = setbits(207,5,2,3);
	printf("%d\n",x);*/

	printf("%u\n", setbits( atoi(argv[1]), atoi(argv[2]), atoi(argv[3]),
				atoi(argv[4])));
	return 0;
}

/*
 This exercise took way more work than I originally expected and I'm 
 probably doing more work than necessary but,

 In order to do this my plan is
 	1) Create a mask to rip out the n bits to be set in x -> temp
	2) Create a mask to copy the rightmost n bits of y -> right_of_y
	3) Shift rightmost of y over to p and then return temp + right_of_y

 This should fill the correct bits in the newly created hole in x.
 */
int setbits(unsigned int x, int p, int n, int y){

	unsigned int temp = 0;/* will be used to mask out the bits in x*/
	unsigned int right_of_y = 0;/* grab rightmost n bits of y*/
	int i = 0;
	
	/*
	 fill right_of_y and temp with 1's in the n right-most n columns
	 */
	while( i < n){
		temp <<= 1;
		temp += 1;
		right_of_y <<= 1;/* shift the current 1's left once*/
		right_of_y += 1;/* fill the 1's spot with another 1*/
		i++;
	}

	/* AND right_of_y with y. This yields the rightmost n columns of y*/
	right_of_y &= y;
	right_of_y <<= (p - n + 1);/* shift the value to where we need it*/

	temp <<= (p - n + 1); /* Shift the ones so that they start at p*/
	temp = ~temp; /*flip all the bits so that there is a zero mask now*/
	/*This will zero out the n bits at p and leave everything else*/
	temp &= x;
	
	return temp + right_of_y;
}
