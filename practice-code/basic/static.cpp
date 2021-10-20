//
// Created by 한현민 on 2021-10-20.
//

#include <iostream>

using namespace std;

class foo {
    static int number;
public:
    static void show() {
        cout << number << endl;
    }

    static void set(int val) {
        number = val;
    }
};

int foo::number = 100;

int main() {
    foo a;
    a.show();
    a.set(20);
    a.show();

    return 0;
}