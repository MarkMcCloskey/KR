/* Exercise 1-5 modify the temperature conversion program to print the table in reverse order, that is, from 300 to 0. */
#import <stdio.h>

/*print Fahrenheit-Celsius table
  for fahr= 0, 20, ..., 300 */

main(){

  float fahr, celsius;
  int lower, upper, step;

  lower = 0;   /* lower limit of temperature table*/
  upper = 300; /* upper limit */
  step = 20;   /* step size */

  fahr = upper;
  while( fahr >= lower){
    celsius = (5.0/9.0) * (fahr-32.0);
    printf( "%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr - step;
  }
   

}
