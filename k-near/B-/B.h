#include<iostream>
using namespace std;
#define M 5
// M usually is odd
// (m/2)up - 1 :: m-1 
// and 3/2 = 1;
// now I just find the tree is grow up!!!
// and one leaf node will split to two leaf nodes

// not compelite declare
struct NODE;

typedef struct BNODE
{
    BNODE *father_bnode = NULL;
    NODE *father_pre = NULL;
    bool leaf_node = false;
    NODE *nodes_head;
    // BNODE *lastnode = NULL;
    int number;
}Bnode;

typedef struct NODE
{
    int data = INT_MAX;
    Bnode *next_bnode = NULL;
    NODE *next_node = NULL;
}node;

// template<class T> // because it reference to compare bigger or smaller
                  // so I'm not really sure is I will use Tmplate
class BTree{
    private:
        BNODE *root;
        void INSERT(int data, BNODE *cur_bnode);
        void split(BNODE *cur_bnode);

    public:
        BTree();
        ~BTree();
        void insert(int data);
        void destory();
        bool find(int data);
        void del(int data);
};

void BTree::INSERT(int data, BNODE *cur_bnode)
{
        // choose the poisiton you shouled insert
    NODE *new_data_node = new NODE;
    new_data_node->data = data;
    NODE *cur_node = cur_bnode->nodes_head;

    NODE *pre = NULL;
    while(cur_node)
    {
        if(cur_node->data > data)
        {
            new_data_node->next_node = cur_node;
            if(pre == NULL)
                cur_bnode->nodes_head = new_data_node;
            else
                pre->next_node = new_data_node;
            break;
        }
        pre = cur_node;
        cur_node = cur_node->next_node; 
    } 
    cur_bnode->number++;
}

void BTree::split(BNODE *cur_bnode)
{
    // 暂时没有考虑到如果father_bnode是空的情况
    while(cur_bnode->number == M)
    {
        // 1) find the middle
        NODE *cur_node = cur_bnode->nodes_head;
        NODE *j;
        for(int i  = 0; i < M/2 ;i++)
        {
            j = cur_node;
            cur_node = cur_node->next_node; 
        }
        // 2) do the middle pre node
        NODE *last = new NODE;
        last->data = INT_MAX;
        last->next_node = NULL;
        last->next_bnode = NULL;
        j->next_node = last;
        cur_bnode->number = M/2;
        // 3) do the middle post node
        BNODE *new_bnode = new BNODE;
        new_bnode->number = M/2;
        new_bnode->father_pre = cur_node;
        new_bnode->leaf_node = true;
        new_bnode->nodes_head = cur_node->next_node;
        // 4) do the father insert
        NODE *m = cur_node->next_node;
        NODE *n = cur_bnode->father_pre->next_node;
        cur_bnode->father_pre->next_node = cur_node;
        cur_node->next_node = n;
        cur_node->next_bnode = cur_bnode;
        cur_node->next_node->next_bnode = new_bnode;
        
        // 5) iterator
        cur_bnode = cur_bnode->father_bnode;
    }
}

BTree::BTree()
{
    root = NULL;
}

void BTree::insert(int data)
{
    if (root == NULL) // if empty init the tree
    {
        root = new BNODE;
        root->number = 0;
        root->leaf_node = true;
    }

    BNODE *cur_bnode = root;
    NODE *next_node;
    BNODE *father_bnode = cur_bnode;
    while(cur_bnode->leaf_node != true)
    {
        // find the next node
        next_node = cur_bnode->nodes_head;
        while(next_node)
        {
            if(next_node->data > data)
            {
                father_bnode = cur_bnode;
                cur_bnode = next_node->next_bnode;
                break;
            }
            next_node = next_node->next_node;
        }
    }
    cur_bnode->father_pre = next_node;
    cur_bnode->father_bnode = father_bnode;
    // the BNODE is not full
    if (cur_bnode->number < M-1)
    {
        // curent node can be insert
        INSERT(data, cur_bnode);
    }
    // the BNODE is full
    else
    {
        // insert in first then findout the middle one
        // then split the node
        // send the node to it's father
        // so , YES we have to store the father's position
        INSERT(data, cur_bnode);
        split(cur_bnode);
    }


}