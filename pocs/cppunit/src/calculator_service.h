#ifndef CALCULATOR_SERVICE_H
#define CALCULATOR_SERVICE_H

#include "adder_interface.h"

/**
 * Service that uses an IAdder and doubles the result.
 * Used to demonstrate testing with a mock.
 */
class CalculatorService {
   public:
    explicit CalculatorService(IAdder& adder) : adder_(adder) {}

    int doubleSum(int a, int b) {
        int sum = adder_.add(a, b);
        return 2 * sum;
    }

   private:
    IAdder& adder_;
};

#endif  // CALCULATOR_SERVICE_H
