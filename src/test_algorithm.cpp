#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cmath>

#include "cell.hpp"
#include "algorithm.hpp"


using namespace hydro;

class AlgorithmTest : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE(AlgorithmTest);
CPPUNIT_TEST(test_algorithm);
CPPUNIT_TEST_SUITE_END();

private:
    PseudoAlgorithm<Cell, CellTransition> algorithm;

public:
    void setUp() {
        algorithm = PseudoAlgorithm<Cell, CellTransition>(1);
    }

    void tearDown() {}

    void test_algorithm()
    {
        CellTransition trans1, trans2;
        Cell cell1(2.0, 1.0), cell2(3.0, 2.0);
        algorithm.compute_transitions(cell1, cell2, trans1, trans2);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(1./6., trans1.get_foo(), 1e-8);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(-1./6., trans2.get_foo(), 1e-8);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(pow(2.0, 0.1), trans1.get_bar(), 1e-8);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(pow(2.0, -0.1), trans2.get_bar(), 1e-8);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(AlgorithmTest);
