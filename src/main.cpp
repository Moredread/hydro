#include <random>

#include "cell.hpp"
#include "algorithm.hpp"
#include "scheme.hpp"
#include "domain.hpp"


using namespace hydro;

typedef PseudoScheme<PseudoAlgorithm<Cell, CellTransition>,
    CartesianDomain1D<Cell>, Cell, CellTransition, double> SchemeType;
typedef PseudoAlgorithm<Cell, CellTransition> AlgorithmType;
typedef CartesianDomain1D<Cell> DomainType;


/**
 * Main routine.
 */
int main() {
    // setup
    std::default_random_engine gen;
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    DomainType domain;
    SchemeType scheme(AlgorithmType(1));
    for (int i = 0; i < 10; i++)
        domain.add_cell(Cell(dist(gen), pow(2.0, dist(gen))));
    scheme.advance(domain, 1.0);
    return 0;
}
