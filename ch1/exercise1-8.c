#include <stdio.h>

/*Write a program to count blanks, tabs, and newlines */

int main(){

	int blanks = 0, tabs = 0, newlines = 0;
	
	int input;
	//while there is input
	while( ( input = getchar() ) != EOF ){
		
		//count blanks
		if( input == ' ' ){
			blanks++;
		
		//count tabs
		}else if( input == '\t' ){
			tabs++;
		//count newlines
		}else if(input == '\n'){
			newlines++;
		
		//otherwise do nothing and continue
		}else{
		}

	//print formatted output
	}		
	printf("Blanks: %d, Tabs: %d, Newlines: %d\n", blanks, tabs, newlines);
}
