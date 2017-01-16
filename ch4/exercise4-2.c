/*
 Extend atof to handle scientific notation of the form 123.45e-6 where a
 floating-point number may be followed by e or E and an optionally signed
 exponent.
 */

#include <stdio.h>

double atof( char s[] );
int is_digit( char c );

int main(void){
	
	return 0;
}

double atof(char s[]){
	
	double val, power;
	int i, sign;

	for( i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1:1;

	if( s[i] == '+' || s[i] == '-' )
		i++;

	for( val = 0.0; is_digit(s[i]); i++)
		val = 10.0 * val + ( s[i] - '0');
	if( s[i] == '.')
		i++;

	for( power = 1.0; is_digit(s[i]); i++){
		val = 10 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power;
}

int is_digit( char c){

	if( c >= '0' && c <= '9' ){
		return 1;
	}else{
		return 0;
	}

}
