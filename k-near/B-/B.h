#include<iostream>
using namespace std;
#define M 3
// m/2


// the step
// 1. create a class's object
// 2. 
typedef struct BNODE
{
    NODE *nodes[M];
    BNODE *lastnode = NULL;
    int number;
}Bnode;

typedef struct NODE
{
    int data;
    Bnode *point;
}node;

// template<class T> // because it reference to compare bigger or smaller
                  // so I'm not really sure is I will use Tmplate
class BTree{
    private:
        BNODE *root;

    public:
        BTree();
        ~BTree();
        void insert(int data);

};

BTree::BTree()
{
    root = NULL;
}

void BTree::insert(int data)
{
    if (root == NULL)
    {
        root = new BNODE;
    }
}