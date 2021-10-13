//
// Created by Deblur on 2021-10-13.
//

#include <iostream>
#include <string>

class Circle {
    int radius;
public:
    Circle(int radius = 0) { this->radius = radius; }

    int getRadius() { return radius; }

    void setRadius(int radius) { this->radius = radius; }

    double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle: public Circle {
    std::string name;
public:
    NamedCircle(int radius = 0, std::string name = "")
    : Circle(radius) {
        this->name = name;
    }

    std::string getName() { return name; }

    void setName(std::string name) { this->name = name; }

    void show() {
        std::cout << getName() << " with " << getRadius() << std::endl;
    }
};

void findWidestOne(NamedCircle *arr) {
    NamedCircle widest = arr[0];

    for (int i = 0; i < 5; i++) {
        if (widest.getRadius() < arr[i].getRadius()) {
            widest = arr[i];
        }
    }

    std::cout << "The widest pizza is " << widest.getName() << std::endl;
}

int main() {
    NamedCircle pizzaArr[5];
    int radius; std::string name;

    std::cout << "Enter 5 integers and 5 name of circles" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << ">>";
        std::cin >> radius;
        std::cin >> name;
        pizzaArr[i].setRadius(radius);
        pizzaArr[i].setName(name);
    }

    findWidestOne(pizzaArr);

    return 0;
}