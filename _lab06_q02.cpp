#include <iostream>
using namespace std;

template <typename E>
class ArrayStack
{
    enum
    {
        DEF_CAPACITY = 100
    }; // default stack capacity
public:
    ArrayStack(int cap = DEF_CAPACITY); // constructor from capacity
    int size() const;                   // number of items in the stack
    bool empty() const;                 // is the stack empty?
    const E &top();                     // get the top element
    void push(const E &e);              // push element onto stack
    void pop();                         // pop the stack
                                        // ...housekeeping functions omitted
private:                                // member data
    E *S;                               // array of stack elements
    int capacity;                       // stack capacity
    int t;                              // index of the top of the stack
};

template <typename E> // push element onto the stack
void ArrayStack<E>::push(const E &e)
{
    if (size() == capacity)
        cout << "Push to full stack\n";
    S[++t] = e;
}

template <typename E> // pop the stack
void ArrayStack<E>::pop()
{
    if (empty())
        cout << "Pop from empty stack\n";
    --t;
}

template <typename E>
ArrayStack<E>::ArrayStack(int cap)
    : S(new E[cap]), capacity(cap), t(-1) {} // constructor from capacity

template <typename E>
int ArrayStack<E>::size() const
{
    return (t + 1);
} // number of items in the stack

template <typename E>
bool ArrayStack<E>::empty() const
{
    return (t < 0);
} // is the stack empty?

template <typename E> // return top of stack
const E &ArrayStack<E>::top()
{
    if (empty())
        cout << "Top of empty stack\n";
    return S[t];
}
int *findSpans(int *stockPrice, int n) {
  ArrayStack<int> stack;
  int *spans = new int[n];
  for (int day = 0; day < n; day++) {
    spans[day] = 0;
  }
  for (int day = 0; day < n; day++)
  {
      // POP all stack entries those are LESS THAN or EQUAL to the stock price for this day
      while (!stack.empty() && stockPrice[stack.top()] <= stockPrice[day]) {
          //Missing Code
          stack.pop();
      }
      // update spans array
      if (stack.empty()) {
          // if stack is empty, simply add 1 to current day index.
          // Missing code
          spans[day] = day + 1;
      }
      else {
          // span for this day is the consequtive day count.
          spans[day] = day - stack.top();
      }
      // PUSH this day index into the stack
      stack.push(day);
  }
  return spans;
}

int main() {
  int *stockPrice[2];
  // stockPrice[0] = new int[5] {6, 3, 4, 5, 2};
  stockPrice[0] = new int[5];
  // stockPrice[0] = {6, 3, 4, 5, 2};
  stockPrice[0][0] = 6;
  stockPrice[0][1] = 3;
  stockPrice[0][2] = 4;
  stockPrice[0][3] = 5;
  stockPrice[0][4] = 2;

  // stockPrice[1] = new int[7] {2, 4, 5, 6, 7, 8, 9};
  stockPrice[1] = new int[7];
  // stockPrice[1] = {2, 4, 5, 6, 7, 8, 9};
  stockPrice[1][0] = 2;
  stockPrice[1][1] = 4;
  stockPrice[1][2] = 5;
  stockPrice[1][3] = 6;
  stockPrice[1][4] = 7;
  stockPrice[1][5] = 8;
  stockPrice[1][6] = 9;

  int n[2] = {5, 7};
  for (int i = 0; i < 2; i++) {
      int *spans = findSpans(stockPrice[i], n[i]);
      cout << "\nInput Stocks Data: ";
      for (int j = 0; j < n[i]; j++)
          cout << stockPrice[i][j] << " ";
      cout << endl;
      cout << "Output Spans: ";
      for (int j = 0; j < n[i]; j++)
          cout << spans[j] << " ";
  }
  cout << endl;
}
