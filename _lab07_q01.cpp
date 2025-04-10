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
        while (!isEmpty()) popFront();
    }
    void pushFront(char x) {
        /* ??? */
        Node *newNode = new Node(x);
        if (isEmpty()) {
          front = newNode;
          rear = newNode;
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
        if (isEmpty()) return '\0';
        char val = front->data;
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
        return val;
    }
    char popBack() {
        /* ??? */
        if (isEmpty()) return '\0';
        char val = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else rear = nullptr;
        delete temp;
        return val;
    }
    bool isEmpty() { return front == nullptr; }
};

bool isPalindrome(string s) {
  /* ??? */
  for (int ind = 0; ind < s.length() / 2; ind++) {
    if (s[ind] == s[s.length() - 1 - ind]) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

bool canFormPalindrome(Deque& dq, string s = "") {
  /* ??? */
  if (dq.isEmpty()) {
    return isPalindrome(s);
  }

  char frontChar = dq.popFront();
  if (canFormPalindrome(dq, s+frontChar)) {
    dq.pushFront(frontChar);
    return true;
  }

  char backChar = dq.popBack();
  if (canFormPalindrome(dq, s+backChar)) {
    dq.pushBack(backChar);
    return true;
  }
  return false;
}

int main() {
    Deque dq;
    string input = "rearcca";
    // for (char c : input) dq.pushBack(c);
    for (int i = 0; i < input.length(); i++) {
      dq.pushBack(input[i]);
    }
    cout << (canFormPalindrome(dq) ? "YES" : "NO") << endl;
    return 0;
}
