#include <iostream>
using namespace std;

struct Node {
    string data;
    struct Node* next;
};

Node* removeLastNode(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    delete (second_last->next);
    second_last->next = NULL;

    return head;
}

void insertNode(struct Node** head_ref, string new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    Node* head = NULL;

    insertNode(&head, "hyd");
    insertNode(&head, "Goa");
    insertNode(&head, "Dubai");
    insertNode(&head, "Pilani");

    head = removeLastNode(head);

    cout << "After deleting the last node:" << endl;
    for (Node* temp = head; temp != NULL; temp = temp->next)
        cout << temp->data << " ";
    return 0;
}

/*
After deleting the last node:
Pilani Dubai Goa
*/
