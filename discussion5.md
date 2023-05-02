---
marp: true
math: mathjax
---

# Discussion 5

## Agenda

- Binary Search Tree
- Balanced BST
- Trait

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

---

## AVL Tree

make sure the tree is balanced using _balance factor_:

$$
BF(node) = height(node.right) - height(node.left)
$$

where the tree is balanced **if and only if** $|BF(root)| \leq 1$.

$$
BF_{AVL} : TreeNode \rightarrow \{-1, 0, 1 \}
$$

So when insert

1. BST insert
2. update height for each node
3. rotate (in **4** different ways)
4. update height for rotated nodes

---

## Increased Insertion Time

$height \in O(h)$, calling it on each node would be costly.

**what if**

$$
relaxed\_balance : \{-1, 0, 1\} \rightarrow \{R, B\}
$$

---

## Red-Black Tree

the tree is "balanced" if it satisfies the [RB-Tree properties](https://github.com/ecs36c-sq2023/hw2/blob/df5666fe27a7f1eb90e7c92ab75fa3c629fe4173/lib/BinaryTreeNode.hpp#L50).

when insert

- BST insert
- rotate / fix_violation (in **2** ways)
  - color of node is updated during _rotate time_.

---

|                     | AVL Tree    | RB Tree      |
| :------------------ | :---------- | :----------- |
| Balancing Criterion | strictly    | roughly      |
| search time         | $O(\log n)$ | ~$O(\log n)$ |
| need for rotation   | frequent    | few          |
| usage               | search only | general      |

RB Tree $\rightarrow$ ordered set, ordered map.

---

## Unordered Set and Unordered Map?

---

## Can we ensure the Tree is balanced at compile time?

1. [Analysis Pass on compiler](https://llvm.org/docs/Passes.html)
2. [Dependent Type](https://www.cs.princeton.edu/~appel/papers/redblack.pdf)

---

# Ad-hoc Polymorphism

polymorphism with limitation on Type Variable

---

## Recall From HW2

```cpp
template <typename T>
class TreeSet {
private:
  BinaryTreeNode<T> *_root;
  std::function<int(T, T)> _comparator;
  size_t _size;

public:
  TreeSet(std::function<int(T, T)> comparator);
}
```

why do we need this `comparator`?

---

For `T a` and `T b`, we need to tell which of them is smaller.

In other words, we require type $T$ to have [total order](https://en.wikipedia.org/wiki/Total_order).
For any ordered $T$, denoted by $Ord\ T$,

$$
\begin{aligned}
<  &: (T, T) \rightarrow Bool \\
== &: (T, T) \rightarrow Bool
\end{aligned}
$$

should be defined.

---

## An Ideal Class Definition for HW2

```cpp
template <typename Ord T>
class TreeSet {
private:
  BinaryTreeNode<T> *_root;
  size_t _size;

public:
  TreeSet();
}
```

where `_comparator` is specified in type `T`.

---

## Properties shared by Types

- `class`: defines shared properties between objects / values
- what should we call the shared properties between types?
  - traits (rust, scala, c++, ...)
  - function overloading (c++, java, ...)
  - containers (c++)
  - typeclass (haskell)
  - modular (ocaml)

---

## Extending Existing Traits

If we already have a trait `Eq` for equivalence relations,
we can say trait `Ord` extends `Eq` with `<`.
In other words, `Ord` "inherits" `==` from `Eq`.

---

## Why Trait?

- "checked" polymorphism
  - template in C++ uses "unchecked" type variables, which is
    - harder to debug
    - harder to analysis
- composition
  - we can require a type to be ordered `Ord` and numeric `Num` at the same time
- automatic deriving functions
  - for `Eq` with `==`, we should also have a `!=`
  - for `Ord` with `<`, we should have `>, >=, <=`, and `max, min`
  - with some function required, other functions can be derived in scope of the trait!
  - in fact, some languages even allow use to derive trait directly

---

## Iterable Tree?

We know a list (vector) is `Iterable`, can we derive `Iterable` for a Tree?
