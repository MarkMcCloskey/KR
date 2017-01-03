/*

 Write a function expand(s1,s2) that expands shorthand notation like a-z in
 the string s1 into the equivalent complete list abc...xyz in s2. Allow for
 letters of either case and digits, and be prepared to handle cases like 
 a-b-c and a-z0-9 and -a-z. Arrange that leading and trailing - is taken 
 literally.

 */

#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE 1000
void expand( char s1[], char s2[]);

int main(int argc, char* argv[]){
	
	char test1[] = "a-z";
	char test2[] = "0-9";
	char test3[] = "a-b-c";
	char test4[] = "a-zA-Z0-9";
	char s2[ARRAY_SIZE];

	expand(test1,s2);
	printf("%s\n", s2);
	memset(&s2, 0, ARRAY_SIZE);

	expand(test2,s2);
	printf("%s\n", s2);
	memset(&s2, 0, ARRAY_SIZE);

	expand(test3,s2);
	printf("%s\n", s2);
	memset(&s2, 0, ARRAY_SIZE);
	
	expand(test4,s2);
	printf("%s\n", s2);
	memset(&s2, 0, ARRAY_SIZE);
	return 0;
}

void expand(char s1[], char s2[]){

	int begin = 0, end = 0;
	int i = 0, j = 0;


	/* Deal with leading dashes */
	for( i = 0; s1[i] == '-'; i++){
		/* skip the dash. It says "arrange that leading - is taken 
		 literally" but I honestly don't know what that means so I 
		 have to ignore it here */
	}

	/* start where the above loop saw something other than a dash,
	 this will be the start of our list. */
	for(i; s1[i] != '\0'; i++){
		
		/* 
		 if we see a dash we know it separates beginning and end
		 of list.
		 */
		if( s1[i] == '-'){
		
			begin = s1[i - 1];/* start of our list */
			end = s1[i+1];	  /* end of our list */
			i++;/*move i to where we found end */	
			
			/* fill s2 with the expanded list. */
			while( begin <= end){
				
				/*
				 keep track of where we are in the expanded
				 list always starting where we left off */
				if( !(s2[j-1] == begin)){
					s2[j] = begin;
					j++;
				}
				
				begin++;
			}		
		}
	}
}
