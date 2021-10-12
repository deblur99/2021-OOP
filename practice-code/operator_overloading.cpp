//
// Created by 한현민 on 2021-10-12.
//

#include <iostream>
#include <string>

using namespace std;

class foo {
private:
    int x; int y;

public:
    void set(int x, int y) {
        this->x = x; this->y = y;
    }

    void operator ++ () { // prefix
        x++; y++;
    }

    foo operator + (int op) {
        foo result;
        result.x = this->x + op;
        result.y = this->y + op;
        return result;
    }

    foo operator + (foo op) {
        foo result;
        result.x = this->x + op.x;
        result.y = this->y + op.y;
        return result;
    }

    operator double() { // 형변환 키워드 오버로딩은 반환형을 지정하지 않지만, 반환은 가능하다.
        return (double(x) + double(y)) / 2;
    }

    foo& operator >> (int op) {
        this->x += op;
        this->y += op;
        return *this;
    }

    void show() {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main() {
    foo m;
    foo n;

    m.set(10, 15);
    n.set(20, 25);

    (m + n).show();
    (n + 100).show();
    ++m;

    // double b; -> double형 변수 b 선언 (오버로딩 X)
    double a = double(m); // double(class foo 객체) -> 오버로딩 O
    cout << a << endl;

    foo b;
    b.set(0, 0);
    b >> 3 >> 5 >> 6; // 참조값을 반환하는 연산자 오버로딩은 this 포인터의 역참조 (*this)를 반환한다.
    b.show();

    return 0;
}