/* This is a copy from the book.  This program will count digits, white space,
   and others using an array.*/
#include <stdio.h>

int main(){

	int c, i , nwhite , nother;
	int ndigit[10];

	nwhite = nother = 0;
	
	//initialize elements of array to = 0
	for( i = 0; i < 10; i++){
		ndigit[i] = 0;
	} 

	/* while there is input and it's not the end of a file */
	while( ( c = getchar()) != EOF ){
		
		/* if c is a digit add to its count  */
		if( c >= '0' && c <= '9' ){
			++ndigit[c-'0'];//kind of a weird way to write this..
					//I think because we're reading it in
					//as an int, we need to get it's value
					//to 0-9, so subtract value of '0'
		
		//if whitespace count it
		}else if( c == ' ' || c == '\n' || c == '\t' ){
			++nwhite;
		
		//otherwise count everything else
		}else{
			++nother;
		}

		
	}
	
	//print the counts with light formatting
	printf("digits = ");
	for( i = 0; i < 10; i ++){
		printf( "%d ", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother );		
}
