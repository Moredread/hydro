#ifndef __CELL_HPP
#define __CELL_HPP


namespace hydro {

class Cell {

public:
    explicit Cell(double foo = 0.0, double bar = 0.0) {
        this->foo = foo;
        this->bar = bar;
    }

    void set_foo(double foo) {
        this->foo = foo;
    }

    double get_foo() const {
        return foo;
    }

    void set_bar(double bar) {
        this->bar = bar;
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

    explicit CellTransition(double dfoo = 0.0, double dbar = 1.0)
        : Cell(dfoo, dbar) {}

    /**
     * This method applies the transition to a given cell.
     */
    void apply(Cell &cell) {
        cell.set_foo(cell.get_foo() + get_foo());
        cell.set_bar(cell.get_bar() * get_bar());
    }

};

}

#endif
