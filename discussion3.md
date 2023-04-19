---
marp: true
math: mathjax
---

# Discussion 3

Henry Yu

---

## Table of Contents

- Homework
- Dynamic Array

---

## Homework

- Deadline
- Grade
- Testing

---

## Dynamic Array

---

### What's a dynamic array?

A dynamic array is an array that can grow and shrink in size at runtime.

---

### Why dynamic array?

---

### Why dynamic array?

- We may not know the size of the array at the time of array declaration
- Elements can be added or removed at anytime

---

### Why dynamic array?

- We may not know the size of the array at the time of array declaration
- Elements can be added or removed at anytime
- Then, why not linked list?

---

### Why dynamic array?

- We may not know the size of the array at the time of array declaration
- We need efficient random access

---

### Array vs List

What's the difference between array and list?

---

### Array vs List

⚠️

There is no universal definition of array and list.

Different languages have different definitions & implementations.

---

### Array & List in C++

In C++,

- `std::list` is a doubly-linked list
- `std::vector` is a dynamic array
- `std::array` is a fixed-size array
- C-style array is also a fixed-size array

---

### In general context and some other languages

- Array often refers fixed-size array
- List usually refers to dynamic array
- Linked list is usually referred to as linked list explicitly

---

### Recap of Fixed-sized Array & Linked List

| Operation            | Fixed-sized Array <br> (e.g. `std::array`) | Linked List <br> (e.g. `std::list`) |
| -------------------- | ------------------------------------------ | ----------------------------------- |
| Random Access (`[]`) |                                            |                                     |
| Append               |                                            |                                     |
| Insert               |                                            |                                     |
| Remove               |                                            |                                     |
| Memory               |                                            |                                     |

---

### Recap of Fixed-sized Array & Linked List

| Operation            | Fixed-sized Array <br> (e.g. `std::array`) | Linked List <br> (e.g. `std::list`) |
| -------------------- | ------------------------------------------ | ----------------------------------- |
| Random Access (`[]`) | $O(1)$                                     | $O(n)$                              |
| Append               | Not supported                              | $O(1)$                              |
| Insert               | Not supported                              | $O(1)$                              |
| Remove               | Not supported                              | $O(1)$                              |
| Memory               | Continuous                                 | Not Continuous                      |

---

### How to implement a dynamic array?

---

### Naive Approach

When we append to the end of the array, we create a new array with **size + 1**,
copy all the elements from the old array to the new array, and then append the
new element to the new array.

---

### Naive Approach

When we append to the end of the array, we create a new array with **size + 1**,
copy all the elements from the old array to the new array, and then append the
new element to the new array.

- Con: $O(n)$ time complexity for append

---

### Improved Naive Approach

When we append to the end of the array, we check if the array is full. If it is
full, we create a new array with **size + 4**, copy all the elements from the
old array to the new array, and then append the new element to the new array.

---

### Improved Naive Approach

When we append to the end of the array, we check if the array is full. If it is
full, we create a new array with **size + 4**, copy all the elements from the
old array to the new array, and then append the new element to the new array.

- Pro: less memory allocation & copying for append than the naive approach
- Con: still $O(n)$ time complexity for append

---

### Improved Naive Approach

<style scoped>
table {
  font-size: 16px;
}
</style>

| Operation  | Capacity | Size | Memory Alloc/Dealloc | Elements Copied |
| ---------- | -------- | ---- | -------------------- | --------------- |
| Initialize | 4        | 0    | 1                    | 0               |
| Append     | 4        | 1    | 0                    | 1               |
| Append     | 4        | 2    | 0                    | 1               |
| Append     | 4        | 3    | 0                    | 1               |
| Append     | 4        | 4    | 0                    | 1               |
| Append     | 8        | 5    | 1                    | 4 + 1           |
| Append     | 8        | 6    | 0                    | 1               |
| Append     | 8        | 7    | 0                    | 1               |
| Append     | 8        | 8    | 0                    | 1               |
| Append     | 12       | 9    | 1                    | 8 + 1           |
| Append     | 12       | 10   | 0                    | 1               |
| Append     | ...      | ...  | ...                  | ...             |

