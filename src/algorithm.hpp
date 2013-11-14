#ifndef __ALGORITHM_HPP
#define __ALGORITHM_HPP

#include <cmath>


namespace hydro {

/**
 * Abstract base class for an algorithm.
 */
template <class Cell, class Transition>
class Algorithm
{

public:
    virtual void compute_transitions(const Cell &cell1, const Cell &cell2,
        Transition *transition1, Transition *transition2) = 0;

};


/**
 * This template implements a pseudo algorithm for testing and
 * benchmarking purposes.
 *
 * NOTE: the algorithm itself is utmost non-sense. It only serves the purpose
 * of performing some floating point operations.
 */
template <class Cell, class Transition>
class PseudoAlgorithm
{

public:
    explicit PseudoAlgorithm(int repeat = 1000) {
        this->repeat = repeat;
    }

    void compute_transitions(const Cell &cell1, const Cell &cell2,
        Transition &transition1, Transition &transition2) const
    {
        double dfoo, dbar;
        for (int i = 0; i < repeat; i++) {
            dfoo = (cell2.get_foo() - cell1.get_foo()) /
                          (1.0 + pow(cell2.get_bar(), 2) + pow(cell1.get_bar(), 2));
            dbar = pow(cell1.get_bar() / cell2.get_bar(), 0.1);
        }

        transition1.set_foo(transition1.get_foo() + dfoo);
        transition2.set_foo(transition2.get_foo() - dfoo);
        transition1.set_bar(transition1.get_bar() / dbar);
        transition2.set_bar(transition2.get_bar() * dbar);
    }

private:
    int repeat;

};

}

#endif
