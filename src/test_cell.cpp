#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <Eigen/Dense>
#include "cell.hpp"


using namespace hydro;

class HydroCellTest : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE(HydroCellTest);
CPPUNIT_TEST(test_init);
CPPUNIT_TEST(test_density);
CPPUNIT_TEST(test_velocity);
CPPUNIT_TEST(test_energy);
CPPUNIT_TEST_SUITE_END();

public:
    void setUp() {}
    void tearDown() {}

    void test_init() {
        HydroCell<double> cell(1.0, Eigen::Vector3d(1.0, -2.0, 3.0), 3.0);
        CPPUNIT_ASSERT_EQUAL(cell.get_density(), 1.0);
        CPPUNIT_ASSERT_EQUAL(cell.get_velocity(), Eigen::Vector3d(1.0, -2.0, 3.0));
        CPPUNIT_ASSERT_EQUAL(cell.get_energy(), 3.0);
    }

    void test_density() {
        HydroCell<double> cell(1.0, Eigen::Vector3d(1.0, -2.0, 3.0), 3.0);
        cell.set_density(2.0);
        CPPUNIT_ASSERT_EQUAL(cell.get_density(), 2.0);
    }

    void test_velocity() {
        HydroCell<double> cell(1.0, Eigen::Vector3d(1.0, -2.0, 3.0), 3.0);
        cell.set_velocity(Eigen::Vector3d(-1.0, 0.0, 4.0));
        CPPUNIT_ASSERT_EQUAL(cell.get_velocity(), Eigen::Vector3d(-1.0, 0.0, 4.0));
    }

    void test_energy() {
        HydroCell<double> cell(1.0, Eigen::Vector3d(1.0, -2.0, 3.0), 3.0);
        cell.set_energy(2.0);
        CPPUNIT_ASSERT_EQUAL(cell.get_energy(), 2.0);
    }

};


class CellTest : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE(CellTest);
CPPUNIT_TEST(test_init);
CPPUNIT_TEST_SUITE_END();

private:
    Cell cell;

public:
    void setUp() {
        cell = Cell(2.0, 1.0);
    }

    void tearDown() {}

    void test_init()
    {
        CPPUNIT_ASSERT_EQUAL(cell.get_foo(), 2.0);
        CPPUNIT_ASSERT_EQUAL(cell.get_bar(), 1.0);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(CellTest);


class CellTransitionTest : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE(CellTransitionTest);
CPPUNIT_TEST(test_init);
CPPUNIT_TEST(test_apply);
CPPUNIT_TEST_SUITE_END();

private:
    Cell cell;
    CellTransition trans;

public:
    void setUp() {
        cell = Cell(1.0, 2.0);
        trans = CellTransition(1.0, 0.5);
    }

    void tearDown() {}

    void test_init()
    {
        CPPUNIT_ASSERT_EQUAL(1.0, trans.get_foo());
        CPPUNIT_ASSERT_EQUAL(0.5, trans.get_bar());
    }

    void test_apply()
    {
        trans.apply(cell);
        CPPUNIT_ASSERT_EQUAL(2.0, cell.get_foo());
        CPPUNIT_ASSERT_EQUAL(1.0, cell.get_bar());
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(CellTransitionTest);
