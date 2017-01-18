#include <cs50.h>
#include <stdio.h>

int main(void) {
    // declare a variable
    int time_in_minutes;

    // ask user for number of minutes
    printf("minutes: ");
    time_in_minutes = GetInt();
    
    // print number of bottles generated with the time
    printf("bottles: %d\n", time_in_minutes * 12);
}
