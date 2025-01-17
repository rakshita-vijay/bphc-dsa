#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector <double> v;
  int i;
  v.push_back(56.5); // basically .add()
  cout << "Size of the vector: " << v.size() << endl;

  for(i = 1; i < 4; i++) {
    v.push_back(v[0] + i);
  }
  cout << "Expanded size: " << v.size() << endl;

  for(i = 0; i < 4; i++) {
    cout << "Value of vector " << i << ": " << v[i] << endl;
  }

  vector <double>::iterator t = v.begin();
  while(t != v.end()) {
    cout << "Value through iterator = " << *t << endl;
    t++;
  }
  return 0;
}
