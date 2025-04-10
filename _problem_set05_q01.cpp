#include <iostream>
using namespace std;

class Node {
  public:
    string s;
    Node *prev, *next;

    Node(string _s) : s(_s), prev(nullptr), next(nullptr) {}

    bool isGreaterThan(Node* other) {
      string r = other->s;
      for (int i = 0; i < min(s.length(), r.length()); i++) {
        if (s[i] > r[i]) return true;
        else if (s[i] < r[i]) return false;
      }
      return s.length() > r.length();
    }
};

class LinkedList {
  private:
    Node *head, *tail;
    int size;

  public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void append(string s) {
      /* ??? */
      Node *newNode = new Node(s);
      if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
      }
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      size++;
      return;
    }

    void display() {
      Node* node = head;
      for (int i = 0; i <= size; i++) {
        cout << node->s << (i == (size) ? '\n' : ' ');
        node = node->next;
      }
    }

    void sort() {
      /* ??? */
      for (Node *outerTemp = head; outerTemp != nullptr; outerTemp = outerTemp->next) {
        for (Node *temp = head; temp != nullptr; temp = temp->next) {
          if (temp->next == nullptr) {
            continue;
          }
          if (temp->isGreaterThan(temp->next)) {
            swap(temp->s, temp->next->s);
            temp = temp->next;
          }
        }
      }
    }
};

int main() {
  int n;
  cout << "Enter value of n: ";
  cin >> n;
  LinkedList* list = new LinkedList();
  for (int i = 0; i < n; i++) {
    string s;
    cout << "Enter string for index " << i << ": ";
    cin >> s;
    list->append(s);
  }
  cout << endl;
  cout << "Before sorting: ";
  list->display();
  list->sort();
  cout << "After sorting: ";
  list->display();
  return 0;
}
