/******************************************************************************************
 * Title: Solution to "initials" (less comfortable) in Problem Set 2 – CS50 2017          *
 * Author: Mateusz Polkowski                                                              *
 ******************************************************************************************/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // prompt the user for a name
    string name = get_string();
    
    // return the first inicial in upper case
    printf("%c", toupper(name[0]));
    
    // find a space and return a letter after the space in upper case
    for (int i = 0, n = strlen(name); i < n; i++) {
        if (name[i] == ' ') {
            printf("%c", toupper(name[i+1]));
        }
    }
    
    printf("\n");
    return 0;
}
