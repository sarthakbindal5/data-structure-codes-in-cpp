//THREADED BINARY SEARCH TREE(TBST) IMPLEMENTATION
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
	node *left, *right;
	bool lthread; // false if left points to child
	bool rthread; // false if right points to ancestor
};

node *insert(node *root, int key)
{
	node *ptr = root;
	node *par = NULL; // Parent of key to be inserted
	while (ptr != NULL)
	{
		if (key == ptr->data)
		{
		    cout << "The key already exists!!!\n";
			return root;
		}
		par = ptr;
		if (key < ptr->data)
		{
			if (ptr->lthread == false) // if left points to child
				ptr = ptr->left;
			else
				break;
		}
		else
		{
			if (ptr->rthread == false) // if right points to ancestor
				ptr = ptr->right;
			else
				break;
		}
	}
	
	node *temp = new node;
	temp->data = key;
	temp->lthread = true; // left points to ancestor
	temp->rthread = true; // right points to child
	if (par == NULL)
	{
		root = temp;
		temp->left = NULL;
		temp->right = NULL;
	}
	else if (key < par->data)
	{
		temp->left = par->left;
		temp->right = par;
		par->lthread = false; // left points to child
		par->left = temp;
	}
	else
	{
		temp->left = par;
		temp->right = par->right;
		par->rthread = false; // right points to ancestor
		par->right = temp;
	}
	return root;
}

node* inorderSuccessor(node *ptr)
{
	if (ptr->rthread == true) // if right points to child
		return ptr->right;
	
	ptr = ptr->right;
	while (ptr->lthread == false) // if left points to child
		ptr = ptr -> left;
	return ptr;
}

void inorder(node *root)
{
	if (root == NULL)
		cout << "Tree is empty.";
	
	node *ptr = root;
	while (ptr->lthread == false) // if left points to child
		ptr = ptr->left;
	
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = inorderSuccessor(ptr);
	}
	cout << endl;
}

node* preorder(node *root)
{
    if(root != NULL)
        cout << root->data << " ";
    if(root->lthread == false)
        preorder(root->left);
    else
        return NULL;
    if(root->rthread == false)
        preorder(root->right);
    else
        return NULL;
}

int main()
{
    int x;
	node *root = NULL;
	while(true)
	{
	    cout << "Enter the element for the TBST(Enter -1 to stop): ";
	    cin >> x;
	    if(x == -1)
	        break;
	    root = insert(root, x);
	}
	inorder(root);
	root = preorder(root);
	return 0;
}