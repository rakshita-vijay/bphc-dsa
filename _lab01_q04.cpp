#include <iostream>
#include <string>
using namespace std;

// Student class
class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Constructor to initialize student details
    Student(string n, int roll, float m) {
        name = n;
        rollNumber = roll;
        marks = m;
        cout << "Student object created for: " << name << endl;
    }

    // Destructor to display message when object is destroyed
    ~Student() {
        cout << "Object Destroyed for: " << name << endl;
    }

    // Member function to display student details
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    string name; int roll; float marks;

    Student student1("John", 101, 85.5);
    Student student2("Alice", 102, 90.0);
    Student student3("Bob", 103, 78.0);

    cout << "\nDetails of Student 1: " << endl;
    student1.displayDetails();

    cout << "\nDetails of Student 2: " << endl;
    student2.displayDetails();

    cout << "\nDetails of Student 3: " << endl;
    student3.displayDetails();

    return 0;
}
