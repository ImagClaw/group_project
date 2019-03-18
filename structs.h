#ifndef STRUCT_HEADER  //begin header guard
#define STRUCT_HEADER
    
// quiz struct
typedef struct quiz{
    char* question;
    char* answers[4];
    char goodAnswer;
} quiz;

quiz q[9]; 


// highscore struct
typedef struct highscore {
    char name[64];
    float score;
} highscore;

highscore values[15], temp;

#endif //STRUCT_HEADER //end header guard