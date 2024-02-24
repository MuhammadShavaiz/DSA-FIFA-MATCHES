#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include"matchList.h"
#include <vector>
#include "matchtableList.h"
#include "worldcupyear.h"
using namespace std;

//created a class parser and create objects of other classes to use them in below methods.
//parser() method uses a while loop to read line of csv file and store them in vector
//temp object of match class stores csv data into corresponding fields.


class parser1 { ;
public:
    match *temp = new match;
    matchNode * root = nullptr;
    matchList *matchtree = new matchList;
    table1 * worldcuphash = new table1;


   int parser() {
       // Open the input file
       std::ifstream input_file("wcmatches.csv");
       if (!input_file) {
           std::cerr << "Error opening input file" << std::endl;
           return 1;
       }

       // Read each line of the file
       std::string line;
       matchList *object1 = new matchList;

       while (std::getline(input_file, line)) {
           // Split the line into fields using a stringstream and a comma delimiter
           std::stringstream line_stream(line);
           std::string field;
           std::vector<std::string> fields;
           while (getline(line_stream, field, ',')) {
               fields.push_back(field);
           }

           // Create and initialize a match object
           temp->match_index = std::stoi(fields[0]);
           temp->year = std::stoi(fields[1]);
           temp->country = fields[2];
           temp->city = fields[3];
           temp->stage = fields[4];
           temp->home_team = fields[5];
           temp->away_team = fields[6];
           temp->home_score = std::stoi(fields[7]);
           temp->away_score = std::stoi(fields[8]);
           temp->outcome = fields[9];
           temp->win_conditions = fields[10];
           temp->winning_team = fields[11];
           temp->losing_team = fields[12];
           temp->month = fields[13];
           temp->dayofweek = fields[14];

           //temp node is given to matchNode class to create new object
           //this object to passed to avl tree and sget stored in it
           //at the same time it's address gets stored in pointer and the pointer get stored in linked list in hash table

           matchNode *singlematch = new matchNode(temp);
           root = matchtree->insert(root, singlematch);
           worldcuphash->insert(singlematch);



       }
   }

   //this main menu calls the entire functions of the classes. it gives users option and then do task accordingly

    void mainmenu() {
        cout<<"SELECT THE OPTIONS:\n1. PRINT ALL THE MATCHES FROM 1930-2018.\n2. CHECK HEAD TO HEAD MATCHES BETWEEN TWO COUNTRIES\n3. CHECK MATCHES OF A PARTICULAR WORLDCUP\n";
        int option;
        cin>>option;
        if(option == 1){
            matchtree->print(root);
        }
        else if(option == 2){
            cout<<"ENTER TWO COUNTRIES: (format : Argentina)\n";
            string a; string b;
            cin>>a; cout<<endl; cin>>b;
            matchtree->matchBetweenTwoTeams(a,b,root);
        }
        else if(option == 3){
            cout<<"ENTER THE WORLD CUP DATE: \n";
            int date; cin>>date; cout<<endl;
            worldcuphash->print(date);
        }
        else{
            cout<<"PLEASE RE-RUN THE PROGRAM AND ENTER A CORRECT VALUE";
        }
    }
};