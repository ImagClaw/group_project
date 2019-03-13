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
#include <conio.h> // Allows the use of console input/output
#endif

#ifdef linux
#define CLEAR "clear"
#include <termios.h>
static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      new.c_lflag |= ECHO; /* set echo mode */
  } else {
      new.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}
#endif

//#incuded header for program functionality
#include <stdio.h> // Allows standard input/output
#include <ctype.h> // Allows the use of toupper functions
#include <stdlib.h> // Allows the use of system commands
#include <string.h> // Allows the use of string functions
#include "questions.h" // Used for the struct

// declaring functions.
void help();
void highScores();

int main() {

    // Variables
    char plyrName[64];
    char choice;
    float score;
    int countr = 0;

    // Identifiy mainhome
    mainhome:
     puts("\t\t*****************************************");
     puts("\t\t\t     WELCOME to...");
     puts("\t\t\t       THE QUIZ...");
     puts("\t\t\t    DUN DUN DUUUUN!");
     puts("\t\t*****************************************");
     puts("\t\t    DO YOU THINK YOU CAN HANDLE IT???    ");
     puts("\t\t*****************************************");
     puts("\t\t > Press S to start the quiz");
     puts("\t\t > Press V to view Top 3 highest scores");
     puts("\t\t > Press R to reset score");
     puts("\t\t > press H for help            ");
     puts("\t\t > press Q to quit             ");
     puts("\t\t_______________________________________\n\n");
     // assigns all input as an uppercase input.  This removes all "or" statements.  
     choice=toupper(getch());
     switch (choice){
         case 'S': // If choice S is selected, Start the quiz.
             system(CLEAR); // clear the screen
             // ask user for their name
             printf("\n\n\n\n\n\n\n\n\n\n\t\t\tEnter your name: ");
             gets(plyrName); 
             system(CLEAR); // clear the screen
             printf("\n ************************** Welcome to the Quiz, %s. ***************************", plyrName);
             printf("\n\n Here are some tips you might wanna know before playing:");
             printf("\n ********************************************************************************");
             printf("\n >> You will be given 4 options, type the answer verbatim.");
             printf("\n >> Don't fail.");
             printf("\n >> Get over 80%% to pass.");
             printf("\n\n\t!!!!!!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!!!!!!!");
             printf("\n\n\t**** IF YOU'RE READY PRESS 'Y' TO START THE QUIZ ****"); 
             if (toupper(getch())=='Y') {
                system(CLEAR); // clear the screen
	 	        goto quiz;
             } else {
                 system(CLEAR); // clear the screen
                 goto mainhome;
             } 
         case 'V': // If choice V is selected, sort and list only the top 3 scores.
             highScores();
             printf("\n\n Press enter to go to the main menu.");
             getch();
             goto mainhome;
         case 'R': // If choice R is selected, remove all scores in score.txt
             fclose(fopen("./scores.txt", "w"));
             printf(" All scores reset.\n\n");
             printf("\n\n Press enter to go to the main menu.");
             getch();
             goto mainhome;
         case 'H': // If choice H is selected, pull the Help function.
             help();
             printf("\n\n Press enter to return to the main menu!");
             getch();
             system(CLEAR); // clear the screen
             goto mainhome; // return to main menu
         case 'Q':
             exit(1);
         default:
             puts("You didn't enter a choice.");
     }

    // Identifies quiz section
    quiz:
     q[0].question = "Who is the president of the United States (2019)?";
     q[0].answers[0]= "Barak Obama";
     q[0].answers[1]= "Bill Clinton";
     q[0].answers[2]= "Donald Trump";
     q[0].answers[3]= "George Bush";
     q[0].goodAnswer = 2;
     q[1].question = "What is the largest ocean in the world?";
     q[1].answers[0]= "Atlantic Ocean";
     q[1].answers[1]= "Pacific Ocean";
     q[1].answers[2]= "Artic Ocean";
     q[1].answers[3]= "Indian Ocean";
     q[1].goodAnswer = 1;
     q[2].question = "Where did the Olympic Games originate?";
     q[2].answers[0]= "Egipt";
     q[2].answers[1]= "India";
     q[2].answers[2]= "Peru";
     q[2].answers[3]= "Greece";
     q[2].goodAnswer = 3;
     q[3].question = "What is the coloured part of the human eye called?";
     q[3].answers[0]= "The iris";
     q[3].answers[1]= "The cornea";
     q[3].answers[2]= "The cone";
     q[3].answers[3]= "The retina";
     q[3].goodAnswer = 0;
     q[4].question = "In which year was Alaska sold to the U.S.?";
     q[4].answers[0]= "1947";
     q[4].answers[1]= "1895";
     q[4].answers[2]= "1867";
     q[4].answers[3]= "1911";
     q[4].goodAnswer = 2;
     q[5].question = "What is the diameter of Earth?";
     q[5].answers[0]= "2000 miles";
     q[5].answers[1]= "9000 miles";
     q[5].answers[2]= "6000 miles";
     q[5].answers[3]= "8000 miles";
     q[5].goodAnswer = 3;
     q[6].question = "How many chambers does the human heart have?";
     q[6].answers[0]= "4";
     q[6].answers[1]= "6";
     q[6].answers[2]= "2";
     q[6].answers[3]= "5";
     q[6].goodAnswer = 0;
     q[7].question = "In which country Bagels originate?";
     q[7].answers[0]= "England";
     q[7].answers[1]= "Poland";
     q[7].answers[2]= "Italy";
     q[7].answers[3]= "India";
     q[7].goodAnswer = 1;
     q[8].question = "How many balls are on a pool table at the start of a game?";
     q[8].answers[0]= "8";
     q[8].answers[1]= "5";
     q[8].answers[2]= "10";
     q[8].answers[3]= "16";
     q[8].goodAnswer = 3;
     q[9].question = "When united states was founded?";
     q[9].answers[0]= "1776";
     q[9].answers[1]= "1720";
     q[9].answers[2]= "1790";
     q[9].answers[3]= "1735";
     q[9].goodAnswer = 0;
     system(CLEAR); // clear the screen
     for(int i=0;i<10;i++){
         system(CLEAR); // clear the screen
         printf("Question %d:\n", i+1);
         printf("%s\n\n", q[i].question);
         printf("Possible answers are:\n\t%s\n\t%s\n\t%s\n\t%s", q[i].answers[0], q[i].answers[1], q[i].answers[2], q[i].answers[3]);
         int x = q[i].goodAnswer;
         printf("\n\nEnter your answer: ");
         char * ans = (char *)malloc(64);
         gets(ans);
         if(strcmp(ans, q[i].answers[x]) == 0) {
            printf("\n Correct!\n");
            printf(" Press enter to continue to the next question.");
            countr++;
         } else {
            printf(" Wrong, the answer was %s\n\n", q[i].answers[x]);
         }
         getch();
         free(ans);
     }
     goto score;

    // Identifies scoring section
    score:
     system(CLEAR); // clear the screen
	 score=(float)countr/10;
     score *= 100;
     // Opens and writes to a file
     FILE *fscore;
     fscore=fopen("scores.txt", "a");
     fprintf(fscore, "%s | %3.2f%%\n", plyrName, score);  // it is not printing :()
     fclose(fscore);
	 
     if(score==100) { // If perfect score, print the below
	    printf("\n\n\t\t**************** CONGRATULATION *****************");
        printf("\n\t\t      You've got %3.2f%%! A PERFECT SCORE!\n\n",score);
        goto go;
     } else if(score>=80.00) { // If greater than 80, print the below
	    printf("\n\n\n \t\t**************** CONGRATULATION ****************");
	    printf("\n\t\t\t     YOU'VE PASSEED!!!!!!!!!");
	    printf("\n\t\t\t      Your score is: %3.2f%%",score);
	    printf("\n\t\t\t          Thank You !!");
        printf("\n\n\n \t\t**************** CONGRATULATION ****************\n\n");
	 } else { // If not 100 or greater than 80%, print the below
	    printf("\n\n\t******** SORRY YOU DIDN'T PASS ********");
        printf("\n\t         Your score is: %3.2f%%",score);
	    printf("\n\t     Thanks for your participation");
	    printf("\n\t\t      TRY AGAIN\n");
        printf("\t******** SORRY YOU DIDN'T PASS ********\n\n");
        goto go;
     }

    // Identifies user choice section to either return to main menu or take the quiz again.
	go:
	 puts(" Press Y if you want to take the quiz again");
	 puts(" Press any key if you want to go main menu");
	 if (toupper(getch())=='Y') {
        system(CLEAR); // clear the screen
	 	goto quiz;
     } else {
        system(CLEAR); // clear the screen
        goto mainhome;
     }

    return 0;
}


