/* Write the function strend(s,t) which returns 1 if the string t occurs at 
 * the end of s, and 0 otherwise.
 * */

#include <stdio.h>

#define LEN 100
int strend(char *s, char *t);

int main(void){
    char a[] = "should fail";
    char b[] = "a";
    char c[] = "l";
    char d[] = "another test";
    char e[] = "test";

    if (strend(a, b)) {
        printf("strend is wrong.\n");
    }
    if (strend(a, c)) {
        printf("strend might work.\n");
    }
    if (strend(d, e)) {
        printf("feel slightly more confident that strend works.\n");
    }
    if (strend(c,e)) {
        printf("strend broken.\n");
    }

    return 0;
}
/* return 1 if t occurs at end of s and 0 otherwise.*/
int strend(char *s, char *t){
    
    int tLen = 0;//get length of t
    char *temp = t;//temp variable to help find t len without using t
    
    //move s to the end
    while (*s != '\0') {
        s++;
    }
    
    //get length of t
    while (*temp != '\0') {
        tLen++;
        temp++;
    }

    s -= tLen;//move s to where t would start
    
    //while there is more t to match
    while (*t != '\0') {
        //if the characters are not the same return 0 and increment
        if (*t++ != *s++) {
            return 0;
        }
    }
    //otherwise found all of t at the end of s 
    return 1;

}