---

### Improved Naive Approach (not a formal proof)

Total time to insert $n$ elements into the dynamic array that is empty:

$$
\begin{align*}
T_n(n)
&= n + \sum_{k=1}^{\frac{n}{4} - 1} 4k \\
&= O(n) + 4 \sum_{k=1}^{\frac{n}{4} - 1} k \\
&= O(n) + 4 \cdot \frac{\frac{n}{4} \cdot (\frac{n}{4} - 1)}{2} \\
&= O(n) + \frac{n^2}{8} - \frac{n}{2} \\
&= O(n^2) \\
\end{align*}
$$

Amortized time complexity for append:

$$
\begin{align*}
T_1(n) &= \frac{1}{n} O(n^2) = O(n) \\
\end{align*}
$$

---

### Actual Approach

When we append to the end of the array, we check if the array is full. If it is
full, we create a new array with **size \* 2**, copy all the elements from the
old array to the new array, and then append the new element to the new array.

- Pro: even less memory allocation & copying for append
- Con: average memory utilization is lower

---

### Actual Approach

<style scoped>
table {
  font-size: 16px;
}
</style>

| Operation  | Capacity | Size | Memory Alloc/Dealloc | Elements Copied |
| ---------- | -------- | ---- | -------------------- | --------------- |
| Initialize | 1        | 0    | 1                    | 0               |
| Append     | 1        | 1    | 0                    | 1               |
| Append     | 2        | 2    | 1                    | 1 + 1           |
| Append     | 4        | 3    | 1                    | 2 + 1           |
| Append     | 4        | 4    | 0                    | 1               |
| Append     | 8        | 5    | 1                    | 4 + 1           |
| Append     | 8        | 6    | 0                    | 1               |
| Append     | 8        | 7    | 0                    | 1               |
| Append     | 8        | 8    | 0                    | 1               |
| Append     | 16       | 9    | 1                    | 8 + 1           |
| Append     | 16       | 10   | 0                    | 1               |
| Append     | ...      | ...  | ...                  | ...             |

---

### Time Complexity for Actual Approach (not a formal proof)

Time for inserting $n$ elements into the dynamic array that is empty:

$$
\begin{align*}
T_n(n)

&= n + \sum_{k=1}^{\log_2 n - 1} 2^k \\
&= n + 2 \sum_{k=1}^{\log_2 n - 1} 2^k \\
&= n + 2 \cdot \frac{2^{\log_2 n} - 1}{2 - 1} \\
&= n + 2 \cdot (n - 1) \\
&= n + 2n - 2 \\
&= O(n) \\
\end{align*}
$$

Amortized time complexity for append:

$$
\begin{align*}
T_1(n) &= \frac{1}{n} O(n) = O(1) \\
\end{align*}
$$

---

### Time Complexity Comparison

| Operation            | Dynamic Array <br> (e.g. `std::vector`) | Fixed-sized Array <br> (e.g. `std::array`) | Doubly-linked List <br> (e.g. `std::list`) |
| -------------------- | --------------------------------------- | ------------------------------------------ | ------------------------------------------ |
| Random Access (`[]`) | $O(1)$                                  | $O(1)$                                     | $O(n)$                                     |
| Append               | $O(1)$ (amortized)                      | Not supported                              | $O(1)$                                     |
| Insert               | $O(n)$                                  | Not supported                              | $O(1)$                                     |
| Remove               | $O(n)$                                  | Not supported                              | $O(1)$                                     |
| Memory               | Continuous                              | Continuous                                 | Not Continuous                             |

---

### Actual Performance

In practice, Dynamic Array is usually faster than Linked List in all operations
when the number of elements is less than 20,000.

Why?

---

### Actual Performance

- big O only tells us the asymptotic performance
- continuous memory locations for elements makes dynamic array practically
  faster than linked list

---

Thank you!
