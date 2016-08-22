/*Exercise 1-15:  Re-write the temperature conversion program of Section 1.2 to
  use a function for conversion. */

#include <stdio.h>

int temp_converter(int start, int end, int step);

int main(){
	
	
	int lower = 0;   /* lower limit of temperature table*/
	int upper = 300; /* upper limit */
	int step = 20;   /* step size */

	temp_converter(lower,upper,step); 
	
	return 0;
}

/*print Fahrenheit-Celsius table*/
int temp_converter(int start, int end, int step){

	float fahr = start , celsius = 0;
	
	while(fahr <= end){
    		celsius = (5.0/9.0) * (fahr-32.0);
    		printf( "%3.0f %6.1f\n", fahr, celsius);
    		fahr = fahr + step;
	}
	return 0;
}
