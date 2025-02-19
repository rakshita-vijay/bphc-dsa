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

    bool getOutput() const {
      return input1 && input2;
    }
};

class OrGate : public Gate {
  public:
    // ???
    OrGate(bool in1, bool in2) : Gate(in1, in2) {}

    bool getOutput() const {
      return input1 || input2;
    }
};

int main() {
  bool a = false;

  for (int i = 0; i <= 1; i++) {
    bool b = false;

    for (int j = 0; j <= 1; j++) {

      bool c = false;
      for (int k = 0; k <= 1; k++) {
        cout << "A: " << a << "; B: " << b << "; C: " << c << '\n';

        OrGate o1(b, c);
        AndGate a1(a, o1.getOutput());
        cout << "A ^ (B U C): " << a1.getOutput() << '\n';

        // ???
        AndGate a2(a, b);
        AndGate a3(a, c);
        OrGate o2(a2.getOutput(), a3.getOutput());
        cout << "(A ^ B) U (A ^ C): " << o2.getOutput() << "\n\n";

        AndGate a4(b, c);
        OrGate o3(a, a4.getOutput());
        cout << "A U (B ^ C): " << o3.getOutput() << "\n";

        OrGate o4(a, b);
        OrGate o5(a, c);
        AndGate a5(o4.getOutput(), o5.getOutput());
        cout << "(A U B) ^ (A U C): " << a5.getOutput() << "\n\n";

        c = true;
      }
      b = true;
    }
    a = true;
  }

  return 0;
}
