#include <iostream>
using namespace std;

#define max 5

int queue[max];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == max - 1) {
        cout << "queue overflow !\n";
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
        cout << x << " added\n";
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "queue underflow !\n";
    } else {
        cout << queue[front] << " removed\n";
        front++;
    }
}

void peek() {
    if (front == -1 || front > rear) {
        cout << "queue is empty\n";
    } else {
        cout << "front: " << queue[front] << "\n";
    }
}

void display() {
    if (front == -1 || front > rear) {
        cout << "queue is empty\n";
    } else {
        cout << "queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
}

bool isfull() {
    return rear == max - 1;
}

bool isempty() {
    return (front == -1 || front > rear);
}

int main() {
    int choice, val;
    while (1) {
        cout << "\n1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n";
        cout << "enter yor choice: ";
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
