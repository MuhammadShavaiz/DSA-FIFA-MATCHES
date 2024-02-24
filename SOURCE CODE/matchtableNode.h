#ifndef MATCHTABLENODE_H
#define MATCHTABLENODE_H
#include<iostream>
#include"matchNode.h"
using namespace std;

//this class declares a node with pointers of type matchnode and matchtablenode.
//matchl pointer basically points to the stored objects in the avl hence minimizing memory usage.


class matchtableNode{
public:

    matchtableNode * next;
    matchNode * matchl;
    matchtableNode(){
        this->next = nullptr;
    }
};
#endif