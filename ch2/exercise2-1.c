/*
 This program will determine the ranges of char, short, int, and long 
 variables. Signed and unsigned.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(int argc, char* argv[]){
	char cmin = 0;
	char cmax = 0;
	short smin= -1 ,smax = 1;
	int imin = 0,imax = 0;
	long lmin = 0 , lmax = 0;
	

	printf("First, the printed library values:\n");
	printf("Char (Signed/Unsigned): %d..%d/%u..%u\n", SCHAR_MIN,	
			SCHAR_MAX, 0,CHAR_MAX);
	printf("Short (Signed/Unsigned): %d..%d/%d..%d\n", SHRT_MIN,
			SHRT_MAX,0, USHRT_MAX);
	printf("Int (Signed/Unsigned): %d..%d/%d..%u\n",INT_MIN
			,INT_MAX,0 ,UINT_MAX);
	printf("Long (Signed/Unsigned): %ld..%ld/%d..%lu\n", LONG_MIN,
			LONG_MAX, 0, ULONG_MAX);


	printf("Now let's try to compute these values.\n\n");
	
	/* Continue to add 1 until we reach the point where the stored value
	 would roll over and then stop. This will get you the max value 
	 stored in one direction. At first I thought I knew how this would 
	 work but then I found my variables were mixed up...*/
	
	while ( (cmax - 1) < 0 ){
		cmax = cmax -1;
	}
	while( (cmin +1) > 0 ){
		cmin = cmin + 1;
	}
	printf("Char: %d..%d\n", cmin,cmax);

	
	while( (smin * 2) < 0 ){
		smin = smin * 2 ;
	}
	while( (smax * 2) > 0 ){
		smax = smax*2;
	}
	printf("Short: %hd..%hd\n", smin, smax);
	
	
	return 0;
}
