/* 

This is a copy from the book, it will read input lines and track the longest.  
At the end of the program it will then print the longest line. 

*/

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line*/
int main(){
	int len; //current line length
	int max; //longest line length
	char line[MAXLINE]; //current input line
	char longest[MAXLINE]; //save longest line here

	max = 0;
	
	/*
	While there is input with length greater than 0 
	*/
	while( (len = get_line(line, MAXLINE) ) > 0 ){
		
		// if the length is greater than what we've seen so far
		if( len > max ){
			max = len;//track new max length
			copy(longest,line);//copy new longest input line
		}
	}
	
	//if there was input, print the longest
	if(max > 0){
		printf("%s", longest);
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

/*
copy 'from' into 'to'
*/
void copy( char to[], char from[]){
	
	int i = 0;
	
	/*
	read through a character array copying from into to until the null
	character is found
	*/
	while( (to[i] = from[i]) != '\0' ){
		++i;
	}
}
