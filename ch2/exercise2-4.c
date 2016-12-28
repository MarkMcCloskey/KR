/*
 Write an alternate version of squeeze, squeeze(s1,s2) that deletes 
 each character in s1 that matches any character in the string s2.

 */

#include <stdio.h>
void squeeze1(char s[], int c);
void squeeze2(char s1[], char s2[]);


/*
 Here I will expect s1 and s2 for squeeze to come from the arguments to the 
 program.
 */
int main(int argc, char* argv[]){

	if( argc < 3){
		printf("Incorrect number of arguments, try again.\n");
	}else{
	
		squeeze2( argv[1], argv[2] );
		printf("%s\n",argv[1]);
	
	}
	return 0;

}

/* Given in book: delete all c from s.*/
void squeeze1(char s[], int c){

	int i, j;

	for( i = j = 0; s[i] != '\0'; i++){
		if(s[i] != c){
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

/* squeeze 2 will take two strings as input, it will then remove all 
 characters in the second string from the first string.
 */
void squeeze2(char s1[], char s2[]){

	int i, j;
	i = j = 0;
	/* 
	   Initially I was going to write this function myself but, why when
	 they've so conveniently given me all I need?
	 */
	for( i = 0; s2[i] != '\0'; i++){
		/* remove all characters in s2 from s1 */
		squeeze1(s1,s2[i]);
	}

}
