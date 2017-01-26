/******************************************************************************************
 * Title: Solution to "initials" (more comfortable) in Problem Set 2 – CS50 2017          *
 * Author: Mateusz Polkowski                                                              *
 ******************************************************************************************/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // prompt the user for a name
    string name = get_string();
    
    // check every sigle letter in the string
    for (int i = 0, n = strlen(name); i < n; i++) {
        // skip all spaces
        while (name[i] == ' ') {
            i++;
        }
        
        // print letter after space in upper case
        printf("%c", toupper(name[i]));
        
        // search for the next space
        while (name[i] != ' ' && i < n) {
            i++;
        }
    }
    
    printf("\n");
    return 0;
}
