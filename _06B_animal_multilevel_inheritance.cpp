#include <iostream>
#include <string>
using namespace std;

class Animal {
  string name = " ";

  public:
    int tail = 1;
};

class Dog : public Animal {
  public:
    void voiceAction() {
      cout << "Barks!";
    }
};

class Puppy : public Dog {
  public:
    void weeping() {
      cout << "Sheds tears!";
    }
};

int main() {
  Puppy p;
  cout << "Puppy has " << p.tail << " tail" << endl;
  cout << "Puppy ";
  p.voiceAction();
  cout << " Puppy ";
  p.weeping();
  cout << endl;
}

/*
O/P:
Puppy has 1 tail
Puppy Barks! Puppy Sheds tears!
*/
