#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>

#include "calculator_service.h"
#include "mock_adder.h"

class TestMockExample : public CppUnit::TestFixture {
   public:
    void setUp() override {
        mock_.reset();
    }

    void tearDown() override {}

    void testServiceCallsAdderWithCorrectArgs() {
        mock_.setReturnValue(10);
        CalculatorService service(mock_);

        service.doubleSum(2, 3);

        CPPUNIT_ASSERT_EQUAL(1, mock_.callCount());
        CPPUNIT_ASSERT_EQUAL(2, mock_.lastA());
        CPPUNIT_ASSERT_EQUAL(3, mock_.lastB());
    }

    void testServiceDoublesResultFromAdder() {
        mock_.setReturnValue(5);
        CalculatorService service(mock_);

        int result = service.doubleSum(2, 3);

        CPPUNIT_ASSERT_EQUAL(10, result);
    }

    void testServiceCallsAdderOncePerInvocation() {
        mock_.setReturnValue(0);
        CalculatorService service(mock_);

        service.doubleSum(1, 2);
        service.doubleSum(3, 4);

        CPPUNIT_ASSERT_EQUAL(2, mock_.callCount());
        CPPUNIT_ASSERT_EQUAL(3, mock_.lastA());
        CPPUNIT_ASSERT_EQUAL(4, mock_.lastB());
    }

    static CppUnit::Test* suite() {
        CppUnit::TestSuite* suite = new CppUnit::TestSuite("MockExample");
        suite->addTest(new CppUnit::TestCaller<TestMockExample>(
            "testServiceCallsAdderWithCorrectArgs",
            &TestMockExample::testServiceCallsAdderWithCorrectArgs));
        suite->addTest(new CppUnit::TestCaller<TestMockExample>(
            "testServiceDoublesResultFromAdder",
            &TestMockExample::testServiceDoublesResultFromAdder));
        suite->addTest(new CppUnit::TestCaller<TestMockExample>(
            "testServiceCallsAdderOncePerInvocation",
            &TestMockExample::testServiceCallsAdderOncePerInvocation));
        return suite;
    }

   private:
    MockAdder mock_;
};

CppUnit::Test* TestMockExampleSuite() {
    return TestMockExample::suite();
}
