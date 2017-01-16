/*
 Write the function strrindex(s,t), which returns the rightmost occurrence 
 of t in s, or -1 if there is none.

 */

#include <stdio.h>


int strrindex(char s[], char t[]);
int strlen( char s[] );
#define TEST_LENGTH 10

int main(int argc, char* argv[]){

	char s[TEST_LENGTH] = "hasta";
	char t[TEST_LENGTH] = "a";

	printf("Rightmost occurrence should be 4, is %d.\n", strrindex(s,t));
	return 0;
}

/*
 What I'll do is modify their function so that it starts from the right
 and returns the first match found.
 */
int strrindex(char s[], char t[]){
	
	int i, j, k;

	for( i = strlen(s); i >= 0; i--){
		for( j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++,k++)
			;
		if(k > 0 && t[k] == '\0')
			return i;
	}
	return -1;

}

int strlen( char s[] ){

	int i;

	i = 0;
	while( s[i] != '\0' ){
		++i;
	}
	return i;
}
