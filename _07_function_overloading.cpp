#include <iostream>
using namespace std;

class Add {
  public:
    int sum(int a, int b) {
      return (a + b);
    }

    int sum(int a, int b, int c) {
      return (a + b + c);
    }
};

int main() {
  Add obj;
  cout << obj.sum(35, 10) << endl;
  cout << obj.sum(100, 50, 50) << endl;
  return 0;
}

/*
O/P:
45
200
*/
