//
// Created by 한현민 on 2021-10-17.
//

#include <iostream>

using namespace std;

class AbstractStack {
public:
    virtual bool push(int n) = 0;

    virtual bool pop(int &n) = 0;

    virtual int size() = 0;
};

class IntStack : public AbstractStack {
private:
    int *stack;
    int capacity;
    int top;
public:
    IntStack(int capacity) {
        this->capacity = capacity;
        stack = new int[this->capacity];

        for (int i = 0; i < this->capacity; i++) {
            stack[i] = 0;
        }

        top = -1;
    }

    bool push(int n) {
        if (top >= capacity - 1) {
            return false;
        }

        stack[++top] = n;

        return true;
    }

    bool pop(int &n) {
        if (top == -1) {
            return false;
        }

        n = stack[top--];

        return true;
    }

    int size() {
        return top;
    }

    ~IntStack() {
        delete[] stack;
    }
};

int main() {
    IntStack myStack(10);
    int n;

    for (int i = 0; i < 10; i++) {
        cin >> n;
        myStack.push(n);
    }

    cout << myStack.push(99) << endl;

    cout << myStack.pop(n) << endl;

    cout << n << endl;

    return 0;
}