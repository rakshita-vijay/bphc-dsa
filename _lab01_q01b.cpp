#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int vowelCount = 0;

    cout << "Enter a string: ";
    getline(cin, str);

    // Count vowels. Few places are left blank (?)for you to fill in.
    for (char ch : str) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
    }

    // Output results
    cout << "Length of the string: " << str.length() << endl;
    cout << "Number of vowels: " << vowelCount << endl;

    return 0;
}
