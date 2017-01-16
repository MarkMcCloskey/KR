/*
 Extend atof to handle scientific notation of the form 123.45e-6 where a
 floating-point number may be followed by e or E and an optionally signed
 exponent.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
double my_atof( char s[] );

int main(void){

	char test1[] = "123.45e-6";
	char test2[] = "123.45E-6";
	char test3[] = "123.45e6";
	char test4[] = "123.45";

	/* the printf contains .8f so that enough decimal digits are 
	   printed to show the number */
	printf("Testing example given.\n");
	printf("%.8f\n", my_atof(test1));
	printf("Testing capital E.\n");
	printf("%.8f\n", my_atof(test2));

	printf("Testing positive exponent.\n");
	printf("%f\n", my_atof(test3));
	printf("Testing no exponent.\n");
	printf("%f\n", my_atof(test4));
	return 0;
}

double my_atof(char s[]){
	
	double val, power;
	int i, sign, exp;

	for( i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1:1;    /* grab sign */

	if( s[i] == '+' || s[i] == '-' )/* skip sign */
		i++;

	for( val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + ( s[i] - '0');
	
	if( s[i] == '.')
		i++;

	for( power = 1.0; isdigit(s[i]); i++){
		val = 10 * val + (s[i] - '0');
		power *= 10.0;
	}

	val = sign * val / power;/* value up to this point */


	/* if there is exponential notation */
	if( s[i] == 'e' || s[i] == 'E' ){
	
		i++;/* skip to the next char */

		/* if the exponent is negative */
		if( s[i] == '-' ) {
			
			i++;/* skip to the exponent */
			exp = atoi(&s[i]);/* turn char exponent to int */
			
			/* divide by 10 the apropriate number of times to
			  shift the value properly */
			while( exp > 0 ){
				val /= 10;
				exp--;
			}

		/* if the exponent is positive */
		}else{
			exp = atoi(&s[i] );/* char exponent to int*/

			/*multiply by 10 appropriate number of times to
			  shift the value */
			while( exp > 0){
				val *= 10;
				exp--;
			}
		}
	
	}
	
	return val;
}

