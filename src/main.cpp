#include <random>

#include "cell.hpp"
#include "algorithm.hpp"


/**
 * Generator for random input data. Just to have some test data to work with.
 */
Cell* generate_random_data(int n_cells) {
    using namespace std;
    // Random number generator
    default_random_engine gen;
    uniform_real_distribution<double> dist(0.0, 1.0);

    // Generate initial cells
    Cell * cells = new Cell[n_cells];
    for (int i = 0; i < n_cells; i++) {
        cells[i] = Cell(dist(gen), dist(gen));
    }
    return cells;
}


/**
 * Main routine. Simply calls the template function above.
 */
int main() {
    const int n_cells = 2000;
    Cell *cells = generate_random_data(n_cells);
    iterate_stuff<Cell, CellTransition>(cells, n_cells, 20);
    return 0;
}
