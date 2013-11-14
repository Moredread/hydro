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


class CellTransition : public Cell
{

public:

    CellTransition(double dfoo = 0.0, double dbar = 1.0)
        : Cell(dfoo, dbar) {}

    /**
     * This method applies the transition to a given cell.
     */
    void apply(Cell *cell) {
        cell->set_foo(cell->get_foo() + this->get_foo());
        cell->set_bar(cell->get_bar() * this->get_bar());
    }

};

#endif
