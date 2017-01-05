#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    if (argc > 2) {
        return 1;
    } else if (argc == 1) {
        printf("Oops! No, key given.");
        return 1;
    } else {
        int k = atoi(argv[1]);
        if (k < 1) {
            printf("You need to give a positive integer!");
            return 1;
        } else {
            string stringOfText = GetString();
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