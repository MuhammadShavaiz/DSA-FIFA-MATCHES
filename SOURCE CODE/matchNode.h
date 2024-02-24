#ifndef MATCHNODE_H
#define MATCHNODE_H
#include<iostream>
#include"match.h"
using namespace std;

//declaring a class for node with data type of match.
//this class will be used in matchlist.h and matchtablenode.h

class matchNode{
public:
    match data;
    matchNode * lchild;
    matchNode * rchild;
    matchNode * root;
    int height;
    matchNode(match *node){
        this->data = *node;
        lchild = nullptr;
        rchild = nullptr;
        height = 0;
    }
};

#endif