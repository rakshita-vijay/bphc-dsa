#include <iostream>
using namespace std;

class Node {
public:
  string data;
  Node* next;
  Node(string val) : data(val), next(nullptr) {}
};

class Queue {
  private:
    Node* front;
    Node* rear;
  public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(string val) {
      Node* newNode = new Node(val);
      if (isEmpty()) {
        front = rear = newNode;
      }
      else {
        rear->next = newNode;
        rear = newNode;
      }
    }

    string dequeue() {
      /* ??? */
      if (isEmpty()) {
        return "";
      } else {
        Node *outNode = front;
        front = front->next;
        outNode->next = nullptr;
        string val = outNode->data;
        delete outNode;
        return val;
      }
    }

    bool isEmpty() { return front == nullptr; }
};

void generateBinaryNumbers(int n) {
  /* ??? */
  Queue *q = new Queue();
  string binNumRev = ""; // initial
  string binNum = ""; // final

  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      q->enqueue("0000");
      continue;
    }

    int temp = i;
    while (temp != 0) {
      binNumRev += to_string(temp % 2);
      temp = floor(temp/2);
    }

    for (int j = binNumRev.length() - 1; j >= 0; j--) {
      binNum += binNumRev[j];
    }

    int binNumLength = binNum.length();
    int rem = (4 - (binNumLength % 4))%4;
    // if (rem % 4 == 0) {
    //   rem = 0;
    // }
    string finalBinNum = "";
    for (int index = 0; index < rem; index++) {
      finalBinNum += "0";
    }
    finalBinNum += binNum;

    q->enqueue(finalBinNum);
    binNumRev = "";
    binNum = "";
  }

  while(q->isEmpty() == false) {
    cout << q->dequeue() << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  generateBinaryNumbers(n);
  return 0;
}
