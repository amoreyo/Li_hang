#include<iostream>
using namespace std;
// declare the code is not original
// I just need to review the class and template
template <class T>
class AVLTreeNode{
    public:
        T key;
        int height;
        AVLTreeNode* left;
        AVLTreeNode* right;

        AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r):
            key(value), height(0),left(l),right(r){} 
};



// AVLTree是AVL树对应的类。它包含AVL树的根节点mRoot和AVL树的基本操作接口。需要说明的是：AVLTree中重载了许多函数。
// 重载的目的是区分内部接口和外部接口，例如insert()函数而言，insert(tree, key)是内部接口，而insert(key)是外部接口。
// beacacuse people don't know the AVLTree<T> *mRoot
template <class T>
class AVLTree
{
private:
    AVLTreeNode<T> *mRoot;
public:
    AVLTree(/* args */);
    ~AVLTree();

    int height();
    int max(int a, int b);
    
    void preOrder();
    void inOrder();
    void postOrder();

    AVLTreeNode<T>* search(T key);
    AVLTreeNode<T>* iterativeSearch(T key);

    T minimum;
    T maximum;

    void insert(T key);
    void remove(T key);
    void destory();
    void print();
private:
    int height(AVLTreeNode<T>* tree);

    void preOrder(AVLTreeNode<T>* tree) const;
    void inOrder(AVLTreeNode<T>* tree) const;
    void inOrder(AVLTreeNode<T>* tree) const;

    AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key) const;
    AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* x, T key) const;

    AVLTreeNode<T>* minimum(AVLTreeNode<T>* x, T key) const;
    AVLTreeNode<T>* maximum(AVLTreeNode<T>* x, T key) const;

    AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);
    AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);
    AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);
    AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);

    AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T key);
    AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z);

    void destory(AVLTreeNode<T>* &tree);

    void print(AVLTreeNode<T>* treem, T key, int direction);

};

template <class T>
int AVLTree<T>::height(AVLTreeNode<T>* tree)
{
    if (tree != NULL)
    {
        return tree->height;
    }
    return 0;
}

template <class T>
int AVLTree<T>::height()
{
    return height(mRoot);
}

template <class T>
int AVLTree<T>::max(int a,int b)
{
    return a>b ? a:b;
} 

template <class T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
    AVLTreeNode<T>* k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k2->height)) + 1;
    return k1;
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>* k1)
{
    AVLTreeNode<T>* k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    return k2;
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* k3)
{
    k3->left = rightRightRotation(k3->left);

    reutrn leftLeftRotation(k3);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>* k1)
{
    k1->right = leftLeftRotation(k1->left);

    return rightRightRotation(k1);
}
