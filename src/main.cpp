#include <random>
#include <iostream>

#include "cell.hpp"
#include "algorithm.hpp"
#include "scheme.hpp"
#include "domain.hpp"
#include "timer.hpp"

using namespace hydro;

typedef PseudoScheme<PseudoAlgorithm<Cell, CellTransition>,
    CartesianDomain1D<Cell>, Cell, CellTransition, double> SchemeType;
typedef PseudoAlgorithm<Cell, CellTransition> AlgorithmType;
typedef CartesianDomain1D<Cell> DomainType;


/**
 * Main routine.
 */
int main() {
    CTimer setup_timer;
    CTimer run_timer;

    // setup
    setup_timer.start();
    std::default_random_engine gen;
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    DomainType domain;
    SchemeType scheme(AlgorithmType(1));
    for (int i = 0; i < 10; i++)
        domain.add_cell(Cell(dist(gen), pow(2.0, dist(gen))));
    setup_timer.stop();

    run_timer.start();
    scheme.advance(domain, 1.0);
    run_timer.stop();

    std::cout << "Setup time: " << setup_timer.get_seconds() << std::endl;
    std::cout << "Run time: " << run_timer.get_seconds() << std::endl;

    return 0;
}
