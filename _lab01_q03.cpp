#include <iostream>
using namespace std;

// Binary Search Function
bool binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (high + low) / 2;

        // Check if the target is at the middle. Fill in the blanks (?).
        if (arr[mid] == target) {
            return true;
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    return false; // Target not found
}

int main() {
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number to search: ";
    cin >> target;

    bool result = binarySearch(arr, n, target);

    // Output the result
    if (result) {
        cout << "Number " << target << " exists in the array." << endl;
    } else {
        cout << "Number " << target << " does not exist in the array." << endl;
    }

    return 0;
}
