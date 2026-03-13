#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TextTestRunner.h>

#include "calculator.h"

class TestCalculator : public CppUnit::TestFixture {
   public:
    void setUp() override {}

    void tearDown() override {}

    void testAdd_PositiveNumbers() {
        CPPUNIT_ASSERT_EQUAL(5, add(2, 3));
    }

    void testAdd_Zero() {
        CPPUNIT_ASSERT_EQUAL(3, add(3, 0));
    }

    void testAdd_Negative() {
        CPPUNIT_ASSERT_EQUAL(-1, add(2, -3));
    }

    static CppUnit::Test* suite() {
        CppUnit::TestSuite* suite = new CppUnit::TestSuite("Calculator");
        suite->addTest(new CppUnit::TestCaller<TestCalculator>(
            "testAdd_PositiveNumbers", &TestCalculator::testAdd_PositiveNumbers));
        suite->addTest(
            new CppUnit::TestCaller<TestCalculator>("testAdd_Zero", &TestCalculator::testAdd_Zero));
        suite->addTest(new CppUnit::TestCaller<TestCalculator>("testAdd_Negative",
                                                               &TestCalculator::testAdd_Negative));
        return suite;
    }
};

CppUnit::Test* TestCalculatorSuite() {
    return TestCalculator::suite();
}
