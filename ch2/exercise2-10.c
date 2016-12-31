/*
 Rewrite the function lower, which converts upper case letters to lower 
 case, using the conditional expression instead of if else.
 */

#include <stdio.h>

int lower(int c);

int main( int argc, char* argv[]){

	printf("%c\n", lower('Z'));
	return 0;
}

int lower(int c){

	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;

}
