//QUEUE USING ARRAY
#include<iostream>
#include<cstddef>
using namespace std;
#define SIZE 5

class queueUsingStack
{
public:
    int arr[SIZE];
    int front, rear;
    
    queueUsingStack()
    { front = rear = -1; }
    
    void enqueue(int);
    void dequeue();
    void peek();
    void display();
};

void queueUsingStack::enqueue(int x)
{
    if(rear == SIZE-1)
        cout << "QUEUE OVERFLOW\n";
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[0] = x;
    }
    else
        arr[++rear] = x;
}

void queueUsingStack::dequeue()
{
    if((front == -1 && rear == -1) || (front > rear))
        cout << "The queue is empty...\n";
    else if(front == rear)
        front = rear = -1;
    else
        front++;
}

void queueUsingStack::peek()
{
    cout << "The frontmost element in the queue is " << arr[front] << ".\n";
}

void queueUsingStack::display()
{
    cout << "The elements of the queue are:\n";
    for(int i = front; i <= rear; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    queueUsingStack q;
    int choice;
    cout << "QUEUE IMPLEMENTATION USING ARRAY (STATIC MEMORY ALLOCATION)";
    do
    {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                int x;
                cout << "\nEnter number to be enqueued: ";
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
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