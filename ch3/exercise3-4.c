/*
 In a two's complement number system our version of itoa does not handle the
 largest negative number -(2^wordsize-1). Explain why not. Modify it to 
 print that value correctly regardless of the machine it is run on.
 */

#include <stdio.h>
void itoa(int n, char s[]);
void reverse(char s[]);
int strlen( char s[] );

int main( int argc, char* argv[]){

	char largest_neg = -128;
	char s[10] = { '\0' };

	itoa(largest_neg,s);
	printf("%s\n",s);
	
	return 0;
}

void itoa(int n, char s[]){

	int i = 0, sign = 0;

	/* decide whether n is negative or positive */
	if( n < 0){
		sign = -1;
	}else{
		sign = 1;
	}

	do{	/* generate digits in reverse order */
		s[i] = sign * (n % 10) + '0';
		i++;

	}while( (n/=10) != 0); /* delete the digit */

	/* insert sign into string if necessary */	
	if(sign < 0){
		s[i] = '-';
		i++;
	}

	s[i] = '\0'; /* terminate string */
	reverse(s);
}

/* Reverse a string in place, this function given in book. */
void reverse(char s[]){

	int c = 0, i = 0, j = 0;

	for ( i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}

/* return length of s, also given in book. */
int strlen ( char s[]){

	int i = 0;

	while( s[i] != '\0' ){
		i++;
	}

	return i;
}

