
/* Bubble Sort in a Doubly Linked List */


#include <iostream>


using namespace std;


// basic structure of a doubly linked list node
class doubly_linked_list_node
{
private:
   int data;
   doubly_linked_list_node *nextPtr;
   doubly_linked_list_node *prevPtr;


public:
   doubly_linked_list_node(int item)
   {
       // call to designated constructor
       doubly_linked_list_node(item, NULL, NULL);
   }
   // designated constructor
   doubly_linked_list_node(int item, doubly_linked_list_node *prev, doubly_linked_list_node *next)
   {
       data = item;
       prevPtr = prev;
       nextPtr = next;
   }
   int getData();
   doubly_linked_list_node *getNext();
   doubly_linked_list_node *getPrev();
   void setNext(doubly_linked_list_node *newNext);
   void setPrev(doubly_linked_list_node *newPrev);
};


typedef doubly_linked_list_node node;


int node::getData()
{
   return data;
}


node *node::getNext()
{
   return nextPtr;
}


node *node::getPrev()
{
   return prevPtr;
}


void node::setNext(node *newNext)
{
   nextPtr = newNext;
}


void node::setPrev(node *newPrev)
{
   prevPtr = newPrev;
}


// basic functionalities in a doubly linked list data structure.
class doubly_linked_list
{
private:
   node *head, *tail;
   void bubbleSort();
   void swap(node *, node *);


public:
   doubly_linked_list()
   {
       head = tail = NULL;
   }
   void append(int item);
   bool isEmpty();
   void sort();
   void display();
};


typedef doubly_linked_list list;


// appends the given item at the end of the list
void list::append(int item)
{
   if (isEmpty())
   {
       head = tail = new node(item, NULL, NULL);
   }
   else
   {
       tail->setNext(new node(item, tail, NULL));
       tail = tail->getNext();
   }
}


// utility method to check if the list is empty
bool list::isEmpty()
{
   return head == NULL;
}


// sorts the given list
void list::sort()
{
   if (isEmpty())
   {
       return;
   }
   bubbleSort();
}


// Implementing bubble sort algorithm in a Doubly Linked List
// Time Complexity:
// Best Case = Omega(n)
// Worst Case = Big-Oh(n^2)
void list::bubbleSort()
{
   // Complete the code here...
   if (head == NULL)
   {
       return;
   }
   int size = 0;
   for (doubly_linked_list_node *temp_1 = head; temp_1 != NULL; temp_1 = temp_1->getNext())
   {
       size++;
   }


   bool swapped;
   for (int i = 0; i < size; i++)
   {
       swapped = false;
       for (int j = 0; j < (size - i - 1); j++)
       {
           int k = j;
           doubly_linked_list_node *temp_2 = head;
           for (; temp_2 != NULL && k > 0; temp_2 = temp_2->getNext())
           {
               k--;
           }
           if (temp_2->getData() > temp_2->getNext()->getData())
           {
               swap(temp_2, temp_2->getNext());
               swapped = true;
           }
       }
       if (swapped == false)
       {
           break;
       }
   }
   // bool swapped;
   // for (doubly_linked_list_node *temp_out = head; temp_out != NULL; temp_out = temp_out->getNext())
   // {
   //     swapped = false;
   //     for (doubly_linked_list_node *temp_in = head; temp_in != temp_out->getPrev() && temp_in != NULL; temp_in = temp_in->getNext())
   //     {
   //         if (temp_out->getData() < temp_in->getData()) {
   //             swapped = true;
   //         }
   //         else if (temp_out->getData() == temp_in->getData()) {
   //             continue;
   //         }
   //         else {
   //             swap(temp_out, temp_in);
   //             swapped = true;
   //         }
   //         cout << "in inner loop" << endl;
   //     }
   //     if (!swapped)
   //     {
   //         break;
   //     }
   // }
}


// utility method to swap the two adjacent nodes of the list
void list::swap(node *a, node *b)
{
   if (a->getPrev() == b)
   {
       swap(b, a);
   }
   // fix the head pointer
   if (head == a || head == b)
   {
       if (head == a)
       {
           head = b;
       }
       else
       {
           head = a;
       }
   }
   // fix the tail pointer
   if (tail == a || tail == b)
   {
       // Missing code D (multiple lines)
       if (tail == a)
       {
           tail = b;
       }
       else
       {
           tail = a;
       }
   }
   // update [a]'s next pointer
   a->setNext(b->getNext());
   // update [b]'s next pointer


   // missing code E (one line)
   b->setNext(a);


   // update the prev pointer of [a]'s new next node
   if (a->getNext() != NULL)
   {
       a->getNext()->setPrev(a);
   }
   // update [b]'s prev pointer
   b->setPrev(a->getPrev());
   // update [a]'s prev pointer
   a->setPrev(b);
   // update the next pointer of [b]'s new prev node
   if (b->getPrev() != NULL)
   {
       b->getPrev()->setNext(b);
   }
}


// utility method to display the list contents
void list::display()
{
   if (isEmpty())
   {
       cout << "Empty List!\n";
       return;
   }
   node *ptr;
   cout << "NULL";
   for (ptr = head; ptr != tail; ptr = ptr->getNext())
   {
       cout << " <- " << ptr->getData() << " -> ";
   }
   cout << " <- " << tail->getData() << " -> "
        << "NULL" << endl;
}


int main()
{
   list li;
   li.append(20);
   li.append(30);
   li.append(15);
   cout << "Before Sorting:\n";
   li.display();
   li.sort();
   cout << "After Sorting:\n";
   li.display();
   li.sort();
   li.append(10);
   li.append(25);
   li.append(35);
   cout << "Before Sorting:\n";
   li.display();
   li.sort();
   cout << "After Sorting:\n";
   li.display();
   return 0;
}
