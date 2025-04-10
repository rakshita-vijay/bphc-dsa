#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

class Stack {
  private:
    Node* top;
  public:
    Stack() { top = nullptr; }
    ~Stack() { while (!isEmpty()) pop(); }
    void push(int x) {
      Node* newNode = new Node(x);
      newNode->next = top;
      top = newNode;
    }
    int pop() {
      if (top == nullptr) return -1;
      int val = top->data;
      Node* temp = top;
      top = top->next;
      delete temp;
      return val;
    }
    int peek() { return top ? top->data : -1; }
    bool isEmpty() { return top == nullptr; }
};

int maxRectangle(int grid[][5], int rows, int cols) {
  /* ??? */
  for (int row_count = 0; row_count < rows; row_count++) {
    for (int col_count = 0; col_count < cols; col_count++) {
    }
  }
}

int main() {
  int grid[4][5] = {
    {1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {1, 1, 0, 1, 1}
  };
  cout << maxRectangle(grid, 4, 5) << endl;
  return 0;
}
