#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cmath>

#include "cell.hpp"
#include "algorithm.hpp"


class AlgorithmTest : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE(AlgorithmTest);
CPPUNIT_TEST(test_algorithm);
CPPUNIT_TEST_SUITE_END();

private:
    Cell cell1, cell2;

public:
    void setUp() {
        cell1 = Cell(2.0, 1.0);
        cell2 = Cell(3.0, 2.0);
    }

    void tearDown() {}

    void test_algorithm()
    {
        CellTransition trans1, trans2;
        pseudo_advect<Cell, CellTransition>(cell1, cell2, &trans1, &trans2);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(1./6., trans1.get_foo(), 1e-8);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(-1./6., trans2.get_foo(), 1e-8);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(pow(2.0, 0.1), trans1.get_bar(), 1e-8);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(pow(2.0, -0.1), trans2.get_bar(), 1e-8);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(AlgorithmTest);
