#ifndef QUESTION_HEADER  //begin header guard
#define QUESTION_HEADER
    
typedef struct quiz{
    char* question;
    char* answers[4];
    char goodAnswer; //We don't need an int for that (0,1,2 or 3)
} quiz;

quiz q[9]; // 10 questions

#endif //QUESTION_HEADER //end header guard