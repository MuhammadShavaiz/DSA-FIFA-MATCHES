#ifndef MATCHTABLELIST_H
#define MATCHTABLELIST_H
#include<iostream>
#include"matchtableNode.h"
using namespace std;

//this is a linked list class for storing matches of particular worldcup
//class doesnot store the actuall data but just store pointers that point to the nodes of avl tree where data is stored.


class matchtableList {
public:
    matchtableNode *root;
    matchtableNode *last;
    matchtableNode *loc = nullptr;
    matchtableNode *ploc = nullptr;

    matchtableList() {
        root = nullptr;
        last = nullptr;
    }

    bool isEmpty() {
        return root == nullptr;
    }

    //this function insert newnodes into the linked list. it takes a node from matchNode as input
    //the function points the linked list node to the node of avl tree contaning data.
    //worst case complexity O(1).
    void insertNodes(matchNode *node) {
        matchtableNode *new_node = new matchtableNode;
        new_node->matchl = node;
        if (isEmpty()) {
            new_node->next = root;
            root = new_node;
            last = new_node;
        } else {
            new_node ->next = nullptr;
            last->next = new_node;
            last = new_node;
        }
    }

    //this function traverses the linked list and print the values
    //worst case complexity O(n)
    void printList() {
        if(!isEmpty()) {
            matchtableNode *current_node = root;
            while (current_node != nullptr) {
                cout << " " << current_node->matchl->data.dayofweek << " "
                     << current_node->matchl->data.home_team << " "
                     << current_node->matchl->data.home_score << " " << current_node->matchl->data.away_team << " "
                     << current_node->matchl->data.away_score <<
                       " " << current_node->matchl->data.year << " "
                       << current_node->matchl->data.stage << endl;
                current_node = current_node->next;
            }
        }
        else{
              cout<<"list is empty";
        }
        }
    };
#endif