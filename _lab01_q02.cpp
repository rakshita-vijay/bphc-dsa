#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize smallest and largest element. Fill in the blanks (?).
    int smallest = arr[0];
    int largest = arr[sizeof(arr)];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
          smallest = arr[i];
        }
        if (arr[i] > largest) {
          largest = arr[i];
        }
    }

    cout << "Smallest element: " << smallest << endl;
    cout << "Largest element: " << largest << endl;
    return 0;
}
