//
// Created by Deblur on 2021-10-21.
//

#ifndef HW2_CPP_SHAPE_H
#define HW2_CPP_SHAPE_H


#include <cstddef>

class Shape { // node
    Shape *next;
protected:
    virtual void draw() = 0;

public:
    Shape() { next = NULL; }

    virtual ~Shape() {}

    void paint();

    Shape *add(Shape *p);

    Shape *getNext() { return next; }
};


#endif //HW2_CPP_SHAPE_H
