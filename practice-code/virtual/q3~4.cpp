//
// Created by 한현민 on 2021-10-17.
//

#include <iostream>
#include <string>

using namespace std;

class LoopAdder {
private:
    string name;
    int x,y,sum;
    void read();
    void write();

protected:
    LoopAdder(string name = "") {
        this->name = name;
    }
    int getX(){return x;}
    int getY(){return y;}
    virtual int calculate() = 0;

public:
    void run();
};

void LoopAdder::read() {
    cout << name << ":" << endl;
    cout << "add first number and second number. enter two numbers >>";
    cin >> x >> y;
}

void LoopAdder::write() {
    cout << "sum from " << x << " to " << y << " = " << sum << endl;
}

void LoopAdder::run() {
    read();
    sum = calculate();
    write();
}

class ForLoopAdder: public LoopAdder {
protected:
    int calculate() {
        int sum = 0;

        for (int i = getX(); i <= getY(); i++) {
            sum += i;
        }

        return sum;
    }
public:
    ForLoopAdder(string name) : LoopAdder(name) {}
};

class WhileLoopAdder: public LoopAdder {
protected:
    int calculate() {
        int sum = 0;
        int idx = getX();

        while (idx <= getY()) {
            sum += idx;
            idx++;
        }

        return sum;
    }
public:
    WhileLoopAdder(string name): LoopAdder(name) {}
};

class DoWhileLoopAdder: public LoopAdder {
protected:
    int calculate() {
        int sum = 0;
        int idx = getX();

        do {
            if (idx > getY()) {
                return sum;
            }
            sum += idx;
            idx++;
        } while (idx <= getY());

        return sum;
    }
public:
    DoWhileLoopAdder(string name): LoopAdder(name) {}
};

int main() {
    ForLoopAdder forLoop("For Loop");
    forLoop.run();

    WhileLoopAdder whileLoop("While Loop");
    whileLoop.run();

    DoWhileLoopAdder doWhileLoop("Do While Loop");
    doWhileLoop.run();
}