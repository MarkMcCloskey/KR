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
	
		reverse(string,len - 1);
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

/*
 reverse will take a character array that is a string and the length of
 the string as input. It will then reverse the string in place.

 Mark, even though we haven't read about it in the book you could allocate
 space for a new string and return a pointer to that. Also, the behavior doesn't seem as "well-behaved" as I would like, maybe go back and fix that?
 */
int reverse(char s[], int length){

	int i = 0; /* iterator*/
	int temp;  /* temp for character swapping */
	
	/* iterate through half the string swapping that index with the
	 corresponding one in the second half of the string. */
	for( i = 0; i < length/2; i++){
		temp = s[i];
		s[i] = s[length - i];
		s[length - i] = temp;
	}
	
	/* add the newline at the end of the string and then delimit it.
	 
	   I believe this is where the behavior gets a little weird, 
	 possibly adding extra newlines. */
	s[length+1] = '\n';
	s[length +2] = '\0';

	return 0;
}
