#include <iostream>
#include <string>
using namespace std;

class Adder {
  private:
    string value;

  public:
    Adder(string v = "") : value(v) {}

    Adder operator+(const Adder& obj) {
      // Check if both values are numeric
      if (isNumber(value) && isNumber(obj.value)) {
        // Add numeric values
        double result = stod(value) + stod(obj.value);
        return Adder(to_string(result));
      } else {
        // Concatenate string values
        return Adder(value + obj.value);
      }
    }

    void display() const {
      cout << value << endl;
    }

  private:
    // Helper function to check if a string represents a number
    static bool isNumber(const string& s) {
      return (!s.empty() && (s.find_first_not_of("0123456789.-") == string::npos));
    }
};

int main() {
  Adder a1("45"), a2("55");
  Adder a3 = a1 + a2;
  cout << "Addition of numbers: ";
  a3.display();

  Adder s1("Hello, "), s2("World!");
  Adder s3 = s1 + s2;
  cout << "Concatenation of strings: ";
  s3.display();

  return 0;
}

/*
O/P:
Addition of numbers: 100.000000
Concatenation of strings: Hello, World!
*/
