#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class MagicArray {
  private:
    int size;
    Node* head;
    Node* tail;
    bool isReverse;

  public:
    MagicArray() : size(0), head(nullptr), tail(nullptr), isReverse(false) {}

    void addElement(int x) {
      Node* newNode = new Node(x);
      size++;

      if (!head) { // (head == NULL)
        head = newNode;
        tail = newNode;
        head->next = head;
        head->prev = head;
      } else if (!isReverse) {
        /* ??? */
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
      } else {
        /* ??? */
        newNode->next = tail;
        newNode->prev = head;
        tail->prev = newNode;
        head->next = newNode;
      }
    }

    int popElement() {
      if (size == 0) {
        throw runtime_error("Cannot pop from an empty array");
      }

      size--;
      int x;

      if (!isReverse) {
        /* ??? */
        Node *curr = tail;
        tail = tail->prev;
        tail->next = NULL;
      } else {
        /* ??? */
      }
      return x;
    }

    void rotate(int k) {
      if (size == 0) return;

      k %= size;
      if (k < 0) k += size;

      for (int i = 0; i < k; i++) {
        if (!isReverse) {
          head = head->next;
          tail = tail->next;
        } else {
          head = head->prev;
          tail = tail->prev;
        }
      }
    }

    void display() const {
      if (size == 0) {
        cout << "Magic Array is empty!\n";
        return;
      }

      /* ??? */
    }

    void reverse() {
      isReverse = !isReverse;
    }
};

int main() {
  MagicArray ma;
  ma.addElement(1);
  ma.addElement(2);
  ma.addElement(3);
  ma.display();

  ma.reverse();
  ma.popElement();
  ma.addElement(4);
  ma.addElement(5);
  ma.display();

  ma.rotate(2);
  ma.reverse();
  ma.display();

  return 0;
}
