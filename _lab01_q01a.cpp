#include <iostream>
using namespace std;

int main() {
    double num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Perform operations. Few places are left blank (?)for you to fill in.
    cout << "Sum: " << num1 + num2 << endl;
    cout << "Difference: " << num1 - num2 << endl;
    cout << "Product: " << num1 * num2 << endl;

    // Handle division by zero
    if (num2 != 0) {
        cout << "Quotient: " << num1 / num2 << endl;
    } else {
        cout << "Division by zero is not allowed." << endl;
    }

    return 0;
}
