
#include<queue>
#include<iomanip>
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
    AVLTree();
    ~AVLTree();

    int height();
    int max(int a, int b);
    
    void preOrder();
    void inOrder();
    void postOrder();

    AVLTreeNode<T>* search(T key);
    AVLTreeNode<T>* iterativeSearch(T key);

    T minimum();
    T maximum();

    void insert(T key);
    void remove(T key);
    void destory();
    void print();
private:
    int height(AVLTreeNode<T>* tree);

    void preOrder(AVLTreeNode<T>* tree) const;
    void inOrder(AVLTreeNode<T>* tree) const;
    void postOrder(AVLTreeNode<T>* tree) const;

    AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key) const;
    AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* x, T key) const;

    AVLTreeNode<T>* minimum(AVLTreeNode<T>* x);
    AVLTreeNode<T>* maximum(AVLTreeNode<T>* x);

    AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);
    AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);
    AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);
    AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);

    AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T key);
    AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z);

    void destory(AVLTreeNode<T>* &tree);

    void print(AVLTreeNode<T>* treem);

};

// struct function
template <class T>
AVLTree<T>::AVLTree():mRoot(NULL)
{
}

// destruct function
template <class T>
AVLTree<T>::~AVLTree()
{
    destory(mRoot);
}

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
void AVLTree<T>::preOrder(AVLTreeNode<T>* tree) const
{
    if (tree != NULL)
    {
        cout << tree->key << "  ";
        preOrder(tree->left);
        // cout << tree->key << "  ";
        preOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::preOrder()
{
    preOrder(mRoot);
}

template <class T>
void AVLTree<T>::inOrder(AVLTreeNode<T>* tree) const
{
//    if (tree == NULL)
//        return;
//    preOrder(tree->left);
//    if (tree->left != NULL)
//        cout << tree->left->key << "  ";
//    cout << tree->key << "  ";
//    preOrder(tree->right);
//    if (tree->right != NULL)
//        cout << tree->right->key << "  ";
//    return;
    if (tree != NULL)
    {
        inOrder(tree->left);
        cout << tree->key << "  ";
        inOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::inOrder()
{
    inOrder(mRoot);
}

template <class T>
void AVLTree<T>::postOrder(AVLTreeNode<T>* tree) const
{
    if (tree != NULL)
    {
        // cout << tree->key << "  ";
        postOrder(tree->left);
        // cout << tree->key << "  ";
        postOrder(tree->right);
        cout << tree->key << "  ";

    }
}

template <class T>
void AVLTree<T>::postOrder()
{
    postOrder(mRoot);
}

// 在成员函数后面加上const
// 当我们在主函数里const实例化了该类的一个对象
// 那该对象就只能使用const过的成员函数
template <class T>
AVLTreeNode<T>* AVLTree<T>::search(AVLTreeNode<T>* x, T key) const
{
    if (x == NULL || x->key == key)
        return x;
    
    if (key > x->key)
        return x->right;
    else 
        return x->left;
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::search(T key)
{
    return search(mRoot, key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::iterativeSearch(AVLTreeNode<T>* x, T key) const
{
    if (x == NULL || x->key == key)
        return x;
    while (x != NULL && x->key != key)
    {
        if (key > x->key)
            x = x->right;
        else 
            x = x->left;
    }
    return x;
    
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::iterativeSearch(T key)
{
    return iterativeSearch(mRoot, key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T>* tree)
{
    if (tree == NULL)
    {
        cout << "the tree is enpty!" << endl;
        return NULL;
    }
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    return tree;
}

template <class T>
T AVLTree<T>::minimum()
{
    AVLTreeNode<T>* p = minimum(mRoot);
    if (p == NULL)
        return (T)NULL;
    return p->key;
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::maximum(AVLTreeNode<T>* tree)
{
    if (tree == NULL)
    {
        cout << "the tree is empty!" << endl;
        return NULL;
    }
    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    return tree;
    
}

template <class T>
T AVLTree<T>::maximum()
{
    AVLTreeNode<T>* p = maximum(mRoot);
    if(p == NULL)
        return (T)NULL; // learn!
    return p->key;
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
    AVLTreeNode<T>* k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k2->right)) + 1;
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

    return leftLeftRotation(k3);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k1)
{
    k1->right = leftLeftRotation(k1->left);

    return rightRightRotation(k1);
}


// insert key and return the tree root
template <class T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &tree, T key)
{
    if (tree == NULL)
    {
        tree = new AVLTreeNode<T>(key, NULL, NULL);
        if (tree == NULL)
        {
            cout << "ERROR: no enough space!" << endl;
            return NULL;
        }
    }
    else if (key < tree->key)
    {
        tree->left = insert(tree->left, key);
        if (height(tree->left) - height(tree->right) == 2)
        {
            if (key < tree->left->key)
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        }
    }
    else if (key > tree->key)
    {
        tree->right = insert(tree->right, key);
        if (height(tree->right) - height(tree->left) == 2)
        {
            if (key > tree->right->key)
                tree = rightRightRotation(tree);
            else    
                tree = rightLeftRotation(tree);
        }
    }
    else
    {
        cout << "fail to insert, the tree already have the same node" << endl;
    }

    tree->height = max( height(tree->right), height(tree->left)) + 1;

    return tree;
}

template <class T>
void AVLTree<T>::insert(T key)
{
    insert(mRoot, key);
}




// del the node z and return the tree root
template <class T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z)
{
    if (tree == NULL || z == NULL)
    {
        return NULL;
    }

    if (z->key < tree->key)
    {
        tree->left = remove(tree->left, z);

        if (height(tree->right) - height(tree->left) == 2)
        {
            AVLTreeNode<T>* r = tree->right;
            if (height(r->left) > height(r->right))
                tree = rightLeftRotation(tree);
            else
                tree = rightRightRotation(tree);
        }
    }
    else if (z->key > tree->key)
    {
       tree->right = remove(tree->right, z);

       if (height(tree->left) - height(tree->right) == 2)
       {
            AVLTreeNode<T>* r = tree->left;
            if (height(r->right) > height(r->left))
                tree = leftRightRotation(tree);
            else
                tree = leftLeftRotation(tree);
       }
    }
    else
    {
        if ((tree->left != NULL) && (tree->right != NULL))
        {
            if (height(tree->left) > height(tree->right))
            {
                AVLTreeNode<T>* max = maximum(tree->left);
                tree->key = max->key;
                tree->left = remove(tree->left, max);
            }
            else
            {
                AVLTreeNode<T>* min = minimum(tree->right);
                tree->key = min->key;
                tree->right = remove(tree->right, min);
            }
        }
        else
        {
            AVLTreeNode<T>* tmp = tree;
            tree = (tree->left != NULL) ? tree->left : tree->right;
            delete tmp;
        }
    }
    return tree;
}

template <class T>
void AVLTree<T>::destory(AVLTreeNode<T>* &tree)
{
    if (tree == NULL)
        return;
    if (tree->left != NULL)
    {
        destory(tree->left);

    }

    if (tree->right != NULL)
    {
        destory(tree->right);
    }

    delete tree;

    return;
}

template <class T>
void AVLTree<T>::destory()
{
    destory(mRoot);
}

template <class T>
void AVLTree<T>::print(AVLTreeNode<T>* tree)
{
    queue<AVLTreeNode<T>*> tree_queue;
    tree_queue.push(tree);
    int cur_height = tree->height;
    while(!tree_queue.empty() && tree_queue.front() != NULL)
    {
        AVLTreeNode<T>* cur_node = tree_queue.front();
        tree_queue.pop();
        if (cur_node->height != cur_height)
        {
            cout << endl;
            cur_height = cur_node->height;
        }   
        cout << cur_node->key << "  ";
        if (cur_node->left != NULL)
            tree_queue.push(cur_node->left);
        if (cur_node->right != NULL)
            tree_queue.push(cur_node->right);
    }  
}

template <class T>
void AVLTree<T>::print()
{
    print(mRoot);
}