/******************************************************************************************
 * Title: Solution to "vigenere" (less comfortable) in Problem Set 2 – CS50 2017          *
 * Author: Mateusz Polkowski                                                              *
 ******************************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// cipher the text
string vigenereCoder(string input, string key);

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    
    // the argument that came with the execture program function is the 'key' for the coder that should be checked by the 'keyPrep' function
    string key = argv[1];
    
    // check if the key contais anything but alphabetical charatres
    for (int i = 0, l = strlen(key); i < l; i++) {
        if (!isalpha(key[i])) {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    // get the 'input' to be ciphered as a string and check until atleast one character is inputed
    string input;
    do {
        printf("plaintext: ");
        input = GetString();
    } while (strlen(input) == 0); // if the sring is empty try and try again.

    // use the vigenereCoder function and print the output 
    printf("ciphertext: %s\n", vigenereCoder(input, key));
}

// cipher the text
string vigenereCoder(string input, string key) {
    // check how long the key is
    int keyLength = strlen(key);
    // make a cipher variable
    char* cipher = input;
    
    // convert all letters to numbers from 0 to 25
    for (int i = 0; i < keyLength; i++) {
        // make all letters uppercase
        if (islower(key[i])) {
            key[i] = key[i] - ('a' - 'A');
        }
        // make them from 0 to 25
        key[i] = key[i] - 'A';
    }
    
    // go throught the whole plaintext and convert to code
    for (int i = 0, j = 0, l = strlen(input); i < l; i++) {
        // if character is a letter
        if (isalpha(input[i])) {
            
            // check if character is upper and note it in upOrDown
            char upOrDown = (isupper(input[i])) ? 'A' : 'a';
            
            // take letter, make it 0-25, add key number and manage overflow, manage overflow of alphabet, readd the upper/lower
            cipher[i] = ((input[i] - upOrDown + key[j % keyLength]) % 26) + upOrDown;
            j++;
            
        // if not a letter, leave it alone
        } else {
            cipher[i] = input[i];
        }


/* ********** trials **********

printf("Sybol %c number %i ", input[i], input[i]);
        // check if it is a letter and then cipher
        if (isalpha(input[i])) {
            input[i] = input[i] + key[j % keyLength];
            printf("+ %i (%c) = %i meaning letter %c\n", key[i % keyLength], (key[i % keyLength]+65), input[i], input[i]);
            j++;
        }
*/

    }
    return cipher;
}
