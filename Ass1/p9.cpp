#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include <iostream>
using namespace std;

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int leftChild;
    int rightChild;
    int height;
};

int Max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int height(Node *root)
{
    if(root == NULL)
        return 0;
    else
        return root -> height;
}

Node* new_node(int key, int leftChild, int rightChild)
{
    Node *tmp_node = (Node *) malloc( sizeof(Node) );
    tmp_node -> key = key;
    tmp_node -> left = NULL;
    tmp_node -> right = NULL;
    tmp_node -> height = 1;
    tmp_node -> leftChild = leftChild;
    tmp_node -> rightChild = rightChild;
    return tmp_node;
}

Node *right_rotation (Node* y)
{
    Node *x = y -> left;
    Node *T2 = x -> right;

    x -> right = y;
    y -> left = T2;

    y -> height = Max( height(y -> left), height(y -> right) ) + 1;
    x -> height = Max( height(x -> left), height(x -> right) ) + 1;

    if (T2 != NULL) y -> leftChild = T2 -> leftChild + T2 -> rightChild + 1;
    else y -> leftChild = 0;
    x -> rightChild = y -> leftChild + y -> rightChild + 1;

    return x;
}

Node *left_rotation (Node *x)
{
    Node *y = x -> right;
    Node *T2 = y -> left;

    y -> left = x;
    x -> right = T2;

    x -> height = Max( height(x -> left), height(x -> right) ) + 1;
    y -> height = Max( height(y -> left), height(y -> right) ) + 1;

    if (T2 != NULL) x -> rightChild = T2 -> leftChild + T2 -> rightChild + 1;
    else x -> rightChild = 0;
    y -> leftChild = x -> leftChild + x -> rightChild + 1;

    return y;
}

int get_balance_factor (Node *root)
{
    if (root == NULL) return 0;
    else return height(root -> left) - height(root -> right);
}

Node *Insert_Node(Node *root, int key)
{
    if (root == NULL) return new_node(key, 0, 0);
    if (key < root -> key)
    {
        root -> left = Insert_Node(root -> left, key);
        root -> leftChild++;
    }
    else if (key > root -> key)
    {
        root -> right = Insert_Node(root -> right, key);
        root -> rightChild++;
    }
    else return root;

    root -> height = Max( height(root -> left), height(root -> right) ) + 1;

    int balance = get_balance_factor(root);

    // 4 cases for unbalanced node
    if ( (balance > 1) && (key < root -> left -> key) ) return right_rotation(root);

    if ( (balance < -1) && (key > root -> right -> key) ) return left_rotation(root);

    if ( (balance > 1) && (key > root -> left -> key) )
    {
        root -> left = left_rotation(root -> left);
        return right_rotation(root);
    }

    if ( (balance < -1) && (key < root -> right -> key) )
    {
        root -> right = right_rotation(root -> right);
        return left_rotation(root);
    }

    return root;
}

int flag;

int search_by_key (Node *root, int key)
{
    if (root != NULL)
    {
        if (key > root -> key)
            return root -> leftChild + 1 + search_by_key(root -> right, key);
        else if (key < root -> key)
            return search_by_key(root -> left, key);
        else
            return root -> leftChild;
    }
    else
    {
        flag = 1;
        return -1;
    }
}

int main ()
{
    int n;
    cin>>n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int indicator;
        int num;
        cin>>indicator>>num;
        if (indicator == 1)
        {
            root = Insert_Node(root, num);
        }
        if (indicator == 2)
        {
            flag = 0;
            int index = search_by_key(root, num) + 1;
            if (flag == true)
            {
                cout<<"-1"<<endl;
            }
            else
            {
                cout<<index<<endl;
            }
        }
    }

    return 0;
}
