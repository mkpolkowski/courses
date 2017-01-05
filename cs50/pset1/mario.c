#include <cs50.h>
#include <stdio.h>

int main(void) {
    int height;
    int retry = 3;
    do {
        if (retry > 0) {
            printf("Height: ");
        } else {
            printf("Retry: ");
        }
        height = GetInt();
        retry--;
    } while (height < 0 || height > 23);

    for (int j = 0; j < height; j++) {
        for (int i = height - 1; i >= 0; i--) {
            if (i > j) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("#\n");
    }
}