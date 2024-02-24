#ifndef MATCH_H
#define MATCH_H
#include<iostream>
using namespace std;

//declaring a class for data of csv file.
//matchnode.h will make use of this class.

class match{
public:
    int match_index;
    int year;
    string country;
    string city;
    string stage;
    string home_team;
    string away_team;
    int home_score;
    int away_score;
    string outcome;
    string win_conditions;
    string winning_team;
    string losing_team;
    string month;
    string dayofweek;
};
#endif