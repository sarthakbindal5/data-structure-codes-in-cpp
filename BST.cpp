//BINARY SEARCH TREE IMPLEMENTATION
#include<iostream>
#include<cstddef>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
}*root;

node* create(node* root, int x)
{
    
    if(root == NULL)
    {
        node* newnode = new node;
        newnode->data = x;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    else if(x > root->data)
        root->right = create(root->right, x);
    else if(x < root->data)
        root->left = create(root->left, x);
    return root;
}

void inorder(node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* search(node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    else if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

node* deleteNode(node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left==NULL and root->right==NULL)
            return NULL;
        else if (root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        //to find the inorder successor of the node in case of 2 children
        node* current = root->right;
        while (current && current->left != NULL)
            current = current->left;
        root->data = current->data;
        root->right = deleteNode(root->right, current->data);
    }
    return root;
}

int main()
{
    int x, key;
    while(true)
    {
        cout << "Enter data to be entered in the BST. Enter -1 to exit:\n";
        cin >> x;
        if(x == -1)
            break;
        root = create(root, x);
    }
    int choice;
    do
    {
        cout << "\n1. Inorder Traversal\n";
        cout << "2. Search for an element\n";
        cout << "3. Delete an element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << "The inorder traversal of the BST made above is:\n";
                inorder(root);
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "Enter the number to be searched:\n";
                cin >> key;
                node* srch = search(root, key);
                if(srch == NULL)
                    cout << "Element was not found in the BST.\n";
                else
                    cout << "Element " << srch->data << " was found!\n";
                break;
            }
            case 3:
            {
                cout << "Enter the number to be deleted:\n";
                cin >> key;
                root = deleteNode(root, key);
                cout << "The inorder traversal of the BST made above is:\n";
                inorder(root);
                cout << endl;
                break;
            }
            case 0:
                cout << "Exiting!!\n";
                break;
            default:
                cout << "Invalid input. Try again...\n";
        }
    }while(choice != 0);
    return 0;
}