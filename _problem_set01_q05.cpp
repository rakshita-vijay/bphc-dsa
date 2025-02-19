#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class PRNG {
  private:
    int a, c, m;
    int x;

  public:
    PRNG(int _a, int _c, int _m, int seed = 0) : a(_a), c(_c), m(_m), x(seed) {}

    int next() {
      // x = ???;
      x = (a * x + c) % m;
      return x;
    }
};

class Virus {
  protected:
    string data;
    PRNG prng;

  public:
    Virus(const string& _data, const PRNG& _prng) : data(_data), prng(_prng) {}

    virtual void corrupt() = 0;

    void display() const {
      // ???
      cout << "Corrupted Data: " << data << endl;
    }
};

class SwapVirus : public Virus {
  public:
    SwapVirus(const string& _data, const PRNG& _prng) : Virus(_data, _prng) {}

    void corrupt() override {
      int index1 = prng.next() % data.length();
      int index2 = prng.next() % data.length();
      // ???
      swap(data[index1], data[index2]); 
    }
};

int main() {
  int a = 1664525, c = 1013904223, m = 1024;
  PRNG prng(a, c, m, static_cast<int>(time(0)));

  string virusData = "Hello World!";
  SwapVirus swapVirus(virusData, prng);
  swapVirus.display();

  for (int i = 0; i < 10; i++) {
    swapVirus.corrupt();
    swapVirus.display();
  }

  return 0;
}
