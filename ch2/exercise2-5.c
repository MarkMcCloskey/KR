/*
 Write the function any(s1, s2) which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
 */

#include <stdio.h>

int any(char s1[], char s2[]);

int main(int argc, char* argv[]){

	if( argc < 3){
		printf("Too few arguments, try again.\n");
	}else{

		printf( "%d\n", any(argv[1],argv[2]) );
	
	}
	return 0;
}

int any(char s1[], char s2[]){
	
	int index = -1;
	int i = 0;
	int j = 0;

	/*
	   for each character in s1, traverse s2 checking for matches. If
	   a match is found, return the index it is found at. Otherwise,
	   fall through and return -1.
	 */
	for( i = 0; s1[i] != '\0'; i++){

		for(j = 0; s2[j] != '\0'; j++){
			if(s1[i] == s2[j])
				return i;
		}
	}

	return index;
}
