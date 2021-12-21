// buile the tree
// find alrio

#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int array_number = 20;
const int dim_number = 10;

struct Node
{
    Node *father;
    Node *right_chil;
    Node *left_chil;
    int *array;
};

Node* build_tree(int **array)
{
    // return the root
    // cur dim = deepth % all_dim + 1
    // in order to find the middle number, sort is necessary???
    // might be necessary
    int right_count = 0;
    int left_count = 0;
    int right_min = INT_MAX;
    int left_max = INT_MIN;

    // for (int i = 0; i < array_number ;i++)
    // {
    //     for (int j = 0; j< dim_number ;j++)
    //     {
    //         if(array[i][j] >= left_max)
    //         {
    //             left_count ++;
    //         }
    //         else // array[i][j] < right_min
    //         {    
    //         }
    //     }
    // }
}

int main()
{
    // init the random seed
    srand(time(NULL));

    // init the data array
    int all_D_array[array_number][dim_number]={0};
    for (int i = 0; i < array_number ;i++)
    {
        for (int j = 0; j< dim_number ;j++)
        {
            all_D_array[i][j] = rand() % 100 + 1; // [1,100]
        }
    }

    return 0;
}