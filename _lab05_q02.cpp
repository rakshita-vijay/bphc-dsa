// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

long factorialNonRecursive(int n) {
  long fact = 1;

  for (int i = 1; i <= n; i++) {
    fact *= i;
  }

  return fact;
}

long factorialNonTailRecursive(int n) {
  // Base case
  if(n == 0)
    return 1;

  long fact = factorialNonTailRecursive(n - 1);
  fact *= n;

  return fact;
}

long factorialTailRecursive(int n, int fact) {
  // Base case
  if (n == 0)
    return fact;

  return factorialTailRecursive(n - 1, n * fact);
}


int main() {
  int iterations = 1;

  while (iterations--)
  {
    cout << factorialNonRecursive(20) << endl;
    cout << factorialTailRecursive(10, 1) << endl;
    cout << factorialNonTailRecursive(5) << endl;
  }

  return 0;
}
