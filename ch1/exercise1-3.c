/*This is a copy and paste from section 1.2.  This is the second temperature converter in 
  section 1.2 it will convert from Fahrenheit to Celsius and print a formatted decimal 
  temperature. */

#import <stdio.h>

/*print Fahrenheit-Celsius table
  for fahr= 0, 20, ..., 300 */

main(){

  float fahr, celsius;
  int lower, upper, step, counter;

  lower = 0;   /* lower limit of temperature table*/
  upper = 300; /* upper limit */
  step = 20;   /* step size */
  counter = 0;
  fahr = lower;

  /* Print the conversion table*/
  //header
  printf("Fahrenheit to Celsius conversion:\n");
  
  //a line under the header
  for(counter = 0; counter < 40; counter++){
    printf("-");
  }
  
  printf("\n");//finish header

  /* convert from Fahrenheit to Celsius */
  while( fahr <= upper ){
    celsius = (5.0/9.0) * (fahr-32.0);
    printf( "%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
   

}
