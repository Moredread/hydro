#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

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
        Cell result = pseudo_advect<Cell, Cell>(cell1, cell2);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(1./6., result.foo, 1e-8);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(0.01, result.bar, 1e-8);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(AlgorithmTest);
