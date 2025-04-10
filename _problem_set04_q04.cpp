#include <iostream>
using namespace std;

class Patient {
  public:
    string name;
    int timeRequired;
    Patient* next;
    Patient(string n, int t) : name(n), timeRequired(t), next(nullptr) {}
};

class Queue {
  public:
    Patient* front, *rear;
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(string name, int time) {
      /* ??? */
      Patient *newPatient = new Patient(name, time);
      if (front == nullptr && rear == nullptr) {
        front = newPatient;
        rear = newPatient;
      } else {
        rear->next = newPatient;
        rear = newPatient;
      }
    }
    Patient* dequeue() {
      /* ??? */
      if (isEmpty()) return nullptr;
      Patient *outPatient = front;

      if (front->next != nullptr) {
        front = front->next;
      } else {
        front = rear = nullptr;
      }
      outPatient->next = nullptr;
      return outPatient;
    }
    Patient* peek() { return front; }
    bool isEmpty() { return !front; }
};

class Hospital {
    int numWards;
    Queue critical, serious, stable;
    Patient** wards;
  public:
    Hospital(int n) : numWards(n) { wards = new Patient*[numWards](); }
    ~Hospital() { delete[] wards; }
    void admitPatient(int type, string name, int time) {
      /* ??? */
      if (type == 1) {
        critical.enqueue(name, time);
      } else if (type == 2) {
        serious.enqueue(name, time);
      } else if (type == 3) {
        stable.enqueue(name, time);
      } else {
        cout << "invalid number, retry" << endl;
      }
    }
    void process() {
      /* ??? */
      for (int ind = 0; ind < numWards; ind++) {
        if (wards[ind] != nullptr) {
          wards[ind]->timeRequired--;
          if(wards[ind]->timeRequired == 0) {
            delete wards[ind];
            wards[ind] = nullptr;
          }
        }

        if (wards[ind] == nullptr) {
          if (critical.isEmpty() == false) {
            wards[ind] = critical.dequeue();
          } else if (serious.isEmpty() == false) {
            wards[ind] = serious.dequeue();
          } else {
            wards[ind] = stable.dequeue();
          }
        }
      }
    }
    void display() {
      /* ??? */
      cout << "Wards: " << endl;
      for (int i = 0; i < numWards; i++) {
        cout << i+1 << ": ";
        if (wards[i] == nullptr) {
          cout << "empty" << endl;
        } else {
          cout << wards[i]->name << endl;
        }
      }
    }
};

int main() {
  Hospital hospital(5);
  int cmd, type, time;
  string name;
  while (true) {
    cout << "Enter cmd (true/false): ";
    cin >> cmd;
    if (cmd) {
      cout << "Enter type(1:critical, 2:serious, 3:stable): ";
      cin >> type;
      cout << "Enter name: ";
      cin >> name;
      cout << "Enter time: ";
      cin >> time;
      cout << endl;
      hospital.admitPatient(type, name, time);
    } else {
      break;
    }
    hospital.process();
    hospital.display();
  }
  return 0;
}
