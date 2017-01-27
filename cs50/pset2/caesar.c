/******************************************************************************************
 * Title: Solution to "caesar" (less comfortable) in Problem Set 2 – CS50 2017            *
 * Author: Mateusz Polkowski                                                              *
 ******************************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    // if there are more than two arguments return an error
    if (argc > 2) {
        printf("Usage: ./caesar k\n");
        return 1;
    // if there is only one argument tell user no key given
    } else if (argc == 1) {
        printf("Usage: ./caesar k\n");
        return 1;
    } else {
        // atoi converts string to integer
        int k = atoi(argv[1]);
        // check if user gave a positive integer for the key
        if (k < 1) {
            printf("You need to give a positive integer!");
            return 2;
        } else {
            // get string from user
            printf("plaintext: ");
            string stringOfText = GetString();
            printf("ciphertext: ");
            
            // run through all characters and if a letter change it by k
            for (int i = 0, l = strlen(stringOfText); i < l; i++) {
                if (stringOfText[i] >= 'A' && stringOfText[i] <= 'Z') {
                    printf("%c", ((((stringOfText[i] - 65) + k) % 26) + 65)); 
                } else if (stringOfText[i] >= 'a' && stringOfText[i] <= 'z') {
                    printf("%c", ((((stringOfText[i] - 97) + k) % 26) + 97)); 
                } else {
                    printf("%c", stringOfText[i]);
                }
            }
            printf("\n");
            return 0;
        }
    }
}
