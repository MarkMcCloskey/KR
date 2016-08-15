#include <stdio.h>

//copy input to ouput first version

main(){
	int c;
	c = getchar();
	
	while( c != EOF ){
		putchar(c);
		c = getchar();
	}
}

