#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *prev;
    Node *next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {};
  };

class LinkedList {
  public:
    Node *head;
    Node *tail;

    LinkedList() : head(nullptr) {};

    // INSERT (AT END), INSERT AT INDEX, DELETE (FROM END), DELETE FROM INDEX, DISPLAY, SWAP INDEX, SWAP NUMBERS

    void insert(int num) {
      Node *newNode = new Node(num);

      if (head == NULL) {
        head = newNode;
        tail = newNode;
      } else {
        tail->next = newNode;
        newNode->prev = tail;

        tail = tail->next;
        newNode->next = NULL;
      }
    }

    void insertAt(int index, int num) {
      int count = 0;

      Node *temp1 = head;
      while (temp1 != NULL && count < index - 1) {
        temp1 = temp1->next;
        count++;
      }

      Node *newNode = new Node(num);
      newNode->prev = temp1;
      newNode->next = temp1->next;
      temp1->next = newNode;
      temp1 = temp1->next->next;
      temp1->prev = newNode;
    }

    void deleteFromEnd() {
      Node *temp = tail;
      tail = tail->prev;
      delete temp;
      tail->next = NULL;
    }

    void deleteFromIndex(int index) {
      int count = 0;
    }

    void swapIndex(int ind1, int ind2) {}

    void swapNumbers(int num1, int num2) {}

    void display() {
      for (Node *temp = head; temp != NULL; temp = temp->next) {
        cout << temp->data << " ";
      }
      cout << endl;
    }

};

int main() {
  LinkedList ll;
  ll.insert(4);
  ll.insert(57);
  ll.insert(29);
  ll.insert(2);
  ll.insert(99);
  ll.insert(62);
  ll.display();
  cout << endl;

  // ll.swapIndex(2, 4);
  // ll.display();

  // ll.swapIndex(4, 2);
  // ll.display();
  // cout << endl;

  // ll.swapNumbers(57, 2);
  // ll.display();

  // ll.swapNumbers(2, 57);
  // ll.display();
  // cout << endl;

  ll.insertAt(2, 100);
  ll.display();

  ll.deleteFromEnd();
  ll.display();
}
