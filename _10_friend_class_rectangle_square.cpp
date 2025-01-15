#include <iostream>
using namespace std;

class Square;

class Rectangle {
  int width, height;

  public:
    int area() { return (width * height); }
    void convert(Square a);
};

class Square {
  friend class Rectangle;

  private:
    int side;

  public:
    Square(int a) : side(a) {} // constructor assigning a to side (side = a)
};

void Rectangle::convert(Square a) { // defining the previously stated function
  width = a.side;
  height = a.side;
}

int main() {
  Rectangle rect;
  Square sqr(7);
  rect.convert(sqr);
  cout << rect.area() << endl;
  return 0;
}

/*
O/P:
49
*/
