/******************************************************************************************
 * Title: Solution to "credit" in Problem Set 1 – CS50 2017
 * Author: Mateusz Polkowski
 ******************************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int checkSum(long long creditCardNum);
void creditCardID(long long creditCardNum);

int main(void) {
    long long creditCardNum;
    
    // get credit card number from user
    do {
        printf("Number: ");
        creditCardNum = get_long_long();
    } while (creditCardNum < 0);
    
    // check the checksum if no error check ID, else scream
    if (checkSum(creditCardNum) == false) {
        creditCardID(creditCardNum);
    } else {
        printf("Failed checksum!\n");
    }
}


// check the checksum
int checkSum(long long creditCardNum) {
    int last = 0;
    int firstSum = 0;
    int secondSum = 0;
    // extract every digit from the credit card number
    for (int i = 0; i < 16; i++) {
//        printf("Nr:        %lld\n", creditCardNum);
        last = creditCardNum % 10;
//        printf("last:      %i\n", last);
        creditCardNum = (creditCardNum - last) / 10;
        
        // sum every second number
        if ((i + 1) % 2 == 1) {
            firstSum += last;
//            printf("firstSum:  %i\n", firstSum);
        
        // multiply every other second number by two and sum
        } else {
            last *= 2;
            
            // if number becomes two digit, add the two digits
            if (last > 9) {
                last = (last % 10) + 1;
            }
            secondSum += last;
//            printf("secondSum: %i\n", secondSum);
        }
    }
//    printf("%i + %i = %i\n", firstSum, secondSum, firstSum + secondSum);
    if ((firstSum + secondSum) % 10 == 0) {
        return 0;
    } else {
        return 1;
    }
}


// validate company's indentifier and length
void creditCardID(long long creditCardNum) {
    if ((creditCardNum >= 340000000000000 && creditCardNum <= 349999999999999) || 
        (creditCardNum >= 370000000000000 && creditCardNum <= 379999999999999)) {
        printf("AMEX\n");
    } else if (creditCardNum >= 5100000000000000 && creditCardNum <= 5599999999999999) {
        printf("MASTERCARD\n");
    } else if ((creditCardNum >= 4000000000000 && creditCardNum <= 4999999999999) || 
                (creditCardNum >= 4000000000000000 && creditCardNum <= 4999999999999999)) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
}
