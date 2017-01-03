/*
 Write a version of itoa that accepts three arguments instead of two. The
 third argument is a minimum field width; the converted number must be 
 padded with blanks on the left if necessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int width);
void reverse( char s[] );

int main( int argc, char* argv[] ){
	
	char s[10] = {'\0'};

	itoa(15, s, 4);
	printf("String: %s Length: %lu\n", s, strlen(s) );
	
	itoa(75, s, 9);
	printf("String: %s Length: %lu\n", s, strlen(s) );

	itoa(-13,s,7);
	printf("String: %s Length: %lu\n", s, strlen(s) );

	itoa(1,s,0);
	printf("String: %s Length: %lu\n", s, strlen(s) );
	return 0;
}

/* another very similar function except at the end a padding will occur */
void itoa( int n, char s[], int width){

	int i = 0, sign = 0;

	if( n < 0){
		sign = -1;
	}else{
		sign = 1;
	}

	do{
		s[i] = sign * ( n % 10 ) + '0';
		i++;
	}while( ( n/=10) != 0 );

	if( sign < 0 ){
		s[i] = '-';
		i++;
	}

	/* CHANGE: pad the string with necessary blanks */
	while( i < width ){
		s[i] = ' ';
		i++;
	}

	s[i] = '\0';
	reverse(s);
}

void reverse( char s[] ){
	
	int c = 0, i = 0, j = 0;

	for( i = 0, j = strlen(s) - 1; i < j; i++, j-- ){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}
