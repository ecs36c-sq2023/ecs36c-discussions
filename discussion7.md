---
marp: true
math: mathjax
---

# Discussion 7

Henry Yu

---

## Agenda

- Review of Quick Sort and Merge Sort
- Radix Sort

---

## Quick Sort vs Merge Sort

|                   | Quick Sort | Merge Sort |
| ----------------- | ---------- | ---------- |
| Time Complexity   |            |            |
| Space Requirement |            |            |
| Stability         |            |            |

---

## Quick Sort vs Merge Sort

|                   | Quick Sort      | Merge Sort    |
| ----------------- | --------------- | ------------- |
| Time Complexity   | $O(n \log n)$\* | $O(n \log n)$ |
| Space Requirement | In-place        | Not in-place  |
| Stability         | Unstable        | Stable        |

---

## Radix Sort

Can we sort in linear time?

---

## Radix Sort

_Demo_

---

## Radix Sort

Time Complexity: $O(nw)$ where 

- $n$ is the number of keys
- $w$ is the key length
