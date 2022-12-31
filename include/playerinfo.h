#ifndef ScoreAndName
#define ScoreAndName

#include "headers.h"

class Name_and_Score
{
public:
    FILE *ScoreFile;
    FILE *NameFile;
    string input_name;
    int save_score[5] = {0, 0, 0, 0, 0};
    string save_name[5] = {"Anynomous", "Anynomous", "Anynomous", "Anynomous", "Anynomous"};
    void save_previous_name_file();
    void save_present_name(string name);
    void output_name();

    void save_previous_highest_score_file();
    void save_present_highest_score(string name, int score);
    void output_highest_score();
    void close_file();
};

extern Name_and_Score player;


#endif