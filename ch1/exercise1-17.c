/* 
Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAXLINE 1000
#define LENGTH_TO_PRINT 80

int get_line(char line[], int maxline);

/* print longest input line*/
int main(){
	int len; //current line length
	char line[MAXLINE]; //current input line

	
	/*
	While there is input with length greater than 0 
	*/
	while( (len = get_line(line, MAXLINE) ) > 0 ){
		
		//if there was input, print the longest
		if( len > LENGTH_TO_PRINT ){
			printf("%s", line);
		}	
	
	}
	return 0;
}

/* read a line into s, return length */
int get_line(char s[], int lim){

	int c, i;
	
	//read input until: the limit is reached, EOF is found, or a newline is
	//encountered.  Copy the input into a char array
	for( i = 0; i < lim - 1 && (c = getchar() ) != EOF && c != '\n'; i++){
		s[i] = c;
	}
	
	//if we find a newline, put it into the char array
	if( c == '\n' ){

		s[i] = c;
		i++;
	}
	//then end the array with the null character
	s[i] = '\0';
	return i;//return number of chars read
}


