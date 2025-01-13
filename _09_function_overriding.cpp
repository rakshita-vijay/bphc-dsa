// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

class base {
  public:
    virtual void print() {
      cout << "Inside base class's print function" << endl;
    }

    void show() {
      cout << "Inside base class" << endl;
    }
};

class child : public base {
  public:
    void print() {
      cout << "Inside child class's print function" << endl;
    }

    void show() {
      cout << "Inside derived class" << endl;
    }
};

int main() {
  base* b;
  child c;
  b = &c;

  // Virtual function, bound at runtime (Runtime polymorphism)
  b->print();

  // Non-virtual function, bound at compile time
  b->show();

  return 0;
}

/*
O/P:
Inside child class's print function
Inside base class
*/
