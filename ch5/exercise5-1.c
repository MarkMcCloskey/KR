/*
 * As written getint treats a + or - not followed by a digit as a valid 
 * representation of zero. Fix it to push such a character back onto the 
 * input.
 */

#include <ctype.h>
#include <stdio.h>
#include "aux.h"

int getint(int *pn);


int main(){
    
    int nextInt;
    
    while( getint(&nextInt) ){
        printf("Next int: %d\n",nextInt);
    }
    
    return 0;
}


/* get next integer from input into *pn */
int getint(int *pn){
    
    int c, sign, temp;

    while ( isspace( c = getch()))/*skip whitespace*/
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){
        temp = c;
        c = getch();
        /* if the next char is not a digit just ungetch */
        if (!isdigit(c)){
            ungetch(c);
            ungetch(temp);
            c = 0;//return 0 
        }
    }    
    for (*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;

    if (c != EOF){
        ungetch(c);
    }
    return c;    
}
