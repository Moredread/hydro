#ifndef __ALGORITHM_HPP
#define __ALGORITHM_HPP

#include <cmath>

// Number of useless algorithm repetitions
const int repeat = 1;

/**
 * This template function implements a pseudo algorithm for testing and
 * benchmarking purposes. It takes two cells as arguments and returns a
 * transition between these types.
 *
 * NOTE: the algorithm itself is utmost non-sense. It only serves the purpose
 * of performing some floating point operations.
 */
template <class CellType, class TransitionType>
void pseudo_advect(const CellType &cell1, const CellType &cell2,
    TransitionType *transition1, TransitionType *transition2)
{
    double dfoo, dbar;
    for (int i = 0; i < repeat; i++) {
        dfoo = (cell2.foo - cell1.foo) /
                      (1.0 + pow(cell2.bar, 2) + pow(cell1.bar, 2));
        dbar = pow(cell1.bar / cell2.bar, 0.1);
    }
    transition1->foo += dfoo;
    transition2->foo -= dfoo;
    transition1->bar /= dbar;
    transition2->bar *= dbar;
}

#endif

