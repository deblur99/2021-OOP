//
// Created by Deblur on 2021-10-16.
//

#include <iostream>

using namespace std;

class BaseArray {
private:
    int capacity; // size of array
    int *mem;   // array
protected:
    BaseArray(int capacity) {
        this->capacity = capacity;
        mem = new int[capacity];
    }

    ~BaseArray() {
        delete[] mem;
    }

    void put(int idx, int val) {
        if (idx >= capacity) {
            cout << "index is out of range" << endl;
            return;
        }

        mem[idx] = val;
    }

    int get(int idx) {
        if (idx >= capacity) {
            cout << "index is out of range" << endl;
            return -1;
        }

        return mem[idx];
    }

    int getCapacity() {
        return capacity;
    }
};

class MyQueue : protected BaseArray {
private:
    int front;
    int rear;
public:
    MyQueue(int capacity) : BaseArray(capacity) {
        front = rear = -1;
    }

    void enqueue(int val) {
        if (front == getCapacity()) {
            return; // check whether queue is full
        }

        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            front++;
        }

        BaseArray::put(front, val);

        return;
    }

    int dequeue() {
        int ret;

        if (front == rear == -1) {
            return -1;  // check whether queue is empty
        }

        ret = BaseArray::get(rear);

        if (front == rear) {
            front = rear = -1;
        } else {
            rear++;
        }

        return ret;
    }

    int capacity() {
        return getCapacity();
    }

    int length() {
        if (front == -1 && rear == -1) {
            return 0;
        } else {
            return front + 1;
        }
    }
};

class MyStack : protected BaseArray {
private:
    int top;
public:
    MyStack(int capacity) : BaseArray(capacity) {
        top = -1;
    }

    void push(int val) {
        if (top == getCapacity())
            return;
        top++;
        BaseArray::put(top, val);
        return;
    }

    int pop() {
        if (top == -1)
            return -1;
        int ret = BaseArray::get(top);
        top--;
        return ret;
    }

    int length() {
        if (top == -1) {
            return 0;
        } else {
            return top + 1;
        }
    }

    int capacity() {
        return getCapacity();
    }
};

void Q5() {
    MyQueue mQ(100);
    int n;

    cout << "Enter 5 integers to insert into queue >>";

    for (int i = 0; i < 5; i++) {
        cin >> n;
        mQ.enqueue(n);
    }

    cout << "Capacity of queue: " << mQ.capacity() << ", Size of queue: " << mQ.length() << endl;

    cout << "Print elements of queue by getting rid of each of them >> ";

    while (mQ.length() != 0) {
        cout << mQ.dequeue() << " ";
    }

    cout << endl << "Current size of queue : " << mQ.length() << endl;

    return;
}

void Q6() {
    MyStack mStack(100);
    int n;
    cout << "Enter 5 integers to push into stack>>";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mStack.push(n);
    }
    cout << "Capacity of stack: " << mStack.capacity() << ", Size of stack: " << mStack.length() << endl;
    cout << "Sum all elements of stack and print it>> ";
    while (mStack.length() != 0) {
        cout << mStack.pop() << " ";
    }
    cout << endl << "Current size of stack : " << mStack.length() << endl;

    return;
}

int main() {
    Q5();
    Q6();

    return 0;
}