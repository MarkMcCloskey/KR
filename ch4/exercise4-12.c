/*
 * Adapt the ideas of printd to write a recurse version of itoa; that is
 * convert an integer into a string by calling a recursive routine.
 *
 * ITOA CODE:
 * void itoa(int n, char s[]){
 * int i, sign;
 * if((sign = n) < 0)
 * 	n = -n;
 * i = 0;
 * do {
 * 	s[i++] = n % 10 + '0';
 * } while ((n/= 10) > 0);
 * if(sign<0)
 * 	s[i++] = '-';
 * s[i] = '\0';
 * reverse(s);
 * }
 */
#include <stdio.h>

void recursiveItoa(int n, char s[]);
int recursiveItoaHelper(int n, char s[], int index);

int main(int argc, char* argv[]){

	int num1 = 0;
	int num2 = -1;
	int num3 = 4;
	int num4 = -27;
	int num5 = 345;
	char str[5];

	recursiveItoa(num1,str);
	printf("Num1: %s\n",str);

	recursiveItoa(num2,str);
	printf("Num2: %s\n",str);

	recursiveItoa(num3,str);
	printf("Num3: %s\n",str);

	recursiveItoa(num4,str);	
	printf("Num4: %s\n",str);

	recursiveItoa(num5,str);	
	printf("Num5: %s\n",str);

	return 0;

}

/*
 * recursiveItoa takes as parameters an integer n and a character array s.
 * 
 * It will then convert n to a string stored in s.
 */
void recursiveItoa(int n, char s[]){
	//start the index at 0
	int index = 0;	
	//if n is negative put the sign into the string
	//and change n to positive
	if(n < 0){
		s[index++] = '-';
		n = -n;
	}
	//call the helper function to finish changing the int
	index = recursiveItoaHelper(n,s,index);
	s[index] = '\0';//terminate string with newline
}

/*
 * recursiveItoaHelper takes as input an integer n, a character array s,
 * and an integer that is the index into the character array where the next
 * character will go.
 *
 * It will then convert n to a character string in s and return the index into
 * s of the next character.
 */
int recursiveItoaHelper(int n, char s[], int index){
	//if there is more to the int keep changing it	
	if(n/10){
		//notice the initial index of 0 or 1 is preserved
		index = recursiveItoaHelper(n/10,s,index);
	}
	//convert the character and store it
	s[index] = (n % 10) + '0';
	
	//increment the index so that the return chain puts everything
	//in the proper place
	return index + 1;
}
