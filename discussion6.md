---
marp: true
math: mathjax
---

# Discussion 6

Henry Yu

---

## Agenda

- Tree Traversal
- Red Black Trees

---

## Tree Traversal

- Pre-order
- In-order
- Postorder

---

## Tree Traversal

![width:384px](./image/disc6/Binary_tree_v2.svg)

---

## Tree Traversal

![width:384px](./image/disc6/Binary_tree_v2.svg)

Is this a binary search tree?

---

## Tree Traversal

![width:384px](./image/disc6/Binary_tree_v2.svg)

Pre-order: 1, 7, 2, 6, 5, 11, 9, 9, 5

In-order: 2, 7, 5, 6, 11, 1, 9, 5, 9

Post-order: 2, 5, 11, 6, 7, 5, 9, 9, 1

---

## Tree Traversal

![width:384px](./image/disc6/Binary_search_tree.svg.png)

For a binary search tree, in-order traversal gives you a sorted sequence.

---

## Red Black Tree

---

### Properties

- Why Red Black Tree?

- What are the properties of a Red Black Tree?

---

### Properties

1. Each node is either red or black
2. Root is black
3. Each Leaf is black
4. Each red node has only black chilren
5. For each node, all simple paths from the node to descendent leaves contain
   the same number of black nodes.

---

### Rotations

- Left Rotation
- Right Rotation

---

### Insertion Fix-up

1. Insert as regular binary search tree.
2. Set new node's color to Red. (Why?)
3. Fix up. (Which rule could be violated?)
