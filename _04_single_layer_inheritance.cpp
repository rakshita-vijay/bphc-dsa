#include <iostream>
using namespace std;

class BitsPilani {
  private:
    string Museum;

  public:
    int YearEst;

    BitsPilani() {
      Museum = "BirlaMuseum";
      YearEst = 0;
      FootballGround = "Nil";
    }

  protected:
    string FootballGround;
};

class BitsHyd : public BitsPilani {
  public:
    void DisplayGround() {
      FootballGround = "Grass";
      cout << "Football Ground is made up of: " << FootballGround << endl;
    }

    void DisplayEst() {
      cout << "BITS Pilani was established in: " << YearEst << endl;
    }
};

int main() {
  BitsHyd obj;
  obj.YearEst = 1964;
  obj.DisplayGround();
  obj.DisplayEst();
  return 0;
}

/*
O/P:
Football Ground is made up of: Grass
BITS Pilani was established in: 1964
*/
