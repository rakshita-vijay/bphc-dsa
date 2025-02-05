#include <iostream>
using namespace std;

class Gate {
protected:
    // ???
    bool input1;
    bool input2;

public:
    Gate(bool in1, bool in2) : input1(in1), input2(in2) {} // constructor
    // assigning in1 to input1 and in2 to input2

    virtual bool getOutput() const = 0;
    // const: qualifier indicates that the function doesn't modify any member variables of the class
    // = 0: This is a pure virtual function, meaning the class that contains it is abstract. A pure virtual function has no implementation in the base class and must be overridden in any derived class. If a derived class does not implement this function, it will also be abstract

    virtual ~Gate() {}
};

class AndGate : public Gate {
public:
    AndGate(bool in1, bool in2) : Gate(in1, in2) {}

    bool getOutput() const override {
        return input1 && input2;
    }
};

class OrGate : public Gate {
public:
    // ???
    OrGate(bool in1, bool in2) : Gate(in1, in2) {}

    bool getOutput() const override {
        return input1 || input2;
    }
};

int main() {
    for (bool a : {false, true}) {
        for (bool b : {false, true}) {
            for (bool c : {false, true}) {
                cout << "A: " << a << "; B: " << b << "; C: " << c << '\n';

                OrGate o1(b, c);
                AndGate a1(a, o1.getOutput());
                cout << "A ^ (B U C): " << a1.getOutput() << '\n';

                // ???
                AndGate a2(a, b);
                AndGate a3(a, c);
                OrGate o2(a2.getOutput(), a3.getOutput());
                cout << "(A ^ B) U (A ^ C): " << o2.getOutput() << "\n\n";
            }
        }
    }

    return 0;
}
