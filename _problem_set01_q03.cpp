#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const size_t MAX_LABS = 10;

class Lab {
  protected:
    string name;
    bool isOccupied;

  public:
    Lab() : name(""), isOccupied(false) {}
    Lab(const string& name, bool occupied) : name(name), isOccupied(occupied) {}

    void freeLab() { isOccupied = false; }

    void occupyLab() { isOccupied = true; }

    bool getOccupiedStatus() const { return isOccupied; }

    virtual void displayInfo() const = 0;

    virtual ~Lab() {}
};

class SWLab : public Lab {
  private:
    int numComputers;

  public:
    SWLab() : Lab(), numComputers(30) {}
    SWLab(const string& name, bool occupied) : Lab(name, occupied), numComputers(30) {}

    void displayInfo() const {
      cout << "Software Lab - Name: " << name << ", Computers: " << numComputers << ", Occupied: " << (isOccupied ? "Yes" : "No") << endl;
    }
};

class HWLab : public Lab {
  private:
    int numDevices;

  public:
    HWLab() : Lab(), numDevices(40) {}
    HWLab(const string& name, bool occupied) : Lab(name, occupied), numDevices(40) {}

    void displayInfo() const {
      cout << "Hardware Lab - Name: " << name << ", Devices: " << numDevices << ", Occupied: " << (isOccupied ? "Yes" : "No") << endl;
    }
};

class HybridLab : public Lab {
  private:
    int numComputers;
    int numDevices;

  public:
    HybridLab() : Lab(), numComputers(10), numDevices(20) {}
    HybridLab(const string& name, bool occupied) : Lab(name, occupied), numComputers(10), numDevices(20) {}

    void displayInfo() const {
      cout << "Hybrid Lab - Name: " << name << ", Computers: " << numComputers << ", Devices: " << numDevices << ", Occupied: " << (isOccupied ? "Yes" : "No") << endl;
    }
};

template <typename T>
class LabList {
  private:
    T labs[MAX_LABS];
    size_t count;

  public:
    LabList() : count(MAX_LABS) {}

    void setup(const string& labType) {
      for (size_t i = 0; i < MAX_LABS; ++i) {
        labs[i] = T(labType + "-Lab-" + to_string(i + 1), false);
      }
    }

    void freeLab(size_t index) {
      if (index < MAX_LABS) {
        labs[index].freeLab();
        cout << "Lab " << index + 1 << " freed successfully.\n";
      } else {
        cout << "Invalid lab index.\n";
      }
    }

    size_t getFreeLabCount() const {
      // ???

      size_t count = 0;
      for (size_t i = 0; i < MAX_LABS; ++i) {
        if (!labs[i].getOccupiedStatus()) {
          count++;
        }
      }
      return count;
    }

    T* occupyFreeLab() {
      for (size_t i = 0; i < MAX_LABS; ++i) {
        if (!labs[i].getOccupiedStatus()) {
          labs[i].occupyLab();
          return &labs[i];
        }
      }
      return nullptr;
    }

    void displayAll() const {
      for (size_t i = 0; i < MAX_LABS; ++i) {
        labs[i].displayInfo();
      }
    }
};

int main() {
  LabList<SWLab> swLabs;
  swLabs.setup("Software");
  LabList<HWLab> hwLabs;
  hwLabs.setup("Hardware");
  LabList<HybridLab> hybridLabs;
  hybridLabs.setup("Hybrid");

  while (true) {
    int x;
    cout << "Enter a value of x (1 or 2): " << endl;
    cin >> x;
    if (x == 1) {
      char c;
      cout << "Enter a value of c (S / H / X): " << endl;
      cin >> c;

      int y;
      cout << "Enter a value of y: " << endl;
      cin >> y;
      if (c == 'S' || c == 's') swLabs.freeLab(y - 1);
      if (c == 'H' || c == 'h') hwLabs.freeLab(y - 1);
      if (c == 'X' || c == 'x') hybridLabs.freeLab(y - 1);
    }

    else if (x == 2) {
      char c;
      cout << "Enter a value of c (S / H): " << endl;
      cin >> c;
      Lab* occupiedLab = nullptr;

      if (c == 'S' || c == 's') {
        occupiedLab = swLabs.occupyFreeLab();
      }
      else if (c == 'H' || c == 'h') {
        occupiedLab = hwLabs.occupyFreeLab();

        if (!occupiedLab) {
          occupiedLab = hybridLabs.occupyFreeLab();
        }
      }

      if (occupiedLab) {
        cout << "Lab occupied successfully: \n";
        occupiedLab->displayInfo();
      } else {
        cout << "No available labs of the requested type. \n";
      }
    }
  }

  return 0;
}
