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
	int imin = -1, imax = 1 ;
	long lmin = -1 , lmax = 1;
	

	printf("First, the printed library values:\n");
	printf("Char (Signed/Unsigned): %d..%d/%u..%u\n", SCHAR_MIN,	
			SCHAR_MAX, 0,CHAR_MAX);
	printf("Short (Signed/Unsigned): %d..%d/%d..%d\n", SHRT_MIN,
			SHRT_MAX,0, USHRT_MAX);
	printf("Int (Signed/Unsigned): %d..%d/%d..%u\n",INT_MIN
			,INT_MAX,0 ,UINT_MAX);
	printf("Long (Signed/Unsigned): %ld..%ld/%d..%lu\n", LONG_MIN,
			LONG_MAX, 0, ULONG_MAX);


	printf("\nNow let's try to compute these values.\n\n");
	
	/*For the computation part, the basic idea is to manipulate the
	 underlying bits. Continue to increase/decrease
	 the stored value until just before a rollover would occur. At this 
	 point, you have reached the limit to the storage range. */
	
	while ( (cmax - 1) < 0 ){
		cmax = cmax -1;
	}
	while( (cmin +1) > 0 ){
		cmin = cmin + 1;
	}
	printf("Char: %d..%d\n", cmin,cmax);

	
	while( (smin - 1)  < 0 ){
		smin = smin - 1 ;
	}
	while( (smax * 2) > 0 ){
		smax = smax*2;
	}
	printf("Short: %hd..%hd\n", smax, smin);

	while( (imin * 2) < 0 ){
		imin = imin * 2;
	}
	while( (imax * 2) > 0 ){
		imax = imax * 2;
	}
	printf("Int: %d..%d\n",imin,imax*2 - 1);

	while (lmin * 2 < 0){
		lmin = lmin*2;
	}

	while( lmax *2 > 0 ){
		lmax = lmax*2;
	}
	printf("Long: %ld..%ld\n", lmin, lmax*2 - 1);
	
	return 0;
}
