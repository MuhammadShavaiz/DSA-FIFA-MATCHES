#include<iostream>
#include"matchtableList.h"
using namespace std;

//this class declares an array of type matchtableList.
//matchtableList is a singly linked list class so this array will store linked list on each index.
//each linked list will be stored based on hash value of the world cup.

class table1 {
public:
    matchtableList arr[23];

    int hash(int value){
        return value % 23;
    }

    //insert function insert linked list into hash table by calling insertNodes function from matchtableList.
    //worst case complexity O(n)
    void insert(matchNode * node) {
        int index = hash(node->data.year);
           while(true){
               if(arr[index].root==NULL){
                    arr[index].insertNodes(node);
                    return;
               }
           else{
               if(arr[index].root->matchl->data.year == node->data.year){
                   arr[index].insertNodes(node);
                   return;
               }
               else{
                   index++;
               }
               if(index == 23){
                   index = 0;
               }
           }
           }
    }

    //this function use the user entered date and hash the value. go to the index and print the linked list there.
    //worst case complexity O(n)
    void print(int value){
        int index = hash(value);
        int counter = 0;
        while(counter < 23){
            if(arr[index].root->matchl->data.year == value){
                arr[index].printList();
                return;
            }
            index++;
            counter++;
            if(index=23){
                index = 0;
            }
        }
        cout<<"re-run the program and enter another date";
    }
};
