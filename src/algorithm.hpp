#ifndef __ALGORITHM_HPP
#define __ALGORITHM_HPP

#include <cmath>

// Number of useless algorithm repetitions
const int repeat = 1;

/**
 * This template function implements a pseudo algorithm for testing and
 * benchmarking purposes. It takes two cells as arguments and returns a
 * transition between these types.
 */
template <class CellType, class TransitionType>
TransitionType pseudo_advect(CellType cell1, CellType cell2)
{
    double dfoo, dbar;
    for (int i = 0; i < repeat; i++) {
        dfoo = (cell2.foo - cell1.foo) /
                      (1.0 + pow(cell2.bar, 2) + pow(cell1.bar, 2));
        dbar = cell1.bar * 0.01;
    }
    return TransitionType(dfoo, dbar);
}

#endif

