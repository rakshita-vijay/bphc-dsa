#include <iostream>
using namespace std;

class B;  // Forward declaration

class A {
  int x;

  public:
    void setdata(int i) {
      x = i;
    }

  friend void min(A, B);  // Friend function declaration
};

class B {
  int y;

  public:
    void setdata(int i) {
      y = i;
    }

  friend void min(A, B);  // Friend function declaration
};

void min(A a, B b) {
  if (a.x < b.y)
    cout << a.x << endl;
  else
    cout << b.y << endl;
}

int main() {
  A a;
  B b;
  a.setdata(100);
  b.setdata(250);
  cout << "Min: ";
  min(a, b);  // Calling the friend function
  return 0;
}

/*
O/P:
Min: 100
*/

// what all access does min() have?: x & y
