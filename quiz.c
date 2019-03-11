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
#ifdef _WIN32
#define CLEAR "cls"
#endif

#ifdef linux
#define CLEAR "clear"
#endif

//#incuded header for program functionality
#include<stdio.h>
#include<conio.h> // Allows the use of console input/output
#include<ctype.h> // Allows the use of toupper functions
#include<stdlib.h> // Allows the use of system commands
#include<string.h> // Allows the use of string
//#include "ogden.h"

// declaring functions.
void help();

int main() {
    // Variables
    char plyrName[64];
    char choice;
    float score;
    int countr;

    // Identifiy mainhome
    mainhome:
     puts("\n\t\t\t  << QUIZ GAME >>\n");
     puts("\t\t****************************************");
     puts("\t\t\t   WELCOME to...");
     puts("\t\t\t     THE QUIZ ");
     puts("\t\t\t  DUN DUN DUUUUN!");
     puts("\t\t****************************************");
     puts("\t\t   DO YOU THINK YOU CAN HANDLE IT???    ");
     puts("\t\t****************************************");
     puts("\t\t > Press S to start the quiz");
     // Maybe additional features?
     //puts("\n\t\t > Press V to view the highest score  ");
     //puts("\n\t\t > Press R to reset score");
     puts("\n\t\t > press H for help            ");
     puts("\n\t\t > press Q to quit             ");
     puts("\n\t\t________________________________________\n\n");
     // assigns all input as an uppercase input.  This removes all "or" statements.
     choice=toupper(getch());
 
     // If choice H is selected, pull the Help function.
     if(choice=='H') {
         system(CLEAR);
         help();
         printf("\n\n Press any other key to return to the main menu!");
         getchar();
         system(CLEAR);
         goto mainhome;
	 } else if(choice=='S') { // If choice S is selected, enter the quiz.
         // clear the screen
         system(CLEAR);
         // ask user for their name
         printf("\n\n\n\n\n\n\n\n\n\n\t\t\tEnter your name: ");
         gets(plyrName);
         // clear the screen again and displays 
         system(CLEAR);
         printf("\n *********** Welcome to the C Program Quiz, %s. *****************",plyrName);
         printf("\n\n Here are some tips you might wanna know before playing:");
         printf("\n ********************************************************************************");
         printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
         printf("\n    right option.");
         printf("\n >> Don't fail.");
         printf("\n >> Get over 80%% to pass.");
         printf("\n\n\t!!!!!!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!!!!!!!");
         printf("\n\n\t**** IF YOU'RE READY PRESS Y TO START THE QUIZ ****");
         printf("\n\n\n Press Y  to start the game!\n");
         printf("\n Press any other key to return to the main menu!");
         
         if (toupper(getch())=='Y') {
             system(CLEAR);
	 	    goto quiz;
         } else {
             system(CLEAR);
             goto mainhome;
         }
     } else if (choice=='Q') {
         exit(1);
     }

    // Identifies quiz section
    quiz:
     system(CLEAR);
     printf("THIS IS THE QUIZ SECTION!");
     printf("\n Press any other key to return to the main menu!");
     getchar();
     system(CLEAR);
     goto mainhome;


    // Identifies scoring section
    score:
     // clear the screen
     system(CLEAR);
	 score=(float)countr*100;
	 if(score==100) { // If perfect score, print the below
	    printf("\n\n\t\t**************** CONGRATULATION *****************");
        printf("\n\t You've got %.2f! A PERFECT SCORE!",score);
        goto go;
     } else if(score>=80.00) { // If greater than 80, print the below
	    printf("\n\n\n \t\t**************** CONGRATULATION ****************");
	    printf("\n\t\t\t\t YOU'VE PASSEED!!!!!!!!!");
	    printf("\n\t\t\t\t Your score is: %.2f",score);
	    printf("\n\t\t\t\t Thank You !!");
	 } else { // If not 100 or greater than 80%, print the below
	    printf("\n\n\t******** SORRY YOU DIDN'T PASS ********");
	    printf("\n\t\t Thanks for your participation");
	    printf("\n\t\t TRY AGAIN");
        goto go;
     }

    // Identifies user choice section to either return to main menu or take the quiz again.
	go:
	 puts("\n\n Press Y if you want to take the quiz again");
	 puts(" Press any key if you want to go main menu");
	 if (toupper(getchar())=='Y') {
	 	goto quiz;
     } else {
         goto mainhome;
     }

    return 0;
}


void help()
{
    system(CLEAR);
    printf("\n\n                                  HELP/ABOUT\n");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ............................ C program Quiz .............................");
    printf("\n > What do you need help for?  It's a quiz...");
    printf("\n > You need to get above an 80%% to pass, or else...");
    printf("\n > The Main Menu should be enough to get you going.  Follow the prompts.");
	printf("\n ***************************** BEST OF LUCK ******************************");
	printf("\n ******* C PROGRAMMING QUIZ DEVELOPED BY MEJIA, OGDEN, AND WHELPLEY ******");
}