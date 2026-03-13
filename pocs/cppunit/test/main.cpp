#include <cppunit/TextTestRunner.h>

#include "test_suites.h"

int main() {
    CppUnit::TextTestRunner runner;
    runner.addTest(TestCalculatorSuite());
    runner.addTest(TestMockExampleSuite());
    return runner.run() ? 0 : 1;
}
