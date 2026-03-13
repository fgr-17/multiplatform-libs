#ifndef MOCK_ADDER_H
#define MOCK_ADDER_H

#include "adder_interface.h"

/**
 * Mock implementation of IAdder for testing.
 * Records call count and last arguments; can return a fixed value.
 */
class MockAdder : public IAdder {
   public:
    MockAdder() : return_value_(0), call_count_(0), last_a_(0), last_b_(0) {}

    int add(int a, int b) override {
        call_count_++;
        last_a_ = a;
        last_b_ = b;
        return return_value_;
    }

    void setReturnValue(int value) {
        return_value_ = value;
    }
    int callCount() const {
        return call_count_;
    }
    int lastA() const {
        return last_a_;
    }
    int lastB() const {
        return last_b_;
    }
    void reset() {
        call_count_ = 0;
        last_a_ = 0;
        last_b_ = 0;
    }

   private:
    int return_value_;
    int call_count_;
    int last_a_;
    int last_b_;
};

#endif  // MOCK_ADDER_H
