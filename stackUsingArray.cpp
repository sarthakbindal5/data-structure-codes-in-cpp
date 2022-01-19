//STACK USING ARRAY
#include <iostream>
#define SIZE 5
using namespace std;

class stackUsingArray
{
public:
    int arr[SIZE], top;
    stackUsingArray()
    {
        top = -1;
    }
    
    void push(int);
    void pop();
    void peak();
    void display();
};

void stackUsingArray::push(int x)
{
    if(top == SIZE-1)
        cout << "STACK OVERFLOW...\n";
    else
        arr[++top] = x;
}

void stackUsingArray::pop()
{
    if(top == -1)
        cout << "STACK UNDERFLOW...\n";
    else
        cout << "Element popped out of the stack is " << arr[top--] << ".\n";
}

void stackUsingArray::peak()
{
    cout << "The element at the top of the stack is " << arr[top] << ".\n";
}

void stackUsingArray::display()
{
    cout << "The stack elements are:\n";
    for(int i = top; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    stackUsingArray s;
    int choice;
    cout << "STACK IMPLEMENTATION USING ARRAYS (STATIC MEMORY ALLOCATION)";
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
                cout << "\nEnter number to be pushed: ";
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