// buile the tree
// find alrio

#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<vector>
using namespace std;

const int array_number = 5;
const int dim_number = 5; // dimention
const int Bucket_cap = 1000;
struct Node
{
    Node *father;
    Node *right_chil;
    Node *left_chil;
    int *array;
    // int index; // actually index is enough??? no !! or we have to design a find function again 
};
int cur_dim = 0;
typedef struct D2_array
{
    int array[dim_number] = {0};
}D2;

// len of 2-D
// int length(D2 array[])
// {
//     cout << sizeof(array) << endl;
//     cout << sizeof(int) << endl;
//     int len = sizeof(array)/(dim_number*sizeof(int));
//     cout << len << endl;
//     // int len = len1/dim_number;
//     return len;
// }
// that's in vain

// sort the particular dim
// void another_sort(D2 *array, int par_dim)
// {
//     // try the ugly sort first??
//     // Bucket sort
//     int Bucket[Bucket_cap] = {0};
//     int index[Bucket_cap][10] = {0};
//     int len = length(array);
//     for (int i = 0 ;i< len ;i++)
//     {
//         Bucket[array[i][par_dim]]++;
//         int j = 0;
//         while(index[array[i][par_dim]][j] != 0)
//         {
//             j++;
//         }
//         index[array[i][par_dim]][j] = i;
//     }
//     // how the random the right and left
//     int middle_len = int(len/2.0 + 0.5 + rand()%2);
//     // if odd like 3/2 = 1.5 + 0.5 = 2
//     // if even like 4/2 = 2 + 0.5 = 2.5 + random  0,1
//     int buck_num = 0;
//     for(int i = 0 ;i<Bucket_cap;i++)
//     {
//         if(Bucket[i] != 0)
//             buck_num++;
//         if(buck_num == middle_len)
//         {

//         }
//     }

// }

bool cmp(D2 a, D2 b)
{
    return a.array[cur_dim] <= b.array[cur_dim];
}

void build_tree(D2 *array, int par_dim, int start, int end)
{
    // end is not include
    if(start == end - 1)
        return;
    cur_dim = par_dim;
    sort(array+start, array+end, cmp);
    int middle_len = int((end - start)/2.0 + 0.5 + rand()%2);


    /* 
    return the root
    cur dim = deepth % all_dim + 1
    in order to find the middle number, sort is necessary???
    might be necessary

    iterator to build the tree
    first sort the cur dimetion's array 
    then find the middle number
    then split
    then iterator the turn
    until only one number left in the array

    pay attention : if the array is even , when we choose the middle numebr , 
    we have to balence the tree , so , choose the left then right then left like this turn
    glob a var is fine
    */


    // int right_count = 0;
    // int left_count = 0;
    // int right_min = INT_MAX;
    // int left_max = INT_MIN;
    // int len = length(array);// it's the len of first dim
    // if(len == 1) // is len equal to 1 then return 
    //     return;
    // sort(array, par_dim);

}

void print_2_D(D2 *array, int start, int end)
{
    // int len = length(array);
    // cout << len;
    // int len2 = sizeof(array[0])/sizeof(int);
    for ( int i = start;i<(start+ end);i++)
    {
        for (int j = 0;j<dim_number ;j++)
        {
            cout << array[i].array[j] << "  ";
        }
        cout  << endl;
    }
}


int main()
{
    // init the random seed
    srand(time(NULL));
    
    // init the data array
    D2 all_2D_array[array_number];
    // int all_D_array[array_number][dim_number]={0};
    for (int i = 0; i < array_number ;i++)
    {
        for (int j = 0; j< dim_number ;j++)
        {
            all_2D_array[i].array[j] = rand() % 100 + 1; // [1,100]
        }
    }
    
    //build_tree(all_2D_array, 0, 0, array_number);
    // print_2_D(all_2D_array, 0, array_number);
    // print_2_D(all_2D_array);
    // cout << endl;
    // sort(all_2D_array, all_2D_array + array_number, cmp); // at least this is right 
    // print_2_D(all_2D_array);
    // ok I got it , we just need to control the range

    return 0;
}