#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "cell.hpp"


class CellTest : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE(CellTest);
CPPUNIT_TEST(test_init);
CPPUNIT_TEST_SUITE_END();

private:
    Cell cell;

public:
    void setUp() {}

    void tearDown() {}

    void test_init()
    {
        cell = Cell(2.0, 1.0);
        CPPUNIT_ASSERT(cell.foo == 2.0);
        CPPUNIT_ASSERT(cell.bar == 1.0);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(CellTest);
