#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node* child, *sibling;

  Node() : value(0), child(nullptr), sibling(nullptr) {}
};

void treeFromInput(Node** tree, int n) {
  for (int i = 0; i < n; i++) {
    int value;
    cout << "Enter value: ";
    cin >> value;
    tree[i] = new Node();
    tree[i]->value = value;
  }
  for (int i = 1; i < n; i++) {
    int parent;
    cout << "Enter value of parent: ";
    cin >> parent;
    parent--;
    if (tree[parent]->child != nullptr)
      tree[i]->sibling = tree[parent]->child;
    tree[parent]->child = tree[i];
  }
}

double probabilityOdd(Node* node) {
  /* ??? */
}

int main() {
  int n;
  cout << "Enter value of n: ";
  cin >> n;
  Node** tree = (Node**)(malloc(sizeof(Node*) * n));
  treeFromInput(tree, n);
  cout << probabilityOdd(tree[0]) << '\n';
  return 0;
}
