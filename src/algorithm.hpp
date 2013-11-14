#ifndef __ALGORITHM_HPP
#define __ALGORITHM_HPP

#include <cmath>

// Number of useless algorithm repetitions
const int repeat = 1000;

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
        dfoo = (cell2.get_foo() - cell1.get_foo()) /
                      (1.0 + pow(cell2.get_bar(), 2) + pow(cell1.get_bar(), 2));
        dbar = pow(cell1.get_bar() / cell2.get_bar(), 0.1);
    }
    transition1->set_foo(transition1->get_foo() + dfoo);
    transition2->set_foo(transition2->get_foo() - dfoo);
    transition1->set_bar(transition1->get_bar() / dbar);
    transition2->set_bar(transition2->get_bar() * dbar);
}


/**
 * This function is a test benchmark for the pseudo-algorithm. It should be
 * refactored if it proves to be useful.
 */
template <class CellType, class TransitionType>
void iterate_stuff(CellType* cells, const int n_cells, const int n_iterations) {
    for (int j = 0; j < n_iterations; j++) {
        // Compute transitions
        TransitionType trans[n_cells];
        for (int i = 0; i < n_cells - 1; i++) {
            pseudo_advect<CellType, TransitionType>(cells[i], cells[i + 1], &trans[i], &trans[i + 1]);
        }
        // Apply transitions to cells
        for (int i = 0; i < n_cells; i++) {
            trans[i].apply(&cells[i]);
        }
    }
}

#endif
