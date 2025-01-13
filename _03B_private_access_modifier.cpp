#include <iostream>
using namespace std;

class Circle {
  private:
    double radius;

  public:
    double compute_area() {
      return 3.14 * radius * radius;
    }
};

int main() {
  Circle obj;

  obj.radius = 7.2; // Error: radius is private

  cout << "Area is: " << obj.compute_area() << endl;

  return 0;
}

/*
O/P:
_03B_private_access_modifier.cpp:17:7: error: 'radius' is a private member of 'Circle'
   17 |   obj.radius = 7.2; // Error: radius is private
      |       ^
_03B_private_access_modifier.cpp:6:12: note: declared private here
    6 |     double radius;
      |            ^
1 error generated.
*/
