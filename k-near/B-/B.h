#include<iostream>
#include<queue>
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
    NODE *nodes_head = NULL;
    // BNODE *lastnode = NULL;
    int number = 0;
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
        void SPLIT(BNODE *cur_bnode);
        BNODE *FIND(int data);

    public:
        BTree();
        ~BTree();
        void insert(int data);
        void destory();
        bool find(int data);
        bool del(int data);
        void print();
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

void BTree::SPLIT(BNODE *cur_bnode)
{
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
        last->next_bnode = cur_node->next_bnode;
        j->next_node = last;
        cur_bnode->number = M/2;
        // 3) do the middle post node
        BNODE *new_bnode = new BNODE;
        new_bnode->number = M/2;
        new_bnode->father_pre = cur_node;
        new_bnode->leaf_node = cur_bnode->leaf_node;
        new_bnode->nodes_head = cur_node->next_node;
        // 4) do the father insert
        if(cur_bnode->father_bnode == NULL)
        {
            BNODE *new_root = new BNODE;
            new_root->number = 1;
            new_root->nodes_head = cur_node;
            NODE *last_node = new NODE;
            cur_node->next_node = last_node;
            cur_node->next_bnode = cur_bnode;
            cur_node->next_node->next_bnode = new_bnode;
            root = new_root;
            break;
        }
        else if(cur_bnode->father_pre == NULL)
        {
            cur_node->next_node = cur_bnode->father_bnode->nodes_head;
            cur_bnode->father_bnode->nodes_head = cur_node;
            cur_node->next_bnode = cur_bnode;
            cur_node->next_node->next_bnode = new_bnode;
            cur_bnode->father_bnode->number++;
        }
        else
        {
            NODE *n = cur_bnode->father_pre->next_node;
            cur_bnode->father_pre->next_node = cur_node;
            cur_bnode->father_bnode->number++;
            cur_node->next_node = n;
            cur_node->next_bnode = cur_bnode;
            cur_node->next_node->next_bnode = new_bnode;
        }
        // 5) iterator
        cur_bnode = cur_bnode->father_bnode;

    }
}

BNODE* BTree::FIND(int data)
{
    BNODE *cur_bnode = root;
    while(cur_bnode)
    {
        NODE *cur_node = cur_bnode->nodes_head;
        for(int i = 0;i < cur_bnode->number;i++)
        {
            if(data < cur_node->data)
            {
                cur_bnode = cur_node->next_bnode;
                break;
            }
            else if(data == cur_node->data)
            {
                return cur_bnode;
                //return true;
            }
            else
            {
                cur_node = cur_node->next_node;
            }
        }
    }
    return NULL;
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
        NODE *last = new NODE;
        root->nodes_head = last;
    }

    BNODE *cur_bnode = root;
    NODE *next_node;
    NODE *pre_node = NULL;
    BNODE *father_bnode = NULL;
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
            pre_node = next_node;
            next_node = next_node->next_node;
        }
    }
    cur_bnode->father_pre = pre_node;
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
        SPLIT(cur_bnode);
    }
}

// first find then decide to del
bool BTree::find(int data)
{
    if(FIND(data) == NULL)
    {
        return false;
    }
    else
        return true;
}

// only the leaf BNODE
bool BTree::del(int data)
{
    // bool find_true = find(data);
    // if(!find_true)
    // {
    //     cout << "no find the number" << endl;
    //     return;
    // }

    // pre act
    BNODE *cur_bnode = FIND(data);
    if(cur_bnode == NULL)
        return false;
    if(cur_bnode->leaf_node == false)
    {
        return false
    }
    else
    {
        if(cur_bnode->number > M/2)
        {
            NODE *cur_node = cur_bnode->nodes_head;
            NODE *pre_node = NULL;
            for(int i = 0; i< cur_bnode->number ;i++)
            {
                if(cur_node->data == data)
                {
                    if(pre_node == NULL)
                    {
                        cur_bnode->nodes_head = cur_node->next_node;
                        delete cur_node;
                        return true;
                    }
                    else
                    {
                        pre_node->next_node = cur_node->next_node;
                        delete cur_node;
                        return true;
                    }
                }
                pre_node = cur_node;
                cur_node = cur_node->next_node;
            }
        }
        else if()
        {
            
        }
    }

}

void BTree::print()
{
    // BFS
    queue<BNODE*> que;
    que.push(root);
    while(!que.empty())
    {
        BNODE *cur_bnode = que.front();
        NODE *cur_node = cur_bnode->nodes_head;
        que.pop();
        for(int i = -1; i< cur_bnode->number;i++)
        {
            cout << cur_node->data << endl;
            if(cur_node->next_bnode != NULL)
                que.push(cur_node->next_bnode);
            cur_node = cur_node->next_node;
        }
    }
}