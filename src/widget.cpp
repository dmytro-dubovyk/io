#include "widget.h"

#include <iostream>
#include <string>
#include <vector>

class Gadget {
};

struct Widget::Impl {
    std::string name ;
    std::vector<double> data;
    void doSomethig() {
        std::cout << "Doing something from pImpl" << std::endl;
    }
    Gadget g;
};

Widget::Widget()
    : pImpl{new Impl} {}

Widget::~Widget() {
    delete pImpl;
}

void Widget::processData() {
    pImpl->doSomethig();
}

