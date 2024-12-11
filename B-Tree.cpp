#include <iostream>
#include <string>
using namespace std;

template <class T, int Order>
struct BTreeNode {
    int n;
    int order;
    T* keys;
    BTreeNode** children;

    BTreeNode(int order) : n(0), order(order) {
        keys = new T[order]; // order "extra key before splitting"
        children = new BTreeNode*[order + 1];
        for (int i = 0; i <= order; i++) {
            children[i] = nullptr;
        }
    }

    BTreeNode* split(T* value) {
        int midIndex = n / 2; // get the index of the key that will be promoted to the parent node.
        *value = keys[midIndex];

        BTreeNode<T, Order>* newNode = new BTreeNode<T, Order>(order);

        //keys after middle key are moved to the new node
        for (int i = midIndex + 1; i < n; ++i) {
            newNode->keys[newNode->n++] = keys[i];
        }

        // separate the children
        for (int i = midIndex + 1; i <= n; ++i) {
            newNode->children[i - midIndex - 1] = children[i];
        }

        n = midIndex;
        return newNode;
    }

    int insertNonFull(T key) {
        int i = n - 1; //starts at the index of the last key in the current node
        if (children[0] == nullptr) {  // Leaf node
            while (i >= 0 && keys[i] > key) {
                keys[i + 1] = keys[i]; // Shift keys to the right
                i--;
            }
            keys[i + 1] = key; //Insert the key at the correct position
            n++;
        } else {  // Internal node
            while (i >= 0 && keys[i] > key) {
                i--;
            }
            i++;  // Move to the correct child
            int splitRequired = children[i]->insertNonFull(key);
            if (splitRequired) {
                T mid;
                BTreeNode<T, Order>* newNode = children[i]->split(&mid);

                for (int j = n; j > i; --j) {
                    keys[j] = keys[j - 1]; // Shift keys to the right
                    children[j + 1] = children[j];  // Shift children to the right
                }
                keys[i] = mid;
                children[i + 1] = newNode;
                n++;
            }
        }

        return n == order;
    }

    void printIndented(int level) {
        for (int i = 0; i < level; ++i) {
            cout << "  ";  // Indentation for current level
        }
        for (int i = 0; i < n; ++i) {
            cout << keys[i];
            if (i < n - 1) {
                cout << ",";
            }
        }
        cout << endl;

        for (int i = 0; i <= n; ++i) {
            if (children[i]) {
                children[i]->printIndented(level + 1);
            }
        }
    }
};

template <class T, int Order>
class BTree {
private:
    BTreeNode<T, Order>* root;
    int order;

public:
    BTree() : root(nullptr), order(Order) {}

    void insert(T key) {
        if (!root) {
            root = new BTreeNode<T, Order>(order);
            root->keys[0] = key;
            root->n = 1;
        } else {
            int splitRequired = root->insertNonFull(key);
            if (splitRequired) {
                T mid;
                BTreeNode<T, Order>* newNode = root->split(&mid);

                BTreeNode<T, Order>* newRoot = new BTreeNode<T, Order>(order);
                newRoot->keys[0] = mid;
                newRoot->children[0] = root;
                newRoot->children[1] = newNode;
                newRoot->n = 1;

                root = newRoot;
            }
        }
    }

    void print() {
        if (root) {
            root->printIndented(0);
        } else {
            cout << "Empty B-Tree!" << endl;
        }
    }
};

int main() {
    // BTree of order 3
    BTree<int, 3> t1;
    t1.insert(1);
    t1.insert(5);
    t1.insert(0);
    t1.insert(4);
    t1.insert(3);
    t1.insert(2);
    t1.print();


    // BTree of order 5
    BTree<char, 5> t;
    t.insert('G');
    t.insert('I');
    t.insert('B');
    t.insert('J');
    t.insert('C');
    t.insert('A');
    t.insert('K');
    t.insert('E');
    t.insert('D');
    t.insert('S');
    t.insert('T');
    t.insert('R');
    t.insert('L');
    t.insert('F');
    t.insert('H');
    t.insert('M');
    t.insert('N');
    t.insert('P');
    t.insert('Q');
    t.print();

    return 0;
}
