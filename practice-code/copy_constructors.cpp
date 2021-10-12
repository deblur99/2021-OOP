//
// Created by 한현민 on 2021-10-12.
//

#include <iostream>
#include <string>
using namespace std;

class Person {
    int id;
    string name;
public:
    Person(int id, const string name);
    Person(const Person &person); // 복사 생성자
    ~Person();
    void changeName(const string name);
    void show() { cout << id << ", " << name << endl; }
};

Person::Person(int id, const string name) {
    this->id = id;
    this->name = name;
}

Person::Person(const Person &person) {
    this->id = person.id;
    this->name = person.name;
    cout << "Copy constructor has executed" << endl;
}

Person::~Person() {
    cout << "Destructor has executed" << endl;
}

int main() {
    Person a(10, "me");
    Person b(a); // 객체 a의 값을 b, c가 복사
    Person c = a;

    a.show();
    b.show();
    c.show();

    return 0;
}
