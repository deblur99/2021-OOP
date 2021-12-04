//
// Created by 한현민 on 2021-12-04.
//

#include <iostream>
#include <string>

using namespace std;

class Coffee {
public:
    virtual string Operation() = 0;
};

class Americano: public Coffee {
public:
    string Operation() {
        return "Americano";
    }
};

class Mocha: public Coffee {
public:
    string Operation() {
        return "Mocha";
    }
};

class Creator {
public:
    virtual Coffee* FactoryMethod() = 0;

    string create() {
        Coffee *product = this->FactoryMethod();
        string result = product->Operation();
        delete product; // 생성하고자 하는 객체 생성 후 소멸

        cout << result << endl;

        return result;
    }
};

class AmericanoCreator: public Creator {
public:
    Coffee* FactoryMethod() {
        return new Americano();
    }
};

class MochaCreator: public Creator {
public:
    Coffee* FactoryMethod() {
        return new Mocha();
    }
};

int main() {
    // 생성하고자 하는 클래스의 Factory 객체를 생성하고,
    // 객체의 create 메서드를 호출하여 작업을 수행한다.
    Creator *creator = new AmericanoCreator();
    creator->create(); // prints Americano

    creator = new MochaCreator();
    creator->create(); // prints Mocha

    delete creator;

    return 0;
}