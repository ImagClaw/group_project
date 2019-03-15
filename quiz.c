/* QUIZ PROJECT 
* 
* char Ogden, Whelpley, Mejia;
* 
* Quiz Generator:
*     - The quiz will ask user for a name input.
*     - Users receive 1 point per correct answer
*     - Score will be represented at the end as a percentage
* 
*/


//#incuded header for program functionality
#include <stdio.h> // Allows standard input/output
#include <ctype.h> // Allows the use of toupper functions
#include <stdlib.h> // Allows the use of system commands
#include <string.h> // Allows the use of string functions
#include "structs.h" // Used for the struct
#include "os.h"

// declaring functions.
void help();
void highScores();
void mainHome();
int quizFunction();
void scoreFunction(char* plyrName,int countr);

int main() {

    // Identifiy mainhome
    mainHome();

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

    char s[64];
    float n;
    int i = 0, lncount = 0;
    FILE *fp; // assign it to the var fp as a read-only var

    system(CLEAR); // clear the screen
    fp = fopen("./scores.txt", "r"); // opens scores.txt as read only
    
    // if file doesnt exist, error out.
    if (!fp) {
        perror("FILE NOT FOUND");
    }

    // Get the amount of lines from scores.txt
    for (int c = getc(fp); c != EOF; c = getc(fp)) {
    if (c == '\n') // Increment count if this character is newline 
        lncount = lncount + 1;
    }
    
    //printf("Your file has %d lines.\n", lncount);  // this was used to test the line number count

    rewind(fp);
    while (fscanf(fp, "%s | %f%%\n", s, &n) != EOF) {
        strcpy(values[i].name, s);
        values[i].score = n;
        i++;
    }
    fclose(fp);

    for (int x = 0; x < lncount; x++) {
        for (int j = 0; j <= lncount - 1; j++) {
            if (values[j].score < values[j+1].score) {
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
        //printf("%s | %3.2f%%\n", values[x].name, values[x].score);
    }

    printf("\t\t*************** TOP 3 HIGH SCORES ***************\n");
    for (int y = 0; y < 3; y++) {
        printf("\t\t\t#%d \t%s \t| \t%3.2f%%\n", y+1, values[y].name, values[y].score);
    }

    //for (i = 0; i < s; i++) {
    //    printf("\t\t\t#%d \t%s \t| \t%3.2f%%\n", lncount+1, hs[i].name, hs[i].score); 
    //}
              
}

void mainHome() {
    char plyrName[64];
    char choice;

    system(CLEAR);
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
            fgets(plyrName,64,stdin);
            plyrName[strlen(plyrName) - 1] = '\0';
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
		        scoreFunction(plyrName,quizFunction());
            } else {
                system(CLEAR); // clear the screen
                mainHome();
            } 
            break;
        case 'V': // If choice V is selected, sort and list only the top 3 scores.
            highScores();
            printf("\n\n Press enter to go to the main menu.");
            getch();
            mainHome();
            break;
        case 'R': // If choice R is selected, remove all scores in score.txt
            fclose(fopen("./scores.txt", "w"));
            printf(" All scores reset.\n\n");
            printf("\n\n Press enter to go to the main menu.");
            getch();
            mainHome();
            break;
        case 'H': // If choice H is selected, pull the Help function.
            help();
            printf("\n\n Press enter to return to the main menu!");
            getch();
            system(CLEAR); // clear the screen
            mainHome();// return to main menu
        case 'Q':
            exit(1);
        default:
            puts("You didn't enter a choice.");
            //mainHome();// return to main menu
            //break; 
    }
}

int quizFunction() {
    int countr = 0;

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
    q[2].answers[0]= "Egypt";
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
        fgets(ans,64,stdin);
        ans[strlen(ans)-1]= '\0';
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
    return countr;
}

void scoreFunction(char* plyrName, int countr) {
    float score;
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
    }
    // Identifies user choice section to either return to main menu or take the quiz again.
	puts(" Press Y if you want to take the quiz again");
	puts(" Press any key if you want to go main menu");
	if (toupper(getch())=='Y') {
        system(CLEAR); // clear the screen
		scoreFunction(plyrName,quizFunction());
    } else {
       system(CLEAR); // clear the screen
       mainHome();
    }
}
