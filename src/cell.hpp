#ifndef __CELL_HPP
#define __CELL_HPP

#include <Eigen/Dense>


namespace hydro {


template <class Scalar>
class HydroCell {

public:
    explicit HydroCell(Scalar density, Eigen::Matrix<Scalar, 3, 1> velocity, Scalar energy)
    {
        this->density = density;
        this->velocity = velocity;
        this->energy = energy;
    }

    void set_density(const Scalar density)
    {
        this->density = density;
    }

    Scalar get_density() const {
        return density;
    }

    void set_velocity(const Eigen::Matrix<Scalar, 3, 1> velocity)
    {
        this->velocity = velocity;
    }

    Eigen::Matrix<Scalar, 3, 1> get_velocity() const
    {
        return velocity;
    }

    void set_energy(const Scalar energy)
    {
        this->energy = energy;
    }

    Scalar get_energy() const
    {
        return energy;
    }

private:
    Scalar density;
    Eigen::Matrix<Scalar, 3, 1> velocity;
    Scalar energy;

};


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
