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

    ~Stack() {
      while (!isEmpty()) {
        pop();
      }
    }

    void push(int x) {
      Node* newNode = new Node(x);
      newNode->next = top;
      top = newNode;
    }

    int pop() {
      /* ??? */
      if (top == nullptr) {
        return -1;
      } else {
        int top_data = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return top_data;
      }
    }
    int peek() {
      if (top == nullptr) return -1;
      return top->data;
    }
    bool isEmpty() { return top == nullptr; }
};

bool ropesIntersect(int twins[], int n) {
  Stack stack;
  /* ??? */
  if (n == 1) { return false; }

  int twins_size = n * 2;
  int ind = 0;

  int last_elem = twins[twins_size-1];
  int last_second_elem = twins[twins_size-2];
  int last_third_elem = twins[twins_size-3];

  if (last_elem != last_second_elem && last_second_elem != last_third_elem) {
    for (; ind < n; ind++) {
      stack.push(twins[ind]);
    }
    // for (ind = 0; ind < n; ind++) {
    //   cout << stack.pop() << " ";
    // }
    // cout << endl;
    // for (ind = 0; ind < n; ind++) {
    //   stack.push(twins[ind]);
    // }
    while (true) {
      if (stack.pop() == twins[ind]) {
        ind++;
      } else {
        break;
      }
    }
    if ((stack.peek() == -1) && (ind == (twins_size))) {
      return false;
    }

    while (stack.peek() != -1) {
      stack.pop();
    }
  }

  // cout << "twins_size " << twins_size << endl;
  // cout << "ind " << ind << endl;
  // cout << "last_elem " << last_elem << endl;
  // cout << "last_second_elem " << last_second_elem << endl;

  int count = 1;

  if (last_elem == last_second_elem) {
    for (; ind < twins_size; ind += 2) {
      stack.push(twins[ind]);
    }
    // now, ind = twins_size
    ind--;
    // now, ind = twins_size - 1
    while (true) {
      if (stack.pop() == twins[ind]) {
        ind -= 2;
      } else {
        count = 0;
        break;
      }
    }
    if (ind < 0 && stack.peek() == -1) {
      return false;
    }
    if (count == 0) {
      return true;
    }
  }  else if (last_elem != last_second_elem && last_second_elem == last_third_elem) {
    ind++;
    stack.push(twins[twins_size-1]);
    for (; ind < twins_size; ind += 2) {
      stack.push(twins[ind]);
    }
    int use = stack.pop(); // now stack has 1 2 3 4 5

    int last_val = twins[twins_size - 1];
    for (int index = twins_size - 1; index >= 0; index--) {
      twins[index] = twins[index-1];
    }
    twins[0] = last_val;
    // now, ind = twins_size + 1
    ind -= 2;
    // now, ind = twins_size - 1

    // cout << "twins print:" << endl;
    // for (int index = 0; index < twins_size; index++) {
    //   cout << twins[index] << " ";
    // }
    // cout << endl;

    // cout << ind << endl;

    while (true) {
      // cout << "line 131~~~~~~ " << twins[ind] << endl;
      if (stack.pop() == twins[ind]) {
        ind -= 2;
        // cout << "line 132 " << twins[ind] << endl;
      } else {
        count = 0;
        // cout << "line 135" << endl;
        break;
      }
    }
    if (ind < 0 && stack.peek() == -1) {
      // cout << "line 141" << endl;
      return false;
    }
    if (count == 0) {
      // cout << "line 145" << endl;
      return true;
    }
  }

  // cout << "line 150" << endl;
  return true;
}

int main() {
  // int n = 3;
  // int twins[] = {1, 2, 2, 1, 3, 3};
  // int n = 5;
  // int twins[] = {1,2,3,4,5,4,5,3,2,1};
  // int twins[] = {1,2,3,4,5,5,4,3,2,1};
  // int twins[] = {5,5,4,4,3,3,2,2,1,1};
  // int twins[] = {5,4,4,3,3,2,2,1,1,5};
  int n = 4;
  int twins[] = {4,3,3,2,1,2,1,4};

  if (ropesIntersect(twins, n)) {
    cout << "Intersection found\n";
  } else {
    cout << "No intersection\n";
  }

  return 0;
}
