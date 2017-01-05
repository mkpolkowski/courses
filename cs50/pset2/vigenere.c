#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string vigenereCoder(string input, string key);

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Error, there should be an input with the program.");
        return 1;
    }
    
    // the argument that came with the execture program function is the 'key' for the coder that should be checked by the 'keyPrep' function
    string key = argv[1];

    for (int i = 0, l = strlen(key); i < l; i++) {
        if (!isalpha(key[i])) {
            printf("No go.");
            return 1;
        }
    }

    // get the 'input' to be ciphered as a string and check until atleast one character is inputed
    string input;
    do {
//        printf("Insert text: ");
        input = GetString();
    } while (strlen(input) == 0); // if the sring is empty try and try again.

    // use the vigenereCoder function and print the output 
    printf("%s\n", vigenereCoder(input, key));
}

string vigenereCoder(string input, string key) {
    int keyLength = strlen(key);
    char* cipher = input;
    
    for (int i = 0; i < keyLength; i++) {
        if (islower(key[i])) {
            key[i] = key[i] - ('a' - 'A');
        }
        key[i] = key[i] - 'A';
    }

    for (int i = 0, j = 0, l = strlen(input); i < l; i++) {
        if (isalpha(input[i])) {
            char upOrDown = (isupper(input[i])) ? 'A' : 'a';
            cipher[i] = ((input[i] - upOrDown + key[j % keyLength]) % 26) + upOrDown;
            j++;
        } else {
            cipher[i] = input[i];
        }


/*        printf("Sybol %c number %i ", input[i], input[i]);
        // check if it is a letter and then cipher
        if (isalpha(input[i])) {
            input[i] = input[i] + key[j % keyLength];
            printf("+ %i (%c) = %i meaning letter %c\n", key[i % keyLength], (key[i % keyLength]+65), input[i], input[i]);
            j++;
        }   */

    }
    return cipher;
}