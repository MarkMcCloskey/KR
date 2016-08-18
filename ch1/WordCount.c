#include <stdio.h>

/*  This is a copy from the book.  This program will count characters, words,
    and lines.  This is a bare bones implementation of the Unix program wc */
#define IN 1 /* inside a word*/
#define OUT 0 /* outside a word*/	

int main(){

	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	
	/* While receiving input and the file hasn't ended*/
	while( ( c = getchar() ) != EOF){
		
		++nc; //count character

		/*if it's a new line count it */
		if( c == '\n' ){
			++nl;
		}
		
		/* if we see any type of space */
		if( c == ' ' || c == '\n' || c == '\t' ){
			
			state = OUT; //we just finished a word
		
		//otherwise if we weren't in a word
		}else if( state == OUT ){

			state = IN;  //now we are
			++nw;        //so count it
		}
	}
	
	//output the counts in a general unspecific way
	printf( "%d %d %d\n", nl, nw, nc);
}
	
	
	

	

