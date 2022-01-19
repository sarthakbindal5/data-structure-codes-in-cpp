//STACK USING LINKED LIST
#include<iostream>
#include<cstddef>
using namespace std;

class stackUsingLinkedList
{
public:
    struct node
    {
        int data;
        node* next;
    };
    node* top;
    
    stackUsingLinkedList()
    { top = NULL; }
    
    void push(int x);
    void pop();
    void peak();
    void display();
};

void stackUsingLinkedList::push(int x)
{
    node* newnode = new node;
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void stackUsingLinkedList::pop()
{
    if(top == NULL)
        cout << "STACK UNDERFLOW...\n";
    else
    {
        cout << "Element pushed out of stack is " << top->data << ".\n";
        node* temp = top;
        top = top->next;
        temp->next = NULL;
        free((void*)temp);
    }
}

void stackUsingLinkedList::peak()
{
    if(top == NULL)
        cout << "The stack is empty...";
    else
        cout << "The topmost element in the stack is " << top->data << ".\n";
}

void stackUsingLinkedList::display()
{
    node* temp = top;
    cout << "The stack elements are:\n";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    stackUsingLinkedList s;
    int choice;
    cout << "STACK IMPLEMENTATION USING LINKED LISTS (DYNAMIC MEMORY ALLOCATION)";
    do
    {
        cout << "\n1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peak\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                int x;
                cout << "Enter number to be pushed: ";
                cin >> x;
                s.push(x);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peak();
                break;
            case 4:
                s.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid input. Try again...\n";
        }
    }while(choice);
    return 0;
}