/*
   Write a function htoi(s) which converts a string of hexadecimal digits, 
   including an optional 0x or 0X, into its equivalent integer value. The 
   string may contain 0-9, a-f, and A-F.
 */

#include <stdio.h>
unsigned long htoi(char* hex);
unsigned long power(int base, int pow);

int main( int argc, char *argv[]){

	printf( "%lu\n", htoi(argv[1]) );

	/* Okay, hex is base 16 so every place is some power of 16. */
	return 0;
}

/*
   htoi will take as input a properly formatted string, including null
   character delimiter. It will return the integer value of that hex string.
 */
unsigned long htoi(char* hex){

	/*
PSUEDOCODE: 
1) Find the end of the hex string, if the string is not 
null character delimited this function will blow up.

2) work backwords towards start of string multiplying by the value found
there and the appropriate power of 16.

3)If optional hex lead is included, ignore it
	 */
	unsigned long value = 0;
	int i = 0;
	int pow = 0;
	int temp = 0;

	/*
	   Find the index of the end of the string, this is the least 
	   significant hex digit 
	 */
	while(hex[i] != '\0' && hex[i] != '\n'){
		i++;
	}
	
	for(i; i > -1; i--){
		/* do nothing when it's x or X*/
		if( hex[i] == 'x' || hex[i] == 'X'){
			/* do nothing */

		/* Handle the case where the hex digits are integers */
		}else if( hex[i] >= '0' && hex[i] <= '9'){
			temp = hex[i] - '0';
			value += temp*(power(16,pow));
			pow++;
			/* value = 16 * value + temp; */
		}else if( hex[i] >= 'a' && hex[i] <= 'f'){
			temp = 10 + hex[i] - 'a';
			/* value = 16 * value + temp; */
			value += temp*(power(16,pow));
			pow++;
		}else if( hex[i] >= 'A' && hex[i] <= 'F'){
			temp = 10 + hex[i] - 'A';
			/* value = 16 * value + temp; */
			value += temp*(power(16,pow));
			pow++;
		}else{
			/* strange value input*/	
		}
		

	}

	return value;

}

/*
 Quick function to calculate the power of 16 for me.
 */
unsigned long power(int base, int pow){
	
	unsigned long value = 1;
	
	while( pow > 0 ){
		value = value * 16;
		pow--;
	}
	
	return value;
	
/* Don't know why I made this recursive at first. Talk about overkill.
	if (pow == 0 ){
		return 1;
	}else{
		return base * power(base,--pow);
	}
*/

}

