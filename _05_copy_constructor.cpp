#include <iostream>
using namespace std;

class A {
  public:
    int x;

    A(int a) {
      x = a;
    }

    A(A &i) {
      x = i.x;
    }
};

int main() {
  A a1(230);
  A a2(a1);
  cout << a2.x << endl;
  return 0;
}

/*
O/P:
230
*/
