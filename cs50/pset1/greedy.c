/******************************************************************************************
 * Title: Solution to "greedy" in Problem Set 1 – CS50 2017
 * Author: Mateusz Polkowski
 ******************************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    // ask for change value
    float fchange;
    int coin_25 = 0, coin_10 = 0, coin_05 = 0, coin_01 = 0, change = 0;
    do {
        printf("How much change is owed? ");
        fchange = GetFloat();
    } while (fchange < 0);
    
    change = round(fchange * 100);
    
    // calculate
    while (change - 25 >= 0) {
        coin_25++;
        change = change - 25;
    }
    while (change - 10 >= 0) {
        coin_10++;
        change = change - 10;
    }
    while (change - 5 >= 0) {
        coin_05++;
        change = change - 5;
    }
    while (change - 1 >= 0) {
        coin_01++;
        change = change - 1;
    }
    
    // answer
    // printf("You will need:\n%i quarters,\n%i dimes,\n%i nickels,\n%i pennies.\n", coin_25, coin_10, coin_05, coin_01);
    printf("%i\n", coin_25 + coin_10 + coin_05 + coin_01);
}
