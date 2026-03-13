#ifndef ADDER_INTERFACE_H
#define ADDER_INTERFACE_H

class IAdder {
   public:
    virtual ~IAdder() = default;
    virtual int add(int a, int b) = 0;
};

#endif  // ADDER_INTERFACE_H