void help() {
    system(CLEAR); // clear the screen
    printf("\n\n                                  HELP/ABOUT\n");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ............................ C program Quiz .............................");
    printf("\n > What do you need help for?  It's a quiz...");
    printf("\n > You need to get above an 80%% to pass, or else...");
    printf("\n > The Main Menu should be enough to get you going.  Follow the prompts.\n\n");
	printf("\n ***************************** BEST OF LUCK ******************************");
	printf("\n ******* C PROGRAMMING QUIZ DEVELOPED BY MEJIA, OGDEN, AND WHELPLEY ******");
}

void highScores() {
    system(CLEAR); // clear the screen
    char * name[4];
    float numScore[4];
    FILE *fp;
    char * swapName;
    float swapNum;
    char str[128];
    
    fp=fopen("scores.txt", "r"); // read scores.txt and assign it to the var fp as a read-only var   

    if (fp == NULL) { // Check if scores.txt exists or not
        perror("\n\n FILE DOESNT EXIST, TAKE THE QUIZ TO GENERATE THIS FILE");
    } else if (fgets (str, 60, fp)==NULL) { // 
        printf("\n\n FILE EXISTS, NO SCORES TO PARSE");
    } else {
        printf("\t\t*************** TOP 3 HIGH SCORES ***************\n");
        for(int i = 0; i < 3; i++) {
            fscanf(fp, "%s | %f%%\n", name[i], &numScore[i]);
            //printf("%s | %f%%\n", name[i], numScore[i]);
        }

        for(int c = 0; c < 3; c++) {
            for(int d = 0; d < 3 - c; d++) {
                if(numScore[d] < numScore[d+1]) {

                    // swap name
                    swapName = name[d];
                    name[d] = name[d+1];
                    name[d+1] = swapName;

                    // swap score
                    swapNum = numScore[d];
                    numScore[d] = numScore[d+1];
                    numScore[d+1] = swapNum;

                }
            }
            printf("\t\t\t#%d \t%s \t| \t%3.2f%%\n", c+1, name[c], numScore[c]); 
        }
        
    } 
    fclose(fp);          
}