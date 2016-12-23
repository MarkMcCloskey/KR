/*
   This program will reverse the input. 
 */

#include <stdio.h>
#define MAX_LINE 1000

int get_line(char line[], int maxline);
int reverse(char line[], int length);

int main(int argc, char* argv[]){

	int len;/* current line length*/
	char string[MAX_LINE];/*current line*/

	while( ( len = get_line(string, MAX_LINE) ) > 0 ){
	
		reverse(string,len);
		printf("%s",string);

	}	

	return 0;
}

int get_line(char s[], int lim){
	
	int c, i;

	for ( i = 0; i < lim - 1 && ( c = getchar() ) != EOF && c != '\n';
				i++){
		s[i] = c;
	}

	if( c == '\n'){
		s[i] = '\n';
		i++;
	}

	s[i] = '\0';
	
	return i;
}

int reverse(char s[], int length){

	
	int i = 0;
	char temp;
	
	for( i = 0; i < length; i++){
		temp = s[i];
		s[i] = s[length - i];
		s[length - i] = temp;
	}

	return 0;
}
