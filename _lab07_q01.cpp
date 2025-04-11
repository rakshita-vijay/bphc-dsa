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
        else front = nullptr;
        delete temp;
        return val;
    }
    bool isEmpty() { return front == nullptr; }
};

bool isPalindrome(string s) {
  /* ??? */
  // int slen = s.length();
  // for (int ind = 0; ind <= slen / 2; ind++) {
  //   cout << s[ind] << ", " << s[slen - 1 - ind] << endl;
  //   if (s[ind] != s[slen - 1 - ind]) {
  //     return false;
  //   }
  // }
  // return true;

  int l = 0;
  int r = s.length() - 1;
  while (r > l) {
    if (s[l] == s[r]) {
      l++;
      r--;
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
    return true;
  }
  dq.pushFront(frontChar);

  char backChar = dq.popBack();
  if (canFormPalindrome(dq, s+backChar)) {
    return true;
  }
  dq.pushBack(backChar);
  return false;
}

int main() {
    Deque dq;
    string input = "madama";
    // for (char c : input) dq.pushBack(c);
    for (int i = 0; i < input.length(); i++) {
      dq.pushBack(input[i]);
    }
    cout << (canFormPalindrome(dq) ? "YES" : "NO") << endl;
    return 0;
}
