#include <iostream>
using namespace std;

class Circle {
  private:
    double radius;

  public:
    void compute_area(double r) {
      radius = r;
      double area = 3.14 * radius * radius;

      cout << "Radius is: " << radius << endl;
      cout << "Area is: " << area << endl;
    }
};

int main() {
  Circle obj;

  obj.compute_area(7.2);

  return 0;
}

/*
O/P:
Radius is: 7.2
Area is: 162.778
*/
