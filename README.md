# B-Tree Implementation

This repository contains a C++ implementation of a generic B-Tree data structure with support for insertion and printing in an indented format. The B-Tree is templated, meaning it supports generic data types, and it works with a specified order.

## Features

- **Insert**: Insert a new key into the B-Tree, maintaining the balance of the tree.
- **Print**: Print the B-Tree in an indented format, showing the structure of the tree.
- **Split**: Split nodes when they exceed the maximum allowed keys (based on the order of the B-Tree).

## B-Tree Structure

A B-Tree of order `m` has the following properties:
- Every node has at most `m` children.
- Every node contains at most `m - 1` keys.
- Every non-root node must have at least `⌈m / 2⌉` children.
- The root node has at least 2 children if it is not a leaf.
- All leaves are at the same level.

## Time Complexities

### Insertion Complexity

- **Best-case time complexity**: **O(log n)**
    - Inserting a key into the tree when no splitting is required. This happens when the tree is balanced and no nodes need to be split, and the key is inserted in the correct position.
  
- **Worst-case time complexity**: **O(log n)**
    - Inserting a key into a B-Tree where the tree may need to perform multiple node splits as it propagates up the tree. Since the height of the B-Tree is proportional to **log n**, this operation remains logarithmic even when splits occur.

### Split Complexity

- **Split time complexity**: **O(1)**
    - Splitting a node only involves moving keys and children pointers, which is a constant-time operation for each node split. 

### Print Complexity

- **Print time complexity**: **O(n)**
    - Printing the tree involves traversing every node and key in the tree. Each node is visited once, and the keys within each node are printed, resulting in a linear time complexity relative to the number of keys in the tree.

## Example Usage

```cpp
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
```
