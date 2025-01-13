#include <iostream>
using namespace std;

bool testSum(int a[], int n) {
  int sum = 0;

  for (int i = 0; i < n; i++) {
    sum += a[i];
  }

  return ((sum % 2) == 0);
}

int main() {
  int a[6] = {4, 4, 7, 6, 5, 2};
  bool result = testSum(a, 6);

  if (result) {
    cout << "Sum of all the numbers is even \n";
  } else {
    cout << "Sum of all the numbers is odd \n";
  }

  return EXIT_SUCCESS;
}

/*
O/P:
Sum of all the numbers is even
*/
