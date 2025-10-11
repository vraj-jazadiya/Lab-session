#include <iostream>
using namespace std;

#define max 5

int cq[max];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((front == 0 && rear == max - 1) || (rear + 1) % max == front) {
        cout << "queue overflow !\n";
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % max;
        }
        cq[rear] = x;
        cout << x << " added\n";
    }
}

void dequeue() {
    if (front == -1) {
        cout << "queue underflow !\n";
    } else {
        cout << cq[front] << " removed\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max;
        }
    }
}

void display() {
    if (front == -1) {
        cout << "queue is empty\n";
    } else {
        cout << "queue: ";
        int i = front;
        while (true) {
            cout << cq[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % max;
        }
        cout << "\n";
    }
}

void peek() {
    if (front == -1) {
        cout << "queue is empty\n";
    } else {
        cout << "front element: " << cq[front] << "\n";
    }
}

int main() {
    int choice, val;
    while (1) {
        cout << "\n1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n";
        cout << "enter yr choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "add: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "exit\n";
                return 0;
            default:
                cout << "invalid choice !\n";
        }
    }
    return 0;
}
