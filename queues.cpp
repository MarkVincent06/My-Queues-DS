#include <iostream>
#include <stdlib.h>

using namespace std;

class Queue {
    private:
        int front;
        int rear;
        int array[6];

    public:
        // This default constructor will initialized front, rear and the array to zero
        Queue() {
            front = -1;
            rear = -1;
            for(int i=0; i<sizeof(array)/sizeof(array[0]); i++) {
                array[i] = 0;
            }
        }

        // This function will check if the array is empty or not
        bool isEmpty() {
            return front == -1 && rear == -1 ? true : false;
        }

        // This function will check if the array is full or not
        bool isFull() {
            return rear == sizeof(array)/sizeof(array[0]) - 1 ? true : false;
        }
       
       // This function adds an element in the front/tail of the queue
       void enqueue(int value) {
            if(isFull()) {
                cout << "Queue is already FULL!" << endl;
                return;
            } else if(isEmpty()) {
                front = 0;
                rear = 0;
                array[rear] = value;
            } else {
                rear++;
                array[rear] = value;
            }
            cout << "Enqueued " << value << " in Queue" << endl;
       }

       // This function removes the first available element from the head of a queue
       int dequeue() {
            int num = 0;
            if(isEmpty()) {
                cout << "No elements detected. Queue is EMPTY!" << endl;
                return 0;
            } else if(front == rear) {
                num = array[front];
                array[front] = 0;
                front = -1;
                rear = -1;
                return num;
            } else {
                num = array[front];
                array[front] = 0;
                front++;
                return num;
            }
       }

       // This function displays all the elements in the queue with the front and rear values
       void displayQueue() {
            cout << "\nFront = " << front << endl;
            cout << "Queue elements: ";
            for(int i=0; i<sizeof(array)/sizeof(array[0]); i++) {
                cout << array[i] << "     ";  
            }
            cout << "\nRear = " << rear << endl;
       }
};

bool tryAnotherOperation() {
    char choice;
    cout << "\nDo you want to select another operation(1 or 2)?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    cout << "Your choice: ";
    cin >> choice;

    return choice == '1' ? true : false;
}

int main() {
    Queue myQueue;
    char selection;
    int value;
    bool tryAnother = true;

    do {
        system("cls");

        cout << "\nWhat operation do you want to perform? Select Option Number(1-6)." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isFull()" << endl;
        cout << "4. isEmpty()" << endl;
        cout << "5. displayQueue()" << endl; 
        cout << "6. Exit" << endl;

        cout <<"\nYour selection: ";
        cin >> selection;

        switch(selection) {
            case '1': 
                cout << "\nPerforming an Enqueue Operation..." << endl;
                cout << "Enter a value to enqueue in the Queue: ";
                cin >> value;
                myQueue.enqueue(value);
                tryAnother = tryAnotherOperation();
                break;
            case '2': 
                cout << "\nPerforming a Dequeue Operation..." << endl;
                if(myQueue.isEmpty()) {
                    cout << "No elements detected. Queue is EMPTY!" << endl;
                } else {
                    cout << "The Dequeued Value is: " << myQueue.dequeue() << endl;
                }
                tryAnother = tryAnotherOperation();
                break;
            case '3': 
                myQueue.isFull() ? cout << "Queue is Full." << endl : cout << "Queue is not Full." << endl;
                tryAnother = tryAnotherOperation();
                break;
            case '4': 
                myQueue.isEmpty() ? cout << "Queue is Empty." << endl : cout << "Queue is not Empty." << endl;
                tryAnother = tryAnotherOperation();
                break;
            case '5': 
                myQueue.displayQueue();
                tryAnother = tryAnotherOperation();
                break;
            case '6':   
                break;
            default:
                cout << "ERROR! Invalid selection." << endl;
                break;
        }

    } while(selection != '6' && tryAnother);

    return 0;
}