#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Flight;

class City {
  private:
    // ???

    string code;
    string name;
    double x;
    double y;

  public:
    City(string c, string n, double xCoord, double yCoord) : code(c), name(n), x(xCoord), y(yCoord) {}

    friend class Flight;
};

class Flight {
  private:
    double speed;
    vector<City> cities;

    double rate;
    double earnings;

  public:
    // Flight(double s) : speed(s) {}
    Flight(double s, double r) : speed(s), rate(r), earnings(0) {}


    void addCity(const City& city) {
      cities.push_back(city);
    }

    City* getCityByCode(const string& code) {
      for (auto& city : cities) {
        if (city.code == code) {
          return &city;
        }
      }
      return nullptr;
    }

    void booking(const string& code1, const string& code2) {
      City* city1 = getCityByCode(code1);
      City* city2 = getCityByCode(code2);

      // ???
      double distance = sqrt(pow((city2->x - city1->x), 2) + pow((city2->y - city1->y), 2));  // Replacing ???
      double flightTime = distance / speed;

      double price = distance * rate;
      earnings += price;

      cout << "Flight time from " << city1->name << " to " << city2->name << ": " << flightTime << " hours" << endl;
      cout << "Distance: " << distance << " units " << endl;
      cout << "Ticket price: $" << price << " \n" << endl;
    }

    void displayEarnings() const {
      cout << "Total earnings: $" << earnings << endl;
    }
};

int main() {
  City city1("NY", "New York", 40.7128, -74.0060);
  City city2("LA", "Los Angeles", 34.0522, -118.2437);
  City city3("SF", "San Francisco", 37.7749, -122.4194);

  // Flight flight(7.5);
  Flight flight(500, 0.1);  // Speed = 500 units/hour, Rate = $0.1 per unit distance

  flight.addCity(city1);
  flight.addCity(city2);
  flight.addCity(city3);

  flight.booking("NY", "LA");
  flight.booking("LA", "SF");
  flight.booking("NY", "SF");

  flight.displayEarnings();

  return 0;
}
