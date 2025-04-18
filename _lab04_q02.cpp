#include <iostream>
using namespace std;

class DLinkedList;

typedef string Elem; // list element type
class DNode
{ // doubly linked list node
private:
    Elem elem;                // node element value
    DNode *prev;              // previous node in list
    DNode *next;              // next node in list
    friend class DLinkedList; // allow DLinkedList access
};

class DLinkedList
{ // doubly linked list
public:
    DLinkedList();                // constructor
    ~DLinkedList();               // destructor
    bool empty() const;           // is list empty?
    const Elem &front() const;    // get front element
    const Elem &back() const;     // get back element
    const Elem &middle() const;   // get middle element
    void addFront(const Elem &e); // add to front of list
    void addBack(const Elem &e);  // add to back of list
    void removeFront();           // remove from front
    void removeBack();            // remove from back
    void listReverse();           // reverse the list
    void traverse();              // traverse the list
    bool isPalindrome();          // check if the list is a palindrome
private:                          // local type definitions
    DNode *header;                // list sentinels
    DNode *trailer;

protected:                             // local utilities
    void add(DNode *v, const Elem &e); // insert new node before v
    void remove(DNode *v);             // remove node v
};

DLinkedList::DLinkedList()
{                       // constructor
    header = new DNode; // create sentinels
    trailer = new DNode;
    header->next = trailer; // have them point to each other
    trailer->prev = header;
}

DLinkedList::~DLinkedList()
{ // destructor
    while (!empty())
        removeFront(); // remove all but sentinels
    delete header;     // remove the sentinels
    delete trailer;
}

bool DLinkedList::empty() const // is list empty?
{
    return (header->next == trailer);
}

const Elem &DLinkedList::front() const // get front element
{
    return header->next->elem;
}

const Elem &DLinkedList::back() const // get back element
{
    return trailer->prev->elem;
}

const Elem &DLinkedList::middle() const // get middle element
{
    // Using Two pointer Technique
    DNode *slowPtr, *fastPtr;
    int count = 0;

    // initially both pointers point to the head node
    slowPtr = fastPtr = header;

    if (slowPtr == nullptr) {
      throw std::runtime_error("List is empty");
    }

    // complete the code here
    while ((fastPtr->next != nullptr) && (fastPtr->next->next != nullptr)) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;
      count++;
    }

    // [slowPtr] is the middle node
    cout << ((count % 2 == 0) ? "even number of elements" : "odd number of elements") << endl;
    return slowPtr->elem;
}

void DLinkedList::add(DNode *v, const Elem &e)
{ // insert new node before v
    DNode *u = new DNode;
    u->elem = e;       // create a new node for e
    u->next = v->next; // link u in between v
    u->prev = v;
    v->next->prev = u;
    v->next = u;
}

void DLinkedList::addFront(const Elem &e) // add to front of list
{
    add(header, e);
}

void DLinkedList::addBack(const Elem &e) // add to back of list
{
    add(trailer->prev, e);
}

void DLinkedList::remove(DNode *v)
{                       // remove node v
    DNode *u = v->prev; // predecessor
    DNode *w = v->next; // successor
    u->next = w;        // unlink v from list
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront() // remove from font
{
    remove(header->next);
}

void DLinkedList::removeBack() // remove from back
{
    remove(trailer->prev);
}

void DLinkedList::listReverse()
{                  // reverse a list
    DLinkedList T; // temporary list
    while (!this->empty())
    { // reverse L into T
        string s = this->front();
        this->removeFront();
        T.addFront(s);
    }
    while (!T.empty())
    { // copy T back to L
        string s = T.front();
        T.removeFront();
        this->addBack(s);
    }
}

void DLinkedList::traverse()
{
    DNode *temp = header;
    while (temp != trailer)
    {
        cout << temp->elem << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool DLinkedList::isPalindrome()
{
    // Complete the initialization of begin and end pointers.
    // begin is the first node and end is the last node of the list.
    DNode *begin = header->next;
    DNode *end = trailer->prev;

    if (begin == nullptr || end == nullptr || begin == end) {
      return 1;
    }

    while (begin != end)
    {
        // Check if the values of begin and end pointers are different.

        if (begin->next == end)
            break;

        //Update the begin and end pointers for the next iteration.
        if (begin->elem == end->elem) {
          begin = begin->next;
          end = end->prev;
          continue;
        } else {
          return 0;
        }
    }

    return 1;
}

void printChoices()
{
    cout << "+----------------------------------------+\n";
    cout << "Please enter one of the following choices:\n";
    cout << "1 : Add at the front\n";
    cout << "2 : Add at the end\n";
    cout << "3 : Remove from the front\n";
    cout << "4 : Remove from the end\n";
    cout << "5 : Get front-most element\n";
    cout << "6 : Get end-most element\n";
    cout << "7 : Get Middle element\n";
    cout << "8 : Check if list is empty\n";
    cout << "9 : Reverse List\n";
    cout << "10 : Traverse the list\n";
    cout << "11 : Check if the list is a palindrome\n";
    cout << "12 : Exit\n";
}

int main()
{
    DLinkedList dl;
    int choice = 0;
    while (1)
    {
        printChoices();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string elem;
            cout << "Enter the element to add to the front: ";
            cin >> elem;
            cout << "Adding the following element to the front: " << elem << endl;
            dl.addFront(elem);
            break;
        }
        case 2:
        {
            string elem;
            cout << "Enter the element to add to the back: ";
            cin >> elem;
            cout << "Adding the following element to the back: " << elem << endl;
            dl.addBack(elem);
            break;
        }
        case 3:
            cout << "Removing from the front\n";
            dl.removeFront();
            break;
        case 4:
            cout << "Removing from the back\n";
            dl.removeBack();
            break;
        case 5:
            cout << "Element at the front is: " << dl.front() << endl;
            break;
        case 6:
            cout << "Element at the back is: " << dl.back() << endl;
            break;
        case 7:
            cout << "Element at the middle is: " << dl.middle() << endl;
            break;
        case 8:
            cout << "List is " << (dl.empty() ? "" : "not ") << "empty\n";
            break;
        case 9:
            cout << "Reversing the list\n";
            dl.listReverse();
            break;
        case 10:
            cout << "Traversing the list: ";
            dl.traverse();
            break;
        case 11:
            cout << "List is " << ((dl.isPalindrome() == 1) ? "" : "not ") << "a palindrome\n";
            break;
        case 12:
            cout << "Exiting\n";
            exit(1);
            break;
        default:
            cout << "Not a valid entry!\n";
            break;
        }
    }
    return 0;
}
