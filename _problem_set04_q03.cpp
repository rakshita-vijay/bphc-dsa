#include <iostream>
using namespace std;

struct Node {
  char data;
  Node* next;
  Node* prev;
  Node(char val) : data(val), next(nullptr), prev(nullptr) {}
};

class Deque {
  private:
    Node* front;
    Node* rear;
  public:
    Deque() : front(nullptr), rear(nullptr) {}
    ~Deque() {
      while (!isEmpty()) {
        popFront();
      }
    }
    void pushFront(char x) {
      /* ??? */
      Node * newNode = new Node(x);
      if (isEmpty()) {
        front = rear = newNode;
      } else {
        front->prev = newNode;
        newNode->next = front;
        front = newNode;
      }
    }
    void pushBack(char x) {
      Node* newNode = new Node(x);
      if (isEmpty()) {
        front = rear = newNode;
      }
      else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
      }
    }
    char popFront() {
      /* ??? */
      if (isEmpty()) return '\0';
      Node *temp = front;
      char dat = temp->data;

      if (front->next != nullptr) {
        front = front->next;
        front->prev = nullptr;
      } else {
        front = rear = nullptr;
      }
      delete temp;
      return dat;
    }
    char popBack() {
      /* ??? */
      if (isEmpty()) return '\0';
      Node *temp = rear;
      char dat = temp->data;

      if (rear->prev != nullptr) {
        rear = rear->prev;
        rear->next = nullptr;
      } else {
        front = rear = nullptr;
      }
      delete temp;
      return dat;
    }
    bool isEmpty() {
      return front == nullptr;
    }
};

bool isPalindrome(string s) {
  /* ??? */
  int left = 0;
  int right = s.size() - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

bool canFormPalindrome(Deque& dq, string s = "") {
  /* ??? */
  if (dq.isEmpty()) {
    return isPalindrome(s);
  }

  char frontChar = dq.popFront();
  if (canFormPalindrome(dq, s + frontChar)) return true;
  dq.pushFront(frontChar); // Restore state

  char backChar = dq.popBack();
  if (canFormPalindrome(dq, s + backChar)) return true;
  dq.pushBack(backChar); // Restore state

  return false;
}

int main() {
  Deque dq;
  string input = "rearcca";
  for (int index = 0; index < input.size(); index++) {
    dq.pushBack(input[index]);
  }
  cout << (canFormPalindrome(dq, input) ? "YES" : "NO") << endl;
  return 0;
}
