#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {};
};

class LinkedList {
  public:
    Node *head;

    LinkedList() : head(nullptr) {};

    void insert(int num) {
      Node *newNode = new Node(num);

      if (head == NULL) {
        head = newNode;
      } else {
        Node *temp = head;
        while (temp->next != NULL) {
          temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = NULL;
      }
    }

    void insertAt(int index, int num) {
      int count = 0;

      Node *temp1 = head;
      while (temp1 != NULL && count < index - 1) {
        temp1 = temp1->next;
        count++;
      }

      Node *newNode = new Node(num);
      newNode->next = temp1->next;
      temp1->next = newNode;
    }

    void swapIndex(int ind1, int ind2) {
      int count1 = 0;

      Node *temp1 = head;
      while(temp1->next != NULL) {
        temp1 = temp1->next;
        count1++;
        if (count1 == ind1 || count1 == ind2) {
          break;
        }
      }

      int count2 = 0;

      Node *temp2 = head;
      while(temp2->next != NULL) {
        temp2 = temp2->next;
        count2++;
        if ((count2 != count1) && (count2 == ind1 || count2 == ind2)) {
          break;
        }
      }

      int count3;
      if (count1 > count2) {
        count3 = count1;
        count1 = count2;
        count2 = count3;

        Node *temp3 = temp1;
        temp1 = temp2;
        temp2 = temp3;
      }

      Node *temp4 = temp1->next;
      temp1->next = temp2->next;
      temp2->next = temp4;
      temp4->next = temp1;

      temp4 = head;
      while (temp4->next != temp1) {
        temp4 = temp4->next;
      }
      temp4->next = temp2;
    }

    void swapNumbers(int num1, int num2) {
      Node *temp1 = head;
      while(temp1->next != NULL) {
        if (temp1->data == num1 || temp1->data == num2) {
          break;
        }
        temp1 = temp1->next;
      }

      Node *temp2 = head;
      while(temp2->next != NULL) {
        if ((temp2->data != temp1->data) && (temp2->data == num1 || temp2->data == num2)) {
          break;
        }
        temp2 = temp2->next;
      }

      Node *temp3 = temp1->next;
      temp1->next = temp2->next;
      temp2->next = temp3;
      temp3->next = temp1;

      temp3 = head;
      while (temp3->next != temp1) {
        temp3 = temp3->next;
      }
      temp3->next = temp2;
    }

    void display() {
      for (Node *temp = head; temp != NULL; temp = temp->next) {
        cout << temp->data << " ";
      }
      cout << endl;
    }
};

int main () {
  LinkedList ll;
  ll.insert(4);
  ll.insert(57);
  ll.insert(29);
  ll.insert(2);
  ll.insert(99);
  ll.insert(62);
  ll.display();
  cout << endl;

  ll.swapIndex(2, 4);
  ll.display();

  ll.swapIndex(4, 2);
  ll.display();
  cout << endl;

  ll.swapNumbers(57, 2);
  ll.display();

  ll.swapNumbers(2, 57);
  ll.display();
  cout << endl;

  ll.insertAt(2, 100);
  ll.display();
}

// INSERT (AT END), INSERT AT INDEX, DELETE (FROM END), DELETE FROM INDEX, DISPLAY, SWAP INDEX, SWAP NUMBERS
// DO DELETE (FROM END), DELETE FROM INDEX
