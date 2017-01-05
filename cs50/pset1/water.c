#include <cs50.h>
#include <stdio.h>

int main(void) {
    int time_in_minutes;
    printf("minutes: ");
    time_in_minutes = GetInt();
    printf("bottles: %d\n", time_in_minutes * 12);
}