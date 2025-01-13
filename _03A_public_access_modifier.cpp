#include <iostream>
using namespace std;

class Circle {
  public:
    double radius;

    double compute_area() {
      return 3.14 * radius * radius;
    }
};

int main() {
  Circle obj;

  obj.radius = 7.2;

  cout << "Radius is: " << obj.radius << endl;
  cout << "Area is: " << obj.compute_area() << endl;

  return 0;
}

/*
O/P:
Radius is: 7.2
Area is: 162.778
*/
