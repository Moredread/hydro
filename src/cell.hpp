#ifndef __CELL_HPP
#define __CELL_HPP

class Cell {

public:
    Cell(double foo = 0.0, double bar = 0.0) {
        this->foo = foo;
        this->bar = bar;
    }

    double set_foo(double foo) {
        this->foo = foo;
        return this->foo;
    }

    double get_foo() const {
        return foo;
    }

    double set_bar(double bar) {
        this->bar = bar;
        return this->bar;
    }

    double get_bar() const {
        return bar;
    }


private:
    double foo;
    double bar;

};

#endif
