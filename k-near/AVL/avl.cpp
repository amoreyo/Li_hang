#include<iostream>
#include"AVLTree.h"
using namespace std;

static int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
#define TBL_SIZE(a) ((sizeof(a)) / sizeof(a[0]))

int main()
{
    int i,ilen;
    // 不是很懂为什么要指针
    AVLTree<int>* tree = new AVLTree<int>();

    cout << "add: ";
    ilen = TBL_SIZE(arr);
    for (i = 0; i < ilen ;i++)
    {
        cout << arr[i] << "  ";
        tree->insert(arr[i]);
    }

    cout << "\n== pre: ";
    tree->preOrder();

    cout << "\n== in: ";
    tree->inOrder();

    cout <<"\n== post: ";
    tree->postOrder();

    cout << endl;


    tree->destory();
    return 0;
}