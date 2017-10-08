/*
 * There is no error checking in month_day or day_of_year. Rememdy this defect
 * */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
int is_leap(int year);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(){
    //random test
    printf( "%d\n", day_of_year(2017,8,22));
    return 0;
}

int day_of_year(int year, int month, int day){
    
    int i, leap;
    
    leap = is_leap(year);
    /*Error checking: ensure no invalid values are passed in, -1 indicates
     * error. */
    if (month > 12 || month < 1 || day < 0 || day > daytab[leap][month]) {
        return -1;
    }
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
   
    int i, leap;

    leap = is_leap(year);
    /*Error checking: ensure no invalid values are passed in, -1 indicates
     * error. */

    for (i = 1; yearday > daytab[leap][i]; i++ ) {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
    

}

int is_leap(int year){
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
