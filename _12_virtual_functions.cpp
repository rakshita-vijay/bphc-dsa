#include <iostream>
using namespace std;

class Parent { // Base class
  public:
    virtual void show() = 0; // Pure virtual function
};

class Child : public Parent { // Derived class
  public:
    void show() {
      cout << "Implementation of Virtual Function in Child class\n";
    }
};

int main() {
  Parent *b;
  Child c;
  b = &c;
  b->show();
  return 0;
}

/*
O/P:
Implementation of Virtual Function in Child class
*/
