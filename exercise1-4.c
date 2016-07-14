/*This is the program for exercise 1-4.  It will convert temperatures from Celsius to Fahrenheit
  and print them in a formatted table with a header*/

#import <stdio.h>

/*print Celsius-Fahrenheit table
  for celsius= 0, 20, ..., 300 */

main(){

  float fahr, celsius;
  int lower, upper, step, counter;

  lower = 0;   /* lower limit of temperature table*/
  upper = 300; /* upper limit */
  step = 20;   /* step size */
  counter = 0;
  celsius = lower;

  /* Print the conversion table*/
  //header
  printf("Celsius to Fahrenheit conversion:\n");
  
  //a line under the header
  for(counter = 0; counter < 40; counter++){
    printf("-");
  }
  
  printf("\n");//finish header

  /* convert from Celsius to Fahrenheit */
  while( celsius <= upper ){
    fahr = (9.0/5.0) * celsius + 32.0;
    printf( "%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
   

}
