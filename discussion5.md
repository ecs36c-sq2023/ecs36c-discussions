---
marp: true
math: mathjax
---

# Discussion 5

## Agenda

- Binary Search Tree
- Balanced BST
- Asides...

---

# Binary Search Tree (BST)

binary tree with order

---

## Definition

1. all nodes in left subtree is smaller than the node
2. all nodes in right subtree is larger than the node

In case of _hw2_,
recall we use `_comparator` to show the order of node's value

```py
cmp = _comparator(node, root)
if cmp == -1:
  node is on left subtree
else if cmp == 1:
  node is on right subtree
else:
  node is the root
```

---

## Walking on Tree

- inorder
  ```py
  def inorder(node):
    inorder(left)
    node.value
    inorder(right)
  ```
- preorder
  ```py
  def preorder(node):
    node.value
    preorder(left)
    preorder(right)
  ```
- postorder
  ```py
  def postorder(node):
    postorder(left)
    postorder(right)
    node.value
  ```

---

## Usage of different tree-walk

- inorder
  - BST -> sorted list
- preorder
  - copying the tree
- postorder
  - deleting the tree

---

## Best \& Worse Case BST

Case 1:

```cpp
BST<int> t1;
vector<int> xs({1, 2, 3, 4, 5, 6, 7, 8});
for (int x: xs) {
  t1.add(x);
}
```

Case 2:

```cpp
BST<int> t2;
vector<int> ys({5, 7, 2, 6, 8, 1, 3});
for (int y: ys) {
  t2.add(y);
}
```

what the difference for querying in `t1` and `t2`?

---

# Self-Balanced Tree

keep the tree at optimal shape

---

## Types of Self-Balanced Trees

- AVL Tree
  - hight difference between left and right <= 1
  - stricter
- **Red-Black Tree**
  - Color properties
- Splay Tree
  - re-order nodes up on access
- ...

---

## Red-Black Tree

todo
