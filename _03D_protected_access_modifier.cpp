// incomplete code, don't try to run it

class Student {
  protected:
    string name;
    int rollNumber;

  public:
    Student (string n, int roll) {
      name = n;
      rollNumber = roll;
    }

    void displayBasicDetails () {
      cout << "Name: " << name << endl;
      cout << "Roll number: " << rollNumber << endl;
    }
};

// what type of constructor is used here? : parameterized
// are there any return types for constructors? : no

class Result : public Student {
  private:
    float marks;

  public:
    Result (string n, int roll, float m) : Student(n, roll) {
      marks = m;
    }

    void displayCompleteDetails() {
      cout << "Name: " << name << endl;
      cout << "Roll number: " << rollNumber << endl;
      cout << "Marks: " << marks << endl;
    }
};
