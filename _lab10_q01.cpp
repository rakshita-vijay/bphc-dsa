#include <iostream>
#include <queue>
#include <list>

using namespace std;

/**
 * Implementing our own Comparators
 */

// For Min Priority Queue
class C
{
public:
    // Overriding the comparison operator
    // Telling the Compiler how to compare any two items.
    int operator()(const int a, const int b)
    {
        return a > b;
    }
};

// For Max Priority Queue
class D
{
    // code here...
    public:
        // Overriding the comparison operator
        // Telling the Compiler how to compare any two items.
        int operator()(const int a, const int b)
        {
            return a < b;
        }
};

// returns the sorted list
list<int> sortAscending(list<int> S)
{
    // initialize min priority queue
    priority_queue<int, vector<int>, C> P;

    /*
     * Ref Textbook Page: 329
     */
    while (!S.empty())
    {
        int e = S.front();
        S.pop_front();
        P.push(e);
    }
    while (!P.empty())
    {
        int e = P.top();
        S.push_back(e);
        P.pop();
    }

    return S;
}

// returns the reverse sorted list
list<int> sortDescending(list<int> S)
{
    // code here...
    // initialize min priority queue
    priority_queue<int, vector<int>, D> P;

    /*
     * Ref Textbook Page: 329
     */
    while (!S.empty())
    {
        int e = S.front();
        S.pop_front();
        P.push(e);
    }
    while (!P.empty())
    {
        int e = P.top();
        S.push_back(e);
        P.pop();
    }

    return S;
}

void display(list<int> S)
{
  std::list<int>::iterator itr;
  for (itr = S.begin(); itr != S.end(); *itr++)
    cout << *itr << ' ';
  cout << '\n';
}

class Point
{
public:
    int x;
    int y;
    Point(int X, int Y)
    {
        x = X;
        y = Y;
    }
};

/*
 * Write your own comparator class to compare two Points
 */
class E
{
public:
    // Overriding the comparison operator
    // Telling the Compiler how to compare any two items.
    int operator()(const Point &a, const Point &b)
    {
        return a.y > b.y;
    }
};

// returns the list of points sorted in
// increasing order of their Y coordinates.
list<Point> sortByYCoordinate(list<Point> points)
{
    // code here...
    // initialize min priority queue
    priority_queue<Point, vector<Point>, E> P;

    /*
     * Ref Textbook Page: 329
     */
    while (!points.empty())
    {
        Point e = points.front();
        points.pop_front();
        P.push(e);
    }
    while (!P.empty())
    {
        Point e = P.top();
        points.push_back(e);
        P.pop();
    }

    return points;
}

void display(list<Point> points)
{
    cout << "[ ";

    std::list<Point>::iterator itr;
    for (itr = points.begin(); itr != points.end(); *itr++)
    cout << '(' << itr->x << ", " << itr->y << ") ";

    cout << "]\n";
}

int main()
{
    // initialize list
    list<int> S;
    S.push_back(10);
    S.push_back(5);
    S.push_back(7);
    S.push_back(14);
    S.push_back(2);
    S.push_back(6);
    list<int> S2;
    S2.push_back(10);
    S2.push_back(5);
    S2.push_back(7);
    S2.push_back(14);
    S2.push_back(2);
    S2.push_back(6);

    cout << "Input List:-\n";
    display(S);

    S = sortAscending(S);
    S2 = sortDescending(S2);

    cout << "List sorted in Ascending Order:-\n";
    display(S);
    cout << "List sorted in Descending Order:-\n";
    display(S2);

    cout << endl;

    list<Point> points;

    points.push_back(Point(2, 7));
    points.push_back(Point(7, 4));
    points.push_back(Point(11, 2));
    points.push_back(Point(15, 9));

    cout << "Input Points:-\n";
    display(points);

    points = sortByYCoordinate(points);

    cout << "Points sorted in increasing order of Y coordinates:-\n";
    display(points);

    return 0;
}
