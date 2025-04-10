#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Node
{
    Node *left;
    Node *right;
    Node *par;
    int data;
    Node() : data(), par(NULL), left(NULL), right(NULL) {}
};

class BinaryTree
{
public:
    BinaryTree();
    int size();
    bool empty();
    Node *getRoot();
    void setRoot(Node *ptr);
    int depth(Node *ptr);
    int height1();
    int height2(Node *ptr);
    void preorder(Node *ptr);
    void postorder(Node *ptr);
    void inorder(Node *ptr);
    bool isRoot(Node *ptr);
    bool isLeaf(Node *ptr);
    Node *createTree(vector<int> &v, Node *root, Node *parent, int i);
    Node *getReferenceOf(int);

private:
    int n;
    Node *main_root;
    set<Node *> all_nodes;
    Node *preorderSearch(Node *root, int data);
};
BinaryTree::BinaryTree()
    : main_root(NULL), n(0) {}
int BinaryTree::size()
{
    return n;
}
bool BinaryTree::empty()
{
    return n == 0;
}
Node *BinaryTree::getRoot()
{
    return main_root;
}
void BinaryTree::setRoot(Node *ptr)
{
    main_root = ptr;
}
bool BinaryTree::isRoot(Node *ptr)
{
    if (!ptr)
        return false;
    if (ptr == main_root)
        return true;
    return false;
}
bool BinaryTree::isLeaf(Node *ptr)
{
    if (ptr->left == NULL && ptr->right == NULL)
        return true;
    return false;
}
int BinaryTree::depth(Node *ptr)
{
    if (!ptr)
        return 0;
    if (isRoot(ptr))
        return 0;
    return 1 + depth(ptr->par);
}
int BinaryTree::height1()
{
    int h = 0;
    for (auto i = all_nodes.begin(); i != all_nodes.end(); i++)
    {
        if (!isRoot(*i))
            h = max(h, depth(*i));
    }
    return h;
}
int BinaryTree::height2(Node *ptr)
{
    if (isLeaf(ptr) || !ptr)
        return 0;
    int h = 0;
    if (ptr->left)
        h = max(h, height2(ptr->left));
    if (ptr->right)
        h = max(h, height2(ptr->right));
    return 1 + h;
}
void BinaryTree::inorder(Node *ptr)
{
    if (!ptr)
        return;
    inorder(ptr->left);
    cout << " " << ptr->data;
    inorder(ptr->right);
}
void BinaryTree::postorder(Node *ptr)
{
    if (!ptr)
        return;
    postorder(ptr->left);
    postorder(ptr->right);
    cout << " " << ptr->data;
}
void BinaryTree::preorder(Node *ptr)
{
    if (!ptr)
        return;
    cout << ptr->data << " ";
    preorder(ptr->left);
    preorder(ptr->right);
}
Node *BinaryTree::createTree(vector<int> &v, Node *root, Node *parent, int i)
{
    n = v.size();
    if (i < v.size())
    {
        if (v[i] == -1)
        {
            return NULL; // NULL here
        }
        Node *temp = new Node;
        temp->data = v[i];
        temp->par = parent;
        root = temp;
        root->left = createTree(v, root->left, root, 2 * i + 1);
        root->right = createTree(v, root->right, root, 2 * i + 2);
        all_nodes.insert(root);
    }
    main_root = root;
    return root;
}
// returns a reference (pointer) to the node
// containing the given data (or NULL)
Node *BinaryTree::getReferenceOf(int data)
{
    // search in the set of all nodes
    for (Node *node : all_nodes)
    {
        if (node->data == data)
            return node;
    }
    return NULL;
}
