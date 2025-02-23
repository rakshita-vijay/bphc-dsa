#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class SortedArray {
  private:
    Node* head;
    Node* tail;

  public:
    SortedArray() : head(nullptr), tail(nullptr) {}

    void insert(int value) {
      /* ??? */
      Node *newNode = new Node(value);
      if (!head) {
        head = newNode;
        tail = newNode;
        return;
      }
      else if (newNode->data < head->data) {
        newNode->prev = NULL;
        newNode->next = head;

        head->prev = newNode;
        head = head->prev;
        return;
      } else if (tail->data < newNode->data) {
        newNode->prev = tail;
        newNode->next = NULL;

        tail->next = newNode;
        tail = tail->next;
        return;
      }

      Node* temp = head;
      while (temp->next != NULL && temp->next->data < newNode->data) {
        temp = temp->next;
      }

      newNode->next = temp->next;
      newNode->prev = temp;
      temp->next = newNode;
      temp = newNode->next;
      temp->prev = newNode;
    }

    void display() const {
      if (!head) {
        cout << "Sorted Array is empty!\n";
        return;
      }

      char ans;
      cout << "Do you want your array to be printed in ascending or descending order?" << "\n" << "Enter a for ascending and d for descending: ";
      cin >> ans;
      cout << endl;

      Node* temp = head;

      if(ans == 'a' || ans == 'A') {
        while (temp) {
          cout << temp->data << ' ';
          temp = temp->next;
        }
      } else if(ans == 'd' || ans == 'D') {
        temp = tail;
        while (temp) {
          cout << temp->data << ' ';
          temp = temp->prev;
        }
      } else {
        cout << "Invalid input, re-run code :(";
      }
      cout << endl;
    }

    ~SortedArray() {
      Node* temp = head;
      while (temp) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
      }
    }
};

int main() {
  SortedArray sa;
  sa.insert(5);
  sa.insert(3);
  sa.insert(8);
  sa.insert(1);
  sa.insert(7);
  sa.display();
  return 0;
}
