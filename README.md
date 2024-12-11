# BTree Implementation

This is a generic C++ implementation of a B-Tree data structure. A B-Tree is a self-balancing search tree that maintains sorted data and allows search, sequential access, insertions, and deletions in logarithmic time. This implementation supports generic data types and can be instantiated with a specified order.

---

## Features

- **Generic Data Types:** Supports insertion of any data type (e.g., `int`, `char`, etc.).
- **Parameterized Order:** Specify the order of the B-Tree at compile time.
- **Insert Operation:** Handles key insertions with splitting when necessary.
- **Print Functionality:** Displays the B-Tree in an indented format to visualize its hierarchical structure.

---

## Code Overview

### Core Classes

1. **`BTreeNode<T, Order>`:** Represents a single node in the B-Tree. It stores keys and pointers to child nodes.
    - **`split(T* value):`** Splits the node when it overflows and promotes the middle key.
    - **`insertNonFull(T key):`** Inserts a key into the node if there is space or propagates the insertion to child nodes if necessary.
    - **`printIndented(int level):`** Recursively prints the B-Tree structure.

2. **`BTree<T, Order>`:** Represents the B-Tree itself.
    - **`insert(T key):`** Inserts a key into the tree, handling root splitting if required.
    - **`print():`** Prints the entire tree using the `printIndented` method of `BTreeNode`.

### Example Usage

```cpp
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
```

## Time Complexity Analysis
### **1-Insertion:**
- **Best Case**
--Insertion into a non-full leaf node: **O(1)**
-** Worst Case**
--Requires traversing from the root to a leaf: **O(log n)**.
--May involve splitting nodes along the path: **O(log n)**.

### **2-Search**
--Search involves traversing from the root to a leaf node, comparing keys at each level.
Time Complexity: O(log n).
