//SINGLY LINKED LIST IMPLEMENTATION
#include <iostream>
#include <cstddef>
using namespace std;

class singlyLinkedList
{
public:
    struct node
    {
        int data;
        struct node* next;
    }*head;
    
    singlyLinkedList()
    { head = NULL; }
    
    void displayList();
    void insertNode();
    void deleteNode();
};

void singlyLinkedList::displayList()
{
    node* temp = head;
    cout << "The elements in the linked list are:\n";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void singlyLinkedList::insertNode()
{
    node* newnode = new node;
    int pos;
    
    cout << "Enter the element to be inserted: ";
    cin >> newnode->data;
    newnode->next = NULL;
    
    cout << "Enter the position at which you want to add an element: ";
    cin >> pos;
    
    if(head == NULL)
        head = newnode;
    else
    {
        node* temp = head;
        for(int i = 1; i < pos-1; i++)
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
    displayList();
}

void singlyLinkedList::deleteNode()
{
    int pos;
    
    cout << "Enter the position at which you want the existing element to be deleted: ";
    cin >> pos;
    
    node* temp = head;
    for(int i = 1; i < pos - 1; i++)
        temp = temp->next;
    
    temp->next = (temp->next)->next;
    displayList();
}

int main()
{
    int choice;
    singlyLinkedList s;
    cout << "Menu-driven Program\n";
    do
    {
        cout << "1. Insert an element\n";
        cout << "2. Delete an element\n";
        cout << "3. Display the list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                s.insertNode();
                break;
            case 2:
                s.deleteNode();
                break;
            case 3:
                s.displayList();
                break;
            case 0:
                cout << "Exiting the program!!\n";
                break;
            default:
                cout << "Invalid input. Try again!!!\n";
        }
    }while(choice != 0);
    return 0;
}