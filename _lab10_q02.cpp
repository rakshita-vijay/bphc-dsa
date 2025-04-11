#include <iostream>
#include <vector>
using namespace std;

// Dynamic Array / Vector based Min Heap implementation
class MinHeap
{
private:
    vector<int> heap;
    int heapSize;
    int heapCapacity;
    void buildMinHeap();
    void bubbleDown(int index);
    void bubbleUp(int index);
    void swap(int i, int j);

public:
    // initializes an empty heap
    MinHeap()
    {
        heapSize = heapCapacity = 0;
    }
    // initializes the heap with the given elements.
    // This runs BUILD_MIN_HEAP operation internally.
    MinHeap(vector<int> elems)
    {
        heapSize = heapCapacity = elems.size();

        // hard-copy of elements into the heap
        // for (int elem : elems)
        for (int i = 0; i < heapSize; i++)
        {
            heap.push_back(elems[i]);
        }

        buildMinHeap();
    }
    void insert(int elem);
    int getMin() const;
    int extractMin();
    vector<int> sort();
    void display();
    bool empty() const;
    int size() const;
};

// BUILD_MIN_HEAP operation.
// Time Complexity = O(n)
void MinHeap::buildMinHeap()
{
    // Run from last internal node upto the root node.
    for (int i = (heapSize >> 1) - 1; i >= 0; i--)
    {
        // Heapify this entry
        bubbleDown(i);
    }
}

// Inserts the given element to the Heap
// Time Complexity = O(log n)
void MinHeap::insert(int elem)
{
    if (heapSize < heap.size())
    {
        // update the index with the new element
        heap[heapSize] = elem;
    }
    else
    {
        // append at the back
        heap.push_back(elem);
        ++heapCapacity;
    }

    // increment heap size
    ++heapSize;

    // heapify this new entry
    bubbleUp(heapSize-1);
}

// Returns the minimum item in the Heap
// Time Complexity = O(1)
int MinHeap::getMin() const
{
    return heap.at(0);
}

// Extracts and returns the minimum item from the heap.
// Time Complexity = O(log n)
int MinHeap::extractMin()
{
    if (empty())
        throw "Heap is Empty!";

    // Grab the minimum item
    int item = heap.at(0);

    // add missing code...
    heap[0] = heap.back();
    heap.pop_back();

    heapSize--;

    if (heapSize > 0)
      bubbleDown(0);

    return item;
}

// Heap Sort Algorithm.
// Returns the sorted list of elements in the Min Heap.
// Time Complexity = O(n * log n)
vector<int> MinHeap::sort()
{
    vector<int> sortedList;

    // STEP 1: Apply BUILD_MIN_HEAP operation
    buildMinHeap();

    // STEP 2: Use extractMin() to populate sortedList
    int count = heapSize;
    while (count > 0) // O(n)
    {
        // extract minimum element
        int minElem = extractMin(); // O(log n)

        // insert minElem into sortedList
        sortedList.push_back(minElem); // O(1)
        count--;
    }

    heap.clear();
    heapSize = heapCapacity = 0;

    // Populate heap
    // for (int elem : sortedList)
    for (int i = 0; i < sortedList.size(); i++)
        insert(sortedList.at(i));

    return sortedList;
}

// Bubble-Up operation
// Move a node upwards until the heap invariant is satisfied.
// Time Complexity = O(log n)
void MinHeap::bubbleUp(int index)
{
    if (index < 0 || index >= heapSize)
        throw "Invalid index.";
    if (index == 0)
        return;

    // Grab the index of the next parent node w.r.t. index
    int parent = (index - 1) >> 1;

    // Keep bubbling up, until we reach the root
    // or the heap property is satisfied.
    while (index > 0 && heap.at(index) < heap.at(parent))
    {
        // Exchange index with parent
        swap(index, parent);

        // update indices.
        index = parent;
        parent = (index - 1) >> 1;
    }
}

// Bubble-Down operation
// Move a node downwards until the heap invariant is satisfied.
// Time Complexity = O(log n)
void MinHeap::bubbleDown(int index)
{
    if (index < 0 || index >= heapSize)
        throw "Invalid index.";

    // complete the code...

    // Grab the index of the next child node w.r.t. index
    // int leftChild = (index << 1) + 1;
    // int rightChild = (index << 1) + 2;

    // int smallest = index;

    // Keep bubbling down, until we reach the root
    // or the heap property is satisfied.
    while (true)
    {
        int leftChild = (index << 1) + 1;
        int rightChild = (index << 1) + 2;

        int smallest = index;

        if (leftChild < heapSize && heap[leftChild] < heap[smallest]) {
          smallest = leftChild;
        }

        if (rightChild < heapSize && heap[rightChild] < heap[smallest]) {
          smallest = rightChild;
        }

        if (smallest != index) {
          // Exchange index with child
          swap(index, smallest);
          index = smallest;
        } else {
          break;
        }
    }
}

// Utility method to swap elements at given indices.
void MinHeap::swap(int i, int j)
{
    int elem = heap.at(i);
    heap.at(i) = heap.at(j);
    heap.at(j) = elem;
}

// Utility method to print the heap items
void MinHeap::display()
{
    cout << '[';
    for (int i = 0; i < size() - 1; i++)
        cout << heap.at(i) << ", ";
    if (!empty())
        cout << heap.at(size() - 1);
    cout << "]\n";
}

// Utility method to check if the heap is empty
bool MinHeap::empty() const
{
    return size() == 0;
}

// Utility method to get the size of the heap
int MinHeap::size() const
{
    return heapSize;
}

int main()
{
    try {MinHeap minHeap;

    minHeap.insert(6);
    minHeap.insert(3);
    minHeap.insert(4);
    minHeap.insert(7);

    cout << "Heap Elems: ";
    minHeap.display();

    cout << "Min Elem = " << minHeap.getMin() << '\n';

    cout << minHeap.extractMin() << " removed!\n";

    cout << "Heap Elems: ";
    minHeap.display();

    cout << "Min Elem = " << minHeap.getMin() << '\n';

    cout << minHeap.extractMin() << " removed!\n";

    cout << "Heap Elems: ";
    minHeap.display();

    minHeap.insert(8);
    minHeap.insert(1);

    cout << "Heap Elems: ";
    minHeap.display();

    cout << "Min Elem = " << minHeap.getMin() << '\n';

    cout << '\n';

    vector<int> inputList;
    inputList.push_back(7);
    inputList.push_back(4);
    inputList.push_back(-2);
    inputList.push_back(15);
    inputList.push_back(9);
    inputList.push_back(11);

    cout << "Input List:-\n";
    // for (int elem : inputList)
    for (int i = 0; i < inputList.size(); i++)
        cout << inputList[i] << ' ';
    cout << endl;

    MinHeap minHeap2(inputList);

    vector<int> sortedList = minHeap2.sort();

    cout << "Sorted List:-\n";
    // for (int elem : sortedList)
    for (int i = 0; i < sortedList.size(); i++) {
        cout << sortedList[i] << ' ';
    }
    cout << endl;}
    catch (const char* err) {
      cout << "Exception: " << err << endl;
  }

    return 0;
}
