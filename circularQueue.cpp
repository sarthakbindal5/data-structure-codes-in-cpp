//CIRCULAR QUEUE IMPLEMENTATION
#include<iostream>
#include<cstddef>
#define N 5
using namespace std;

class circularQueue
{
public:
    int arr[N];
    int front, rear;
    circularQueue()
    { front = rear = -1; }
    
    void enqueue(int x);
    void dequeue();
    void display();
};

void circularQueue::enqueue(int x)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[rear] = x;
    }
    else if((rear+1) % N == front)
    {
        cout << "QUEUE OVERFLOW!\n";
        return;
    }
    else
    {
        rear = (rear+1) % N;
        arr[rear] = x;
    }
    cout << x << " was successfully enqueued!\n";
}

void circularQueue::dequeue()
{
    if(front == -1 && rear == -1)
        cout << "QUEUE UNDERFLOW!\n";
    else if(rear == front)
    {
        cout << arr[front] << " was successfully dequeued!\n";
        rear = front = -1;
    }
    else
    {
        cout << arr[front] << " was successfullt dequeued!\n";
        front = (front+1) % N;
    }
}

void circularQueue::display()
{
    cout << "The elements of the circular queue are:\n";
    int i;
    for(i = front; i != rear; i = (i+1) % N)
        cout << arr[i] << " ";
    cout << arr[i] << endl;
}

int main()
{
    circularQueue c;
    int choice, x;
    do
    {
        cout << "Menu-driven program!!\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete an element\n";
        cout << "3. Display queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter the element you want to enqueue: ";
                cin >> x;
                c.enqueue(x);
                break;
            case 2:
                c.dequeue();
                break;
            case 3:
                c.display();
                break;
            case 0:
                cout << "Exiting the program!!\n";
                break;
            default:
                cout << "Invalid input. Try again...\n";
        }
    }while(choice != 0);
    return 0;
}