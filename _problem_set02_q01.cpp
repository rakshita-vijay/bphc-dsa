#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
  private:
    Node* head , *tail;
    int inversions;

  public:
    LinkedList () : head(nullptr), tail(nullptr), inversions(0) {}

    ~LinkedList () {
      Node* current = head;
      while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
      }
    }

    void add(int value) {
      Node* newNode = new Node(value);

      for (Node *temp = head; temp != NULL; temp = temp->next) {
        if (temp->data > value) {
          inversions++;
        }
      }

      if (!head) {
        head = newNode;
        tail = newNode;
      } else {
        tail->next = newNode;
        tail = newNode;
      }
    }

    // int countInversions () const {
    //   int inversions = 0;

    //   /* ??? */

    //   for (Node *current = head; current != NULL; current = current->next) {
    //     for (Node* nextNode = current->next; nextNode != NULL; nextNode = nextNode->next) {
    //       if (current->data > nextNode->data) {
    //         inversions++;
    //       }
    //     }
    //   }

    //   return inversions;
    // }

    int countInversions() const {
      return inversions; 
    }

    void display () const {
      Node* temp = head;
      while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
};

int main() {
  LinkedList list;

  list.add(5);
  list.add(3);
  list.add(2);
  list.add(1);

  cout << "Linked List: ";
  list.display();

  cout << "Number of inversions: " << list.countInversions() << endl;

  return 0;
}
