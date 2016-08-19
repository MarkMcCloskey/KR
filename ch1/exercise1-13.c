/* Exercise 1-13:  Write a program to print a histogram of the lengths of words    in its input.  It is easy to draw the bars of the histogram horizontally, a 
   vertical orientation is more challenging.  */


#include <stdio.h>
#define LONGEST_WORD_IN_DICTIONARY 45

int main(){

	int lengths[LONGEST_WORD_IN_DICTIONARY + 1];//hold word counts
	int len = 0;//track current word length
	int c; //character holder
	int i,x;//iterators
	
	//initialize counts to 0
	for( i = 0; i < LONGEST_WORD_IN_DICTIONARY; i++){
		lengths[i] = 0;
	}

	//while there is input and the file hasn't ended
	while( ( c = getchar() ) != EOF ){
		
		//if we see a whitespace character
		if( c == ' ' || c == '\n' || c == '\t'){
			lengths[len]++;//log the length of the last word
			len = 0;//reset length of word counter
		}else{
			len++;
		} 
	}
	
	//header for histogram	
	printf("Histogram\n");
	for(i = 0; i < 30; i++){
		putchar('-');
	}
	printf("\n");

	//print actual histogram	
	for( i = 1; i < LONGEST_WORD_IN_DICTIONARY; i++){
		
		//if statement prevents me from printing unecessary lines but
		//I'm not sure if that is acceptable for a histogram
		if(lengths[i] > 0){	
			printf("%d ", i);//length of word axis
		
			//I'll use | to represent the bars of the graph
			for(x = 0; x < lengths[i]; x++){
				putchar('|');
			}
			
			printf("\n");
		}
	}

}

/*


This is actually an interesting problem.  I need to have a structure that
can handle arbitrary length words.  I Googled the longest english word and
there seems to be some variation... dictionary has a word 45 characters long
but someone else coined one like 180 000 characters long.
For the sake of getting something done quickly though, I'll assume
the program will be used with appropriate input.  Dangerous, I know.

It would be cool to have a program that automatically scaled base off input
within reasonable bounds.  Maybe down the road. 

This is a rough solution and I see room for improvement.  The improvements would
take time disproportionate to the reward though.  For example:

	-This accepts any input as a word whether it is in the dictionary or
not.  I think a proper implementation would need a lookup table.
	
	-The output could be formatted cleaner.  The single digit and double
digit length words would need to be aligned so that their bars start at the 
same spot.  Could be as easy as if( i < 10){putchar(' ');} but then what about
words with longer digit lengths if they were allowed?
	
	-As is, an adversary could probably give input longer than the array
length and break the program.  A simple check for word length might be good 
enough to stop this.  
	
	-As is, punctuaton such as periods and commas will be included in word
counts.  This is obviously incorrect so maybe add to the whitespace if check
to include punctuation.

Or I could be nitpicking.
*/
