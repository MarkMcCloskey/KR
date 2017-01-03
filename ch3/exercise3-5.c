/*
 Write the function itob(n,s,b) that converts the integer n into a base b
 character representation in the string s. In particular, itob(n,s,16) 
 formats n as a hexadecimal integer in s.
 */

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse( char s[]);

int main( int argc, char* argv[]){

	int test_num = 0;
	char converted[10];

	/* TEST BINARY */
	printf("Testing Binary\n");
	test_num = 0;
	itob( test_num, converted, 2);
	printf("%s\n", converted);
	memset(converted, '\0', 10);	
	
	test_num = 1;
	itob( test_num, converted, 2);
	printf("%s\n", converted);
	memset(converted, '\0', 10);
	
	test_num = 2;
	itob( test_num, converted, 2);
	printf("%s\n", converted);
	memset(converted, '\0', 10);
	
	test_num = 3;
	itob( test_num, converted, 2);
	printf("%s\n", converted);
	memset(converted, '\0', 10);

	/* TEST DECIMAL */
	printf("Testing Decimal\n");
	test_num = 5;
	itob( test_num, converted, 10);
	printf("%s\n", converted);
	memset(converted, '\0', 10);

	test_num = 10;
	itob( test_num, converted, 10);
	printf("%s\n", converted);
	memset(converted, '\0', 10);
	
	test_num = 15;
	itob( test_num, converted, 10);
	printf("%s\n", converted);
	memset(converted, '\0', 10);

	/* TEST OCTAL */
	printf("Testing Octal\n");
	test_num = 4;
	itob( test_num, converted, 8);
	printf("%s\n", converted);
	memset(converted, '\0', 10);

	test_num = 7;
	itob( test_num, converted, 8);
	printf("%s\n", converted);
	memset(converted, '\0', 10);

	test_num = 8;
	itob( test_num, converted, 8);
	printf("%s\n", converted);
	memset(converted, '\0', 10);
	
	/* TEST HEX */
	printf("Testing Hex\n");
	test_num = 9;
	itob( test_num, converted, 16);
	printf("%s\n", converted);
	memset(converted, '\0', 10);

	test_num = 10;
	itob( test_num, converted, 16);
	printf("%s\n", converted);
	memset(converted, '\0', 10);

	
	test_num = 15;
	itob( test_num, converted, 16);
	printf("%s\n", converted);
	memset(converted, '\0', 10);
	
	test_num = 16;
	itob( test_num, converted, 16);
	printf("%s\n", converted);
	memset(converted, '\0', 10);
	return 0;
}

/* This will be very similar to itoa I just wrote except for now we need to
 account for bases higher than 10. */
void itob(int n, char s[], int b){

	int i = 0, sign = 0, temp = 0;

	if( n < 0 ){
		sign = -1;
	}else{
		sign = 1;
	}

	do{	/* Here are the changes */
		temp = n % b; /* get digit value */

		/* if it is a numeric digit */
		if( temp <= 9 ){
			s[i] = sign * (temp + '0');
		/* otherwise it needs to be alphabetic */
		}else{
			s[i] = sign * (temp + 'a' - 10);
		}

		i++;
	}while( (n/=b) != 0);
	
	if( sign < 0 ){
		s[i] = '-';
		i++;
	}

	s[i] = '\0';
	reverse(s);
}

void reverse( char s[] ){

	int c = 0, i = 0, j = 0;

	for( i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

