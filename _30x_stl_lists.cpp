#include <iostream>
#include <list>
#include <iterator>

using namespace std;

// Function for printing the elements in a list
void showlist(list<int> g) {
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main() {
    list<int> gqlist1, gqlist2;

    for (int i = 0; i < 10; ++i) {
        gqlist1.push_back(i * 2);
        gqlist2.push_front(i * 3);
    }

    cout << "List 1 (gqlist1) is : ";
    showlist(gqlist1);

    cout << "List 2 (gqlist2) is : ";
    showlist(gqlist2);

    cout << "\ngqlist1.front() : " << gqlist1.front();
    cout << "\ngqlist1.back() : " << gqlist1.back();

    gqlist1.pop_front();
    cout << "\nAfter gqlist1.pop_front() : ";
    showlist(gqlist1);

    gqlist2.pop_back();
    cout << "\nAfter gqlist2.pop_back() : ";
    showlist(gqlist2);

    gqlist1.reverse();
    cout << "\nAfter gqlist1.reverse() : ";
    showlist(gqlist1);

    gqlist2.sort();
    cout << "\nAfter gqlist2.sort() : ";
    showlist(gqlist2);

    return 0;
}












// List 1 (gqlist1) is :  0  2  4  6  8  10  12  14  16  18
// List 2 (gqlist2) is :  27  24  21  18  15  12  9  6  3

// gqlist1.front() : 0
// gqlist1.back() : 18
// gqlist1.pop_front() : 2  4  6  8  10  12  14  16  18

// gqlist2.pop_back() : 27  24  21  18  15  12  9  6

// gqlist1.reverse() : 18  16  14  12  10  8  6  4  2

// gqlist2.sort() : 3  6  9  12  15  18  21  24  27

// program source: https://www.geeksforgeeks.org/
