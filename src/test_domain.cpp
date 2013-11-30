#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <random>

#include "cell.hpp"
#include "domain.hpp"


using namespace hydro;

class DomainTest : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE(DomainTest);
CPPUNIT_TEST(test_add_cell);
CPPUNIT_TEST_SUITE_END();

private:
    CartesianDomain1D<Cell> domain;

public:
    void setUp() {
        domain = CartesianDomain1D<Cell>();
    }

    void tearDown() {}

    void test_add_cell() {
        domain.add_cell(Cell(1.0, 2.0));
        CPPUNIT_ASSERT_EQUAL(1, (int) domain.get_cells().size());
        CPPUNIT_ASSERT_EQUAL(2.0, domain.get_cells()[0].get_bar());
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(DomainTest);
