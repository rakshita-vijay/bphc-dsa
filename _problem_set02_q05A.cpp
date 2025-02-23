#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class JosephusCircle {
  private:
    Node* head;
    int size;

  public:
    JosephusCircle() : head(nullptr), size(0) {}

    void initialize(int n) {
      size = n;
      head = new Node(1);
      Node* prev = head;

      for (int i = 2; i <= n; i++) {
        Node* newNode = new Node(i);
        prev->next = newNode;
        prev = newNode;
      }

      prev->next = head;
    }

    int solve(int k) {
      /* ??? */
      Node *temp = head;

      while(size > 1) {
        for(int i = 1; i < k; i++) {
          temp = temp->next;
        }
        Node *curr = temp->next;
        if (curr == head) {
          head = curr->next;
        }
        temp->next = curr->next;
        cout << "data popped: " << curr->data << endl;
        delete curr;

        size--;
        temp = temp->next;
      }

      return temp->data;
    }
};

int main() {
  JosephusCircle circle;
  circle.initialize(7);
  int lastPerson = circle.solve(3);
  cout << "The last person standing is: " << lastPerson << endl;
  return 0;
}
