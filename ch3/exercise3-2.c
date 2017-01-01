/*
 Write a function escape(s,t) that converts characters like newline and tab
 into visible escape sequences like \n and \t as it copies the string t to
 s. Use a switch. Write a function for the other direction as well, 
 converting escape sequences into the real characters.
 */

#include <stdio.h>

void escape(char s[], char t[]);
void reescape(char s[], char t[]);

#define BUFF_SIZE 1000

int main( int argc, char* argv[]){
	
	char strbuff[BUFF_SIZE]  = { '\0' };
	char string[BUFF_SIZE] = "Hello	how	are you?";
	char bleh[BUFF_SIZE];

	escape( strbuff, string);
	printf("%s\n", strbuff);
	reescape(bleh, strbuff);
	printf("%s\n", string);

	return 0;
}

void escape(char s[], char t[]){
	
	int i = 0; /* iterators */
	int j = 0;

	/* iterate through t explicitly inserting escape sequences when
	 found otherwise just copy over whats in t*/
	for( i = 0; t[i] != '\0'; i++){

		switch( t[i] ) {
		
			/* I feel like this is kind of ugly */
			case '\n': s[j] = '\\'; 
				   j++;
				   s[j] = 'n';
				   j++;
				   break;
			case '\t': s[j] = '\\';
				   j += 1;
				   s[j] = 't';
				   j++;
				   break;
			default: s[j] = t[i];
				 j++;
				 break;
					
		}
		
	}

	s[j] = '\0';

}

void reescape(char s[], char t[]){
	
	int i = 0;
	int j = 0;

	for( i =0; t[i] != '\0'; i++ ){

		switch( t[i] ) {
		
			/* if we see what may possibly be an escaped char */
			case '\\' :

				/* nested switch, what up.*/
				switch ( t[i+1] ){
					
					case 't': s[j] = '\t';
						  i++;
						  break;
					case 'n': s[j] = '\n';
						  i++;
						  break;
					default: s[j] = t[i];
						 break;

				}
				j++;
				break;
			
			default: s[j] = t[i];
				 j++;
				 break;


		}
	
	}
	s[j] = '\0';

}
