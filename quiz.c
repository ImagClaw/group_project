/* QUIZ PROJECT 
* 
* char Ogden, Whelpley, Mejia;
* 
* Quiz Generator:
*     - The quiz will ask user for a name input.
*     - Ask the user how many questions >10 && < 100
*     - Questions will be randomly queried from a predefined list
*     - Users receive 1 point per correct answer
*     - Score will be represented at the end as a percentage
* 
*/


//#incuded header for program functionality
#include <stdio.h>
//#include "ogden.h"


int main() {
    // Variables
    char name[64];
    int numQ;

    // Ask user for name
    printf("Enter your name: ");
    scanf("%s", name);

    printf("\n\nHello there, %s.\n", name);
    printf("How many questions would you like to be tested on? \n");
    do {
        printf("Enter question amount here (10-20): ");
        scanf("%d", &numQ);
        if (numQ <= 9) {
            printf("**ERROR: Question amount must be more than 10.\n\n");
        } else if (numQ >= 21) {
            printf("**ERROR: Question amount must be less than 20.\n\n");
        } else {
            printf("You've entered %d questions.\n\n", numQ);
        }
    } while ((numQ <= 9) || (numQ >=21));

    return 0;
}