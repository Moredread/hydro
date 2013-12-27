#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <thread>
#include <iostream>

#include "timer.hpp"

using namespace hydro;

class TimerTest : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE(TimerTest);
CPPUNIT_TEST(test_timer_nanos);
CPPUNIT_TEST(test_timer_seconds);
CPPUNIT_TEST_SUITE_END();

private:


public:
    void setUp() {
    }

    void tearDown() {}

    void test_timer_nanos() {
        CTimer timer = CTimer();
        timer.start();
        timer.stop();

        CPPUNIT_ASSERT_ASSERTION_PASS(CPPUNIT_ASSERT(timer.get_nanoseconds() > 0));
        CPPUNIT_ASSERT_ASSERTION_PASS(CPPUNIT_ASSERT(timer.get_nanoseconds() < 1e6));
    }

    void test_timer_seconds() {
        CTimer timer = CTimer();
        timer.start();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        timer.stop();

        CPPUNIT_ASSERT_DOUBLES_EQUAL(timer.get_seconds(), 0.1, 0.005);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(TimerTest);
