//#include <iostream>
//using namespace std;

//#define M 4


//// the reason why I turn the M + 1 
//typedef struct btree_node
//{
    //int num;
    //int data[M];
    //btree_node *nodes[M+1];

//};

//btree_node *init()
//{
    //btree_node *node = (btree_node*)malloc(sizeof(btree_node));
    //if (node == NULL)
        //return NULL;
    //return node;
//}

//btree_node *find(int new_data, btree_node *cur_node)
//{
    //if(cur_node == NULL)
        //return NULL;
    //// not consider the cur_node->num == 0 first
    //for(int i =0 ;i<cur_node->num;i++)
    //{
        //if(new_data < cur_node->data[i]);
            //return cur_node->nodes[i];
    //}
    //return cur_node->nodes[cur_node->num];
//}

//btree_node *insert_in_node(int new_date, btree_node *cur_node)
//{
    //for(int i = 0;i<cur_node->num;i++)
    //{
        //cur_node->data[cur_node->num - i] = cur_node->data[cur_node->num - i -1];
        //if(new_date > cur_node->data[cur_node->num - i - 1])
        //{
            //cur_node->data[cur_node->num] = new_date;
            //cur_node->num++;
            //// than we have to change the nodes
            //return cur_node;
        //}
    //}
    //cur_node->data[0] = new_date;
    //cur_node->num++;
    //return cur_node;
//}

//btree_node *insert(int new_data, btree_node *root)
//{
    //// btree_node *new_node = init();
    //btree_node *cur_node = root;
    //btree_node *upnode;
    //while(cur_node != NULL)
    //{
        //upnode = cur_node;
        //cur_node = find(new_data, cur_node);
    //}

    //if (cur_node->num == M-1)
    //{
        //// full

    //}
    //else 
    //{
        //// not full
        //// so insert in node
        //cur_node = insert_in_node(new_data, cur_node);
    //}


//}


//int main()
//{


    //return 0;
//}


// plz using class. OK

#include<iostream>
#include"B.h"
using namespace std;


int main()
{
    // cout << 3/2 <<endl;
    return 0;
}