#include <iostream>
#include <string>
using namespace std;

class Student {
  /* ??? */
  public:
    string name;
    int sub1;
    int sub2;
    int sub3;

    int totalScore() {
      return (sub1 + sub2 + sub3);
    }

    void display() {
      cout << "Name: " << name << "\nMarks: \n\tSubject 1: " << sub1 << "\n\tSubject 2: " << sub2 << "\n\tSubject 3: " << sub3 << endl;
    }
};

class Node {
  public:
    Student data;
    Node* next;

    Node(const Student& student) : data(student), next(nullptr) {}

    void display() {
      cout << "Student data: \n";
      data.display();
    }
};

class LinkedList {
  private:
    Node* head;
    Node* aboveAverageHead;
    Node* belowAverageHead;
    bool isSplit;

  public:
    LinkedList () : head(nullptr), aboveAverageHead(nullptr), belowAverageHead(nullptr), isSplit(false) {}

    void addStudent(const Student& student) { // at the end
      if (isSplit) {
        cout << "List has already been split." << endl;
        return;
      }

      /* ??? */

      Node* newNode = new Node(student);
      if (head == NULL) {
        head = newNode;
      } else {
        // traversing list
        Node* temp = head;
        while (temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = newNode;
      }
    }

    int calculateAverage () {
      /* ??? */
      if (head == NULL) {
        return 0;
      }

      int sum = 0;
      int count = 0;

      for (Node *temp = head; temp != NULL; temp = temp->next) {
        sum += temp->data.totalScore();
        count++;
      }

      return (count == 0) ? 0 : (sum / count);
    }

    void split() {
      if (isSplit) {
        cout << "List has already been split." << endl;
        return;
      }

      double average = calculateAverage();

      /* ??? */ ???????????????????????????????????????????????????????????????????????????????????????????????

      for (Node *temp = head; temp != NULL; temp = temp->next) {
        if (temp->data.totalScore() > average) {
          aboveAverageHead->data = temp->data;
          aboveAverageHead = aboveAverageHead->next;
        } else {
          belowAverageHead->data = temp->data;
          belowAverageHead = belowAverageHead->next;
        }
      }

      isSplit = true;
    }

    void display() const {
      if (!isSplit) {
        /* ??? */
      } else {
        cout << "\nBelow average:" << endl;
        Node* temp = aboveAverageHead;
        while (temp) {
          temp->data.display();
          temp = temp->next;
        }

        cout << "\nAbove average:" << endl;
        temp = belowAverageHead;
        while (temp) {
          temp->data.display();
          temp = temp->next;
        }
      }
    }
};

int main() {
  LinkedList students;
  students.addStudent(Student("Alice", 85, 90, 78));
  students.addStudent(Student("Bob", 70, 65, 80));
  students.addStudent(Student("Charlie", 88, 92, 95));
  students.addStudent(Student("Diana", 60, 75, 70));

  cout << "All students:" << endl;
  students.display();

  students.split();
  students.display();

  return 0;
}
