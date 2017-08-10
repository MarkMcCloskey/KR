/**
 * Write a recursive version of the function reverse(s) which
 * reverses the string s in place
 */

#include <stdio.h>

void reverse( char s[], int index, int strLen );
void swap(char v[], int i, int j);

int main(){

	char string1[] = "abc";
	char string2[] = "1234";
	char string3[] = "1";	
	char string4[] = "hello";

	reverse(string1,0,3);
	reverse(string2,0,4);
	reverse(string3,0,1);
	reverse(string4,0,5);
	printf("%s\n",string1);
	printf("%s\n",string2);
	printf("%s\n",string3);
	printf("%s\n",string4);
	
	return 0;
}

void reverse( char s[], int index, int strLen ){
	
	if( strLen - (2*index + 1) <= 0 ){
		//do nothing
	}else{
		swap(s,index, strLen - index - 1);
		reverse(s,index+1,strLen);
	}
			
}

void swap(char v[], int i, int j){
	char temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;

}

