#include <iostream>
using namespace std;

class student_marks {
  protected:
    int rollNo, marks1, marks2;

  public:
    void get() {
      cout << "Enter the ID No.: ";
      cin >> rollNo;
      cout << "Enter the Midsem and Compre marks: ";
      cin >> marks1 >> marks2;
    }
};

class lab_marks {
  protected:
    int lmarks;

  public:
    void getLm() {
      cout << "Enter the mark for lab exam: ";
      cin >> lmarks;
    }
};

class Result : public student_marks, public lab_marks {
  int total_marks; // by default, it is private

  public:
    void display() {
      total_marks = (marks1 + marks2 + lmarks);
      cout << "\nID No: " << rollNo;
      cout << "\nTotal marks: " << total_marks << endl;
    }
};

int main() {
  Result res;
  res.get();
  res.getLm();
  res.display();
}

/*
O/P:
Enter the ID No.: 2010
Enter the Midsem and Compre marks: 50 50
Enter the mark for lab exam: 50

ID No: 2010
Total marks: 150
*/
