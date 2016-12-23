/*
Exercise 1-18:  Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines.
*/

#include <stdio.h>
/* #define DEBUG 0 */

#define LINE_LENGTH 1000
int get_line(char line[], int maxline);
int remove_blanks(char new[], int end);

int main(){
	
	int len; /* current line length */
	char string[LINE_LENGTH];/*current line*/

	/* while there's some input */
	while( ( len = get_line(string, LINE_LENGTH) ) > 0 ){
		#if defined(DEBUG)
			printf("In Main While loop\n");
			printf("Original string length: %d\n", len);
		#endif
		
		len = remove_blanks(string, len);
	
	#if defined(DEBUG)
		printf("String length after removing blanks: %d\n", len);
	#endif
		/* only print the string if it contains an actual character
		 * not just a newline */
		if(len > 1){
			printf("%s",string);
		}
	
	}
	
	return 0;
}

int get_line(char s[], int lim){
	
	int c, i;

	for( i = 0; i < lim - 1 && ( c = getchar() ) != EOF && c != '\n'; i++){
		s[i] = c;
	}
	
	if( c == '\n'){
		s[i] = '\n';
		i++;
	}

	s[i] = '\0';
	return i;
}

/*
Remove blanks will take a character array and the length of that array.  It
will then remove any trailing blanks, tabs, and completely delete blank
lines.  It will then return an integer that is the length of the new line.
*/
int remove_blanks(char s[], int length){
	int i = length;
	
	#if defined(DEBUG)
		printf("In remove_blanks\n");
	#endif
	/* while there's still a blank at the end of the string decrement
	   i */
	for( i = length; i > -1 && (s[i] == ' ' || s[i] == '\t'|| s[i] == '\n' || s[i] == '\0'); i--){
	}
	
	/*once we've found a legit character we need to insert endline and
	  null char */
	s[i + 1] = '\n';
	s[i + 2] = '\0';
	/* account for newline*/
	return ++i;
}
