//
// Created by 한현민 on 2021-10-12.
//

#include <iostream>

using namespace std;

void pal(int num) {
    cout << "pal says " << num << endl;
}

class bar {
private:
    void inner_pal() {
        cout << "inner" << endl;
    }

protected:
    void inner_pal_prt() {
        cout << "inner" << endl;
    }

public:
    void inner_pal_pub() {
        cout << "inner" << endl;
    }
};

class foo {
private:
    static int count; // 기본적으로 static int 변수는 0으로 초기화되어 있어 0으로 지정할 필요 없음
    // 주의) static 클래스 변수를 사용하려면 클래스 외부에서 선언 또는 초기화해야 하며,
    // static 멤버 함수에서는 static 변수만 사용할 수 있다. (non-static 변수 사용 X)

    int num;

public:
    foo(int num) {
        cout << "Object has created" << endl;
        count++;
        getCount();

        this->num = num;
    }

    static void getCount() {
        cout << count << endl;
    }

    // friend void bar::inner_pal(); -> friend는 private 멤버 함수를 가져올 수 없다.
    // friend void bar::inner_pal_prt(); -> protected 멤버 함수도 마찬가지
    friend void bar::inner_pal_pub(); // public 멤버 함수만 가져올 수 없다.

    friend void pal() {
        cout << "pal says " << num << endl;
    };
};

int foo::count = 5; // 외부에서 반드시 초기화해야 사용할 수 있음

int main() {
    foo a = foo();
    foo b = foo();
    foo c = foo();
    foo d = foo();
    foo e = foo();

    pal(10);


    return 0;
}