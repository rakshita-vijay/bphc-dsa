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
        head->prev = newNode;
        tail->next = newNode;
        tail = tail->next;
      } else {
        /* ??? */
        newNode->prev = head;
        newNode->next = tail;
        head->next = newNode;
        tail->prev = newNode;
        tail = tail->prev;
      }
    }

    void popElement() {
      if (size == 0) {
        throw runtime_error("Cannot pop from an empty array");
      }

      size--;
      int x;

      reverse();
      if (!isReverse) { //(isReverse == 0)
        /* ??? */
        Node *curr = tail;
        x = tail->data;
        tail = tail->prev;

        tail->next = head;
        head->prev = tail;

        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
      } else {
        /* ??? */
        Node *curr = head; // haven't switched head and tail pointers on purpose
        x = head->data;
        head = head->next;

        head->prev = tail;
        tail->next = head;

        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
      }
      // return x;
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
      Node *temp = head;
      if (!isReverse) {
        for(int i = 0; i < size; i++) {
          cout << temp->data << " ";
          temp = temp->next;
        }
        cout << endl;
      } else {
        temp = tail;
        for(int i = 0; i < size; i++) {
          cout << temp->data << " ";
          temp = temp->prev;
        }
        cout << endl;
      }
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
  ma.addElement(4);
  ma.addElement(5);

  cout << "1) Displaying the magic array before reversing: " << endl;
  ma.display();
  cout << "~~~" << endl << endl;

  ma.reverse();
  cout << "2) Displaying the magic array after reversing: " << endl;
  ma.display();
  cout << "~~~" << endl << endl;

  ma.popElement();
  cout << "3) Displaying the magic array after popping 1 element: " << endl;
  ma.display();
  cout << "~~~" << endl << endl;

  ma.addElement(12);
  ma.addElement(13);

  cout << "4) Displaying the magic array after adding 2 more elements: " << endl;
  ma.display();
  cout << "~~~" << endl << endl;
  // ma.display();

  ma.rotate(2);
  cout << "5) Displaying the magic array after rotating: " << endl;
  ma.display();
  cout << "~~~" << endl << endl;

  ma.reverse();
  cout << "6) Displaying the magic array after reversing: " << endl;
  ma.display();
  cout << "~~~" << endl;
  // ma.display();

  return 0;
}
