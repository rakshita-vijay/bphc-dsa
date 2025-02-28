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

    // INSERT (AT END), INSERT AT INDEX, DELETE (FROM END), DELETE FROM INDEX, DISPLAY, SWAP INDEX, SWAP NUMBERS

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

      if (temp1 == NULL) return;

      Node *newNode = new Node(num);
      newNode->next = temp1->next;
      temp1->next = newNode;
    }

    void deleteFromEnd() {
      if (head == NULL) return;
      if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
      }

      Node *temp = head;
      while(temp->next->next != NULL) {
        temp = temp->next;
      }
      delete temp->next;
      temp->next = NULL;
    }

    void deleteFromIndex(int index) {
      if (head == NULL) return;
      if (index == 0) {
        delete head;
        head = NULL;
        return;
      }

      int count = 0;
      Node *temp = head;
      while((temp->next != NULL) && (count < (index - 1))) {
        temp = temp->next;
        count++;
      }
      Node *temp2 = temp->next;
      temp->next = temp2->next;
      temp2->next = NULL;
      delete temp2;
    }

    void swapIndex(int ind1, int ind2) {
      if (ind1 == ind2) return;

      int size = 0;

      for (Node *curr = head; curr != NULL; curr = curr->next) {
        size++;
      }

      // cout << "size: " << size << endl;

      int count1 = 0;

      Node *temp1 = head;
      while(temp1->next != NULL) {
        if (count1 == ind1 || count1 == ind2) {
          break;
        }
        temp1 = temp1->next;
        count1++;
      }

      int count2 = 0;

      Node *temp2 = head;
      while(temp2->next != NULL) {
        if ((count2 != count1) && (count2 == ind1 || count2 == ind2)) {
          break;
        }
        temp2 = temp2->next;
        count2++;
      }

      // cout << count1 << endl;
      // cout << count2 << endl;
      // cout << temp1->data << endl;
      // cout << temp2->data << endl;

      if (count1 > count2) {
        Node *temp3 = temp1;
        temp1 = temp2;
        temp2 = temp3;
      }

      if (count1 == 0 || count2 == 0) {
        head = temp2;
      }

      Node *temp4 = temp1;
      Node *temp5 = (temp1->next != temp2) ? temp1->next : temp1;
      while (temp4->next != temp2) {
        temp4 = temp4->next;
      }

      temp1->next = temp2->next;
      temp2->next = temp5;

      if ((count1 == 0 || count2 == 0) && (count2 - count1 != 1)) {
        Node *tempK = temp4;
          while(tempK->next != head || tempK->next != temp2) {
            tempK = tempK->next;
          }

          tempK->next = temp1;
          return;
      } else if ((count1 == 0 || count2 == 0) && (count2 - count1 == 1)) {
        head = temp2;
      } else if (count2 - count1 != 1) {
        temp4->next = temp1;

        Node *temp6 = head;
        while(temp6->next != temp1) {
          temp6 = temp6->next;
        }

        temp6->next = temp2;
      } else {
        Node *temp7 = head;
        while(temp7->next != temp1) {
          temp7 = temp7->next;
        }

        temp7->next = temp2;
      }
    }

    // void swapNumbers(int num1, int num2) {
    //   Node *temp1 = head;
    //   while(temp1->next != NULL) {
    //     if (temp1->data == num1 || temp1->data == num2) {
    //       break;
    //     }
    //     temp1 = temp1->next;
    //   }

    //   Node *temp2 = head;
    //   while(temp2->next != NULL) {
    //     if ((temp2->data != temp1->data) && (temp2->data == num1 || temp2->data == num2)) {
    //       break;
    //     }
    //     temp2 = temp2->next;
    //   }

    //   Node *temp3 = temp1->next;
    //   temp1->next = temp2->next;
    //   temp2->next = temp3;
    //   temp3->next = temp1;

    //   temp3 = head;
    //   while (temp3->next != temp1) {
    //     temp3 = temp3->next;
    //   }
    //   temp3->next = temp2;
    // }

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

  ll.swapIndex(5, 0);
  ll.display();

  ll.swapIndex(4, 2);
  ll.display();
  cout << endl;

  // ll.swapNumbers(57, 2);
  // ll.display();

  // ll.swapNumbers(2, 57);
  // ll.display();
  // cout << endl;

  ll.insertAt(2, 100);
  ll.display();

  ll.deleteFromEnd();
  ll.display();

  ll.deleteFromIndex(2);
  ll.display();

  cout << "end" << endl;
}

