#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
    Node* cursor; // Pointer to the back node

public:
    CircularLinkedList() : head(nullptr), cursor(nullptr) {}

    ~CircularLinkedList() {
        if (head) {
            Node* current = head;
            Node* next;
            do {
                next = current->next;
                delete current;
                current = next;
            } while (current != head);
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node;
        newNode->data = data;

        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
            cursor = newNode;
        } else {
            newNode->next = head;
            head = newNode;
            cursor->next = head;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;

        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
            cursor = newNode;
        } else {
            newNode->next = head;
            cursor->next = newNode;
            cursor = newNode;
        }
    }

    void deleteFirst() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        if (head == head->next) { // Single node
            delete head;
            head = nullptr;
            cursor = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            cursor->next = head;
            delete temp;
        }
    }

    void deleteLast() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        if (head == head->next) { // Single node
            delete head;
            head = nullptr;
            cursor = nullptr;
        } else {
            Node* current = head;
            while (current->next != cursor) {
                current = current->next;
            }
            current->next = head;
            delete cursor;
            cursor = current;
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtBeginning(3);
    list.insertAtEnd(4);

    cout << "List: ";
    list.display();

    list.deleteFirst();
    cout << "After deleting first: ";
    list.display();

    list.deleteLast();
    cout << "After deleting last: ";
    list.display();

    return 0;
}
