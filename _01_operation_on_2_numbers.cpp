#include <iostream>
using namespace std;

int main() {
  double num1, num2;
  cout << "Enter the first number: ";
  cin >> num1;
  cout << "Enter the second number: ";
  cin >> num2;

  cout << "Sum: " << (num1 + num2) << endl;
  cout << "Difference: " << (num1 - num2) << endl;
  cout << "Product: " << (num1 * num2) << endl;

  if (num2 != 0) {
    cout << "Quotient: " << (num1 / num2) << endl;
  } else {
    cout << "Division by zero is not allowed." << endl;
  }

  return 0;
}

/*
O/P:
Enter the first number: 21
Enter the second number: 34
Sum: 55
Difference: -13
Product: 714
Quotient: 0.617647
*/
