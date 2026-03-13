#ifndef REAL_ADDER_H
#define REAL_ADDER_H

#include "adder_interface.h"

class RealAdder : public IAdder {
   public:
    int add(int a, int b) override;
};

#endif  // REAL_ADDER_H
