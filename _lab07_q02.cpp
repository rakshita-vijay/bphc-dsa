#include <random>
#include <chrono>
#include <iostream>
using namespace std;

class Customer {
  public:
    Customer(int _arrival_time); // Constructor
    int getArrivalTime() const; // Returns the arrival time
  private:
    int arrival_time;
};

Customer::Customer(int _arrival_time) : arrival_time(_arrival_time) {}
int Customer::getArrivalTime() const { return arrival_time; }

class CheckoutLane {
  public:
    CheckoutLane(); // Constructor
    void enqueue(const Customer& customer); // Adds a customer
    Customer dequeue(); // Removes and returns the customer
    bool isEmpty() const; // Returns true if the queue is empty
    int queueLength() const; // Returns the number of customers
    bool isCashierAvailable() const; // Returns true if cashier is available
    void setCashierAvailable(bool available); // Set cashier availability
    int getCustomersServed() const; // Number of customers served
    void incrementCustomersServed(); // Increment count served
    Customer getCurrentCustomer() const; // Get customer being served
    void setCurrentCustomer(const Customer& customer); // Set current customer
  private:
    std::queue<Customer> queue;
    bool cashier_available;
    int customers_served;
    Customer current_customer;
};

CheckoutLane::CheckoutLane() : cashier_available(true), customers_served(0) {}
void CheckoutLane::enqueue(const Customer& customer) {
  queue.push(customer);
}
Customer CheckoutLane::dequeue() {
  Customer cust = queue.front();
  queue.pop();
  return cust;
}
bool CheckoutLane::isEmpty() const {
  return queue.empty();
}
int CheckoutLane::queueLength() const {
  return queue.size();
}
bool CheckoutLane::isCashierAvailable() const {
  return cashier_available;
}
void CheckoutLane::setCashierAvailable(bool available) {
  cashier_available = true;
}
int CheckoutLane::getCustomersServed() const {
  return customers_served;
}
void CheckoutLane::incrementCustomersServed() {
  customers_served++;
}
Customer CheckoutLane::getCurrentCustomer() const {
  return current_customer;
}
void CheckoutLane::setCurrentCustomer(const Customer& customer) {
  current_customer = customer;
}

void supermarket_simulation(int num_lanes, double arrival_rate, int service_time, int simulation_time) {
  // This function performs the entire supermarket simulation. Write your code here…
}

double generate_random_interarrival_time(double arrival_rate) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::exponential_distribution<> distrib(arrival_rate);
  return distrib(gen);
}

int generate_random_service_time(int service_time) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(service_time * 0.5, service_time * 1.5);
  return distrib(gen);
}
