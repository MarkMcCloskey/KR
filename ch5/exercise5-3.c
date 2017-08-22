/* Exercise 5-3: write a pointer version of the function strcat that we showed
 * in chapter 2:strcat(s,t) copies the string t to the end of s.
 *
 *
 */
/*
 void strcat(char s[], char t[]){
    int i, j;
    i = j = 0;

    while (s[i] != '\0'){ //find end of s
        i++;
    }

    while ((s[i++] = t[j++]) != '\0') //copy t
        ;
 }
*/

#include <stdio.h>
#define PLENTY_OF_SPACE 100
void mystrcat(char* s, char* t);

int main(int argc, char* argv[]){
    char a[PLENTY_OF_SPACE] = "Hello, ";
    char b[PLENTY_OF_SPACE] = "world.";
    
    mystrcat(a,b);
    printf("%s\n",a);
    
    return 0;
}

/* Concatenate t to the end of s. s must be big enough. */
void mystrcat(char* s, char* t){

    while( *s != '\0' ){
       s++; //find the end of s
    }

    while( (*s++ = *t++) != '\0'){
        ;//copy t to end of s
    }

}

