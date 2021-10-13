//
// Created by Deblur on 2021-10-13.
//

#include <iostream>

class Point {
    int x, y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() { return x; }

    int getY() { return y; }

protected:
    void move(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class ColorPoint : public Point {
    std::string color;
public:
    ColorPoint(int x = 0, int y = 0, std::string color = "BLACK")
            : Point(x, y) {
        this->color = color;
    }

    void setPoint(int x, int y) {
        move(x, y);
    }

    void setColor(std::string color) {
        this->color = color;
    }

    void show() {
        std::cout << "color is " << color << " and it locates ("  << getX() << ", " << getY() << ")." << std::endl;
    }
};

int main() {
    ColorPoint zeroPoint;
    zeroPoint.show();

    ColorPoint cp(5,5);
    cp.setPoint(10,20);
    cp.setColor("BLUE");
    cp.show();

    return 0;
}