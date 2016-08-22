/* Exercise 1-13:  Write a program to print a histogram of the frequencies of
 * different characters in input. */


#include <stdio.h>
#define NUM_CHARACTERS 26 //will consider only alphabet as characters here
#define ASCII_CAPS_START 65

int main(){

	int counts[NUM_CHARACTERS];//track character usage
	int c; //character holder
	int i,x;//iterators
	
	//initialize counts to 0
	for( i = 0; i < NUM_CHARACTERS; i++){
		counts[i] = 0;
	}

	//while there is input and the file hasn't ended
	while( ( c = getchar() ) != EOF ){
		
		/*So, this is going to be ugly but I think it's in line with
		  what the authors wanted us to learn.  This if else chain will
		  go through and check what each character is and increment
		  its count */	
		if( c == 'a' || c == 'A'){
			counts[0]++;
		}else if( c == 'b' || c == 'B'){
			counts[1]++;
		}else if( c == 'c' || c == 'C' ){
			counts[2]++;
		}else if( c == 'd' || c == 'D' ){
			counts[3]++;
		}else if( c == 'e' || c == 'E' ){
			counts[4]++;
		}else if( c == 'f' || c == 'F' ){
			counts[5]++;
		}else if( c == 'g' || c == 'G' ){
			counts[6]++;
		}else if( c == 'h' || c == 'H' ){
			counts[7]++;
		}else if( c == 'i' || c == 'I' ){
			counts[8]++;
		}else if( c == 'j' || c == 'J' ){
			counts[9]++;
		}else if( c == 'k' || c == 'K' ){
			counts[10]++;
		}else if( c == 'l' || c == 'L' ){
			counts[11]++;
		}else if( c == 'm' || c == 'M' ){
			counts[12]++;
		}else if( c == 'n' || c == 'N' ){
			counts[13]++;
		}else if( c == 'o' || c == 'O' ){
			counts[14]++;
		}else if( c == 'p' || c == 'P' ){
			counts[15]++;
		}else if( c == 'q' || c == 'Q' ){
			counts[16]++;
		}else if( c == 'r' || c == 'R' ){
			counts[17]++;
		}else if( c == 's' || c == 'S' ){
			counts[18]++;
		}else if( c == 't' || c == 'T' ){
			counts[19]++;
		}else if( c == 'u' || c == 'U' ){
			counts[20]++;
		}else if( c == 'v' || c == 'V' ){
			counts[21]++;
		}else if( c == 'w' || c == 'W' ){
			counts[22]++;
		}else if( c == 'x' || c == 'X' ){
			counts[23]++;
		}else if( c == 'y' || c == 'Y' ){
			counts[24]++;
		}else if( c == 'z' || c == 'Z' ){
			counts[25]++;
		}

	}
	
	//header for histogram	
	printf("Histogram\n");
	for(i = 0; i < 30; i++){
		putchar('-');
	}
	printf("\n");

	//print actual histogram	
	for( i = 1; i < NUM_CHARACTERS; i++){
		
		//if statement prevents me from printing unecessary lines but
		//I'm not sure if that is acceptable for a histogram
		if(counts[i] > 0){	
			printf("%c: ",( ASCII_CAPS_START + i));
			//I'll use | to represent the bars of the graph
			for(x = 0; x < counts[i]; x++){
				putchar('|');
			}
			
			printf("\n");
		}
	}

}
