//BINARY TREE IMPLEMENTATION AND PRE/POST/INORDER TRAVERSAL
#include<iostream>
#include<cstddef>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
}*root;

node* create()
{
    int x = 0;
    node* newnode = new node;
    newnode->left = newnode->right = NULL;
    cout << "Enter data: ";
    cin >> x;
    if(x == -1)
        return NULL;
    else
    {
        newnode->data = x;
        cout << "Enter the data for the left node of " << newnode->data << ": ";
        newnode->left = create();
        cout << "Enter the data for the right node of " << newnode->data << ": ";
        newnode->right = create();
    }
    
    return newnode;
}

void inorder(node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

int main()
{
    int choice;
    cout << "Preparation of binary tree starts!\n";
    root = NULL;
    root = create();
    cout << "Enter 1 for preorder, 2 for inorder, 3 for postorder traversal:\n";
    cin >> choice;
    switch(choice)
    {
        case 1:
            preorder(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
    }
    return 0;
}