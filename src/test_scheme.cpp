#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <random>
#include <cmath>

#include "scheme.hpp"
#include "cell.hpp"
#include "domain.hpp"
#include "algorithm.hpp"


// Some typedefs for convenience

using namespace hydro;

class SchemeTest : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE(SchemeTest);
CPPUNIT_TEST(test_advance);
CPPUNIT_TEST(test_empty_advance);
CPPUNIT_TEST_SUITE_END();

private:
    typedef PseudoScheme<PseudoAlgorithm<Cell, CellTransition>,
        CartesianDomain1D<Cell>, Cell, CellTransition, double> Scheme;
    typedef PseudoAlgorithm<Cell, CellTransition> Algorithm;
    typedef CartesianDomain1D<Cell> Domain;

    Scheme scheme = Scheme(Algorithm(1));
    Domain domain = Domain();

public:
    void setUp() {
    }

    void tearDown() {}

    void test_advance()
    {
        std::default_random_engine gen;
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        for (int i = 0; i < 10; i++)
            domain.add_cell(Cell(dist(gen), pow(2.0, dist(gen))));
        scheme.advance(domain, 1.0);
    }

    void test_empty_advance()
    {
        CPPUNIT_ASSERT_EQUAL(0, (int) domain.get_cells().size());
        scheme.advance(domain, 1.0);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(SchemeTest);
