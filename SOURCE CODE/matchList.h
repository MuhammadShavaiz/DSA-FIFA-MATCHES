#include<iostream>
#include"matchNode.h"

//this class declares some pointers of matchnode type and implements an AVL tree through functions.
//all of the data from csv file gets stored as matchnode in avl tree object of this class.
//class contains method such as balance insertion, printing and checking for specific matches

using namespace std;
class matchList{
public:
    matchNode *root;
    matchNode *loc = nullptr;
    matchNode *ploc = nullptr;
    matchList(){
        root = nullptr;
    }
    matchList(match *node){

        matchNode *nn = new matchNode(node);

        root = nn;
    }
    int height(matchNode *N)
    {
        if (N == nullptr)
            return 0;
        return N-> height;
    }
    int max(int a, int b)
    {
        return (a > b)? a : b;
    }
    matchNode* newNode(matchNode*Node)
    {
        Node -> height = 1;
        return(Node);
    }
    matchNode *rightRotate(matchNode *y) {
        matchNode *x = y->lchild;
        matchNode *T2 = x->rchild;

        // Perform rotation
        x->rchild = y;
        y->lchild = T2;

        // Update heights
        y->height = max(height(y->lchild),
                        height(y->rchild)) + 1;
        x->height = max(height(x->lchild),
                        height(x->rchild)) + 1;

        // Return new root
        return x;
    }
    matchNode *leftRotate(matchNode *x)
    {
        matchNode *y = x->rchild;
        matchNode *T2 = y->lchild;

        // Perform rotation
        y->lchild = x;
        x->rchild = T2;

        // Update heights
        x->height = max(height(x->lchild),
                        height(x->rchild)) + 1;
        y->height = max(height(y->lchild),
                        height(y->rchild)) + 1;

        // Return new root
        return y;
    }
    int getBalance(matchNode *N)
    {
        if (N == nullptr)
            return 0;
        return height(N->lchild) - height(N->rchild);
    }

    //worstcase complexity O(n);

    matchNode* insert(matchNode* node, matchNode* node2)
    {
        /* 1. Perform the normal BST insertion */
        if (node == nullptr)
            return newNode(node2);

        if (node2->data.match_index < node->data.match_index)
            node->lchild = insert(node->lchild, node2);
        else if (node2->data.match_index > node->data.match_index)
            node->rchild = insert(node->rchild, node2);
        else // Equal keys are not allowed in BST
            return node;

        /* 2. Update height of this ancestor node */
        node->height = 1 + max(height(node->lchild),
                               height(node->rchild));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && node2->data.match_index < node->lchild->data.match_index)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && node2->data.match_index > node->rchild->data.match_index)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && node2->data.match_index > node->lchild->data.match_index)
        {
            node->lchild = leftRotate(node->lchild);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && node2->data.match_index < node->rchild->data.match_index)
        {
            node->rchild = rightRotate(node->rchild);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }

    //worstcase complexity O(n)
    void print(matchNode * root){
        if(root != nullptr) {
            print(root->lchild);
            cout << root->data.match_index << " " << root->data.dayofweek << " " << root->data.home_team << " "
                 << root->data.home_score << " " << root->data.away_team << " " << root->data.away_score << " "
                 << root->data.country
                 << " " << root->data.country << " " << root->data.year << " " << root->data.month << " "
                 << root->data.city << " "
                 << root->data.losing_team << " " << root->data.winning_team << " " << root->data.win_conditions << " "
                 << root->data.outcome
                 << " " << root->data.stage << endl;
            print(root->rchild);
        }
    }

    //this method takes two teams and a root of an avl tree and search for their head to head record.
    //worstcase complexity O(n).

   void matchBetweenTwoTeams(string cA, string cB, matchNode *root){
        if(root!= nullptr){
            matchBetweenTwoTeams(cA, cB, root->lchild);
            if(root->data.home_team == cA && root->data.away_team == cB
            || root->data.home_team == cB && root->data.away_team == cA){
                cout << root->data.home_team << "  " <<root->data.home_score<<"  "
                     <<root->data.away_score<<"  "<<root->data.away_team<<"  "<<root->data.stage<<"  "<<
                     root->data.year<<endl;
            }
            matchBetweenTwoTeams(cA,cB,root->rchild);

        }
        else{
            return;
        }
    }
};
