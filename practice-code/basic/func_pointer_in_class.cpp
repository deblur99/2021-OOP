//
// Created by 한현민 on 2021-10-20.
//

#include <iostream>

using namespace std;

class A {
public:
    int m;

    void set(int val) {
        m = val;
        show();
    }

    void show() { cout << m << endl; }
};

int main() {
    void (A::*ptr)(int) = &A::set;

    A a;
    a.set(10);
    (a.*ptr)(20);
    A *b = &a;
    (b->*ptr)(30);
    return 0;
}