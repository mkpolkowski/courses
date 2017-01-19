/******************************************************************************************
 * Title: Solution to "mario" (more comfortable) in Problem Set 1 – CS50 2017
 * Author: Mateusz Polkowski
 ******************************************************************************************/

#include <cs50.h>
#include <stdio.h>

int main(void) {
    int height;
    int retry = 2;

    // ask for a number until user gives value between 0 and 23
    do {
        if (retry > 0) {
            printf("Height: ");
        } else {
            printf("Retry: ");
            retry = 3;
        }
        height = GetInt();
        retry--;
    } while (height < 0 || height > 23);

    // draw the piramid
    for (int j = 0; j < height; j++) {
        for (int i = height - 1; i >= 0; i--) {
            if (i > j) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        
        printf("  ");
        
        for (int i = 0; i < height; i++) {
            if (i > j) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}
