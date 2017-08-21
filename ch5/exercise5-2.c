/*
 * Write getfloat the floating point analog of getint. What type does
 * getfloat return as its return value?
 */

#include <ctype.h>
#include <stdio.h>
#include "aux.h"

#define DECIMAL_ADJUST 1.0/10.0
int getfloat(double *pn);


int main(){
    
    double nextFloat;
    
    while( getfloat(&nextFloat) ){
        printf("Next float: %f\n",nextFloat);
    }
    
    return 0;
}


/* get next integer from input into *pn */
int getfloat(double *pn){
    
    int c, sign, temp, beforeDecimal;
    double afterDecimal, multiplier;
    
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

    /* if we get to the decimal of the float */
    if ( c == '.' ){
        c = getch();//get next char past decimal
        multiplier = DECIMAL_ADJUST;//get decimal place start value
        /* while we read in a digits start at 0 and add until done */
        for (afterDecimal = 0; isdigit(c); c = getch()){
            /* grab the input character digit, convert to an int by subtracting
             * the zero char, then scale the number by the appropriate value
             * to shift it to the correct place beyond the decimal
             */
            afterDecimal += multiplier * (c - '0');
            //keep making multiplier smaller by factors of 10
            multiplier = multiplier * DECIMAL_ADJUST;
        }
    }
    /* add the decimal portion to the integer part */
    *pn += afterDecimal; 
    *pn *= sign;

    if (c != EOF){
        ungetch(c);
    }
    return c;    
}
