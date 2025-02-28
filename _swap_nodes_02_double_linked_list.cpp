#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *prev;
    Node *next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {};
  };

class LinkedList {
  public:
    Node *head;
    Node *tail;

    LinkedList() : head(nullptr) {};

    // INSERT (AT END), INSERT AT INDEX, DELETE (FROM END), DELETE FROM INDEX, DISPLAY, SWAP INDEX, SWAP NUMBERS

    void insert(int num) {
      Node *newNode = new Node(num);

      if (head == NULL) {
        head = newNode;
        tail = newNode;
      } else {
        tail->next = newNode;
        newNode->prev = tail;

        tail = tail->next;
        newNode->next = NULL;
      }
    }

    void insertAt(int index, int num) {
      int size = 0;
      for (Node *cur = head; cur != NULL; cur = cur->next) {
        size++;
      }

      Node *newNode = new Node(num);

      if (index <= 0) {
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev = newNode;
        head = head->prev;
        return;
      } else if (index >= size) {
        insert(newNode->data);
        return;
      }

      int count = 0;

      Node *temp1 = head;
      while (temp1 != NULL && count < index - 1) {
        temp1 = temp1->next;
        count++;
      }
      newNode->prev = temp1;
      newNode->next = temp1->next;
      temp1->next = newNode;
      temp1 = temp1->next->next;
      temp1->prev = newNode;
    }

    void deleteFromEnd() {
      Node *temp = tail;
      tail = tail->prev;
      delete temp;
      tail->next = NULL;
    }

    void deleteFromIndex(int index) {
      int count = 0;
      Node *temp = head;
      while(temp->next != NULL && count < (index - 1)) {
        temp = temp->next;
        count++;
      }

      Node *temp1 = temp->next;
      temp->next = temp1->next;
      temp = temp1->next;
      temp->prev = temp1->prev;
      delete temp1;
    }

    void swapIndex(int ind1, int ind2) {
      int size = 0;
      for (Node *cur = head; cur != NULL; cur = cur->next) {
        size++;
      }
      if (ind1 > ind2) {
        int ind3 = ind1;
        ind1 = ind2;
        ind2 = ind3;
      }

      int count1 = 0;

      Node *temp1 = head;
      while(temp1->next != NULL) {
        if (count1 == ind1) {
          break;
        }
        temp1 = temp1->next;
        count1++;
      }

      int count2 = 0;
      Node *temp2 = head;
      while(temp2->next != NULL) {
        if (count2 == ind2) {
          break;
        }
        temp2 = temp2->next;
        count2++;
      }

      // cout << "count1: " << count1 << endl;
      // cout << "count2: " << count2 << endl;
      // cout << "temp1: " << temp1->data << endl;
      // cout << "temp2: " << temp2->data << endl;

      if (ind1 != 0 && ind2 != size) {
        Node *temp3 = temp1->prev;
        Node *temp4 = temp1->next;
        Node *temp5 = temp2->prev;

        temp1->prev = temp2->prev;
        temp1->next = temp2->next;
        temp2->prev = temp3;
        temp2->next = temp4;
        temp3->next = temp2;
        temp4->prev = temp2;
        temp2->next->prev = temp1;
        temp5->next = temp1;
      } else if (ind1 == 0 && ) {}
    }

    void swapNumbers(int num1, int num2) {}

    void display() {
      for (Node *temp = head; temp != NULL; temp = temp->next) {
        cout << temp->data << " ";
      }
      cout << endl;
    }

};

int main() {
  LinkedList ll;
  ll.insert(4);
  ll.insert(57);
  ll.insert(29);
  ll.insert(2);
  ll.insert(99);
  ll.insert(62);
  ll.display();
  cout << endl;

  ll.insertAt(-2, 100);
  ll.display();

  ll.swapIndex(0, 4);
  ll.display();

  // ll.swapIndex(4, 2);
  // ll.display();
  // cout << endl;

  // ll.swapNumbers(57, 2);
  // ll.display();

  // ll.swapNumbers(2, 57);
  // ll.display();
  // cout << endl;

  // ll.insertAt(2, 100);
  // ll.display();

  // ll.deleteFromEnd();
  // ll.display();

  // cout << "end" << endl;

  // ll.deleteFromIndex(2);
  // ll.display();
}

