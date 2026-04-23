# DAA Project

Design and Analysis of Algorithms - Course Project

## Contributors

| SRN | Name |
|-----|------|
| PES2UG24CS910 | Prajwal M |
| PES2UG24CS150 | Deepthi V |
| PES2UG24CS917 | R.P Pranav |
| PES2UG24CS159 | Dimpal N |

---

## Overview

This project contains implementations of fundamental algorithms and data structures in C, demonstrating key concepts in algorithm design and analysis.

## Questions & Problems

### Question 1: TREAP Data Structure Implementation
**File**: `treap.c`

**Problem**: Implement a Treap (Tree + Heap) self-balancing binary search tree with standard operations.

**Description**:
- A Treap combines the properties of a Binary Search Tree and a Heap
- Each node has a key (for BST ordering) and a random priority (for heap ordering)
- Uses rotations to maintain both BST and Heap properties simultaneously

**Approach**:
- Combine BST property (sorted by key) with Heap property (random priority)
- Tree rotations (left and right) for maintaining balance
- Support insert, delete, and search operations
- Random priority-based self-balancing

**Key Features**:
- O(log N) average time complexity for insert, delete, and search
- O(N) space complexity
- Better cache locality than traditional balanced BSTs

**Time Complexity**: O(log N) average case
**Space Complexity**: O(N)

**Reference**: See [Question.pdf](Question.pdf) for detailed problem statement

---

### Question 2: Count Prime-Valued Nodes in Subtrees
**File**: `subtree_prime_count.c`

**Problem**: Given a tree where each node has a value, count the number of nodes with prime values in each subtree.

**Description**:
- For each node in the tree, determine how many nodes in its subtree contain prime numbers
- A node's value is prime if it is only divisible by 1 and itself
- Store and output the count for each node

**Approach**:
- Sieve of Eratosthenes for efficient prime number generation
- Adjacency list representation for tree storage
- Depth-First Search (DFS) traversal to count primes in subtrees
- Store results (answer array) for each node

**Key Features**:
- Efficient prime generation using sieve algorithm
- Single DFS traversal for all computations
- Graph-based tree representation with edge lists

**Time Complexity**: O(N × √M) where N is number of nodes and M is max node value
**Space Complexity**: O(N + M)

**Reference**: See [Question.pdf](Question.pdf) for detailed problem statement

---

### Question 3: N-Queens Problem
**File**: `QUEEN.C`

**Problem**: Place N queens on an N×N chessboard such that no two queens attack each other (no two queens share the same row, column, or diagonal).

**Description**:
- Classic backtracking problem with N=4 configuration
- Queens attack horizontally, vertically, and diagonally
- Find and count all valid placements of queens

**Approach**:
- Backtracking algorithm to explore all possible placements
- Constraint propagation using arrays:
  - `col[]`: tracks occupied columns
  - `diag1[]`: tracks occupied primary diagonals
  - `diag2[]`: tracks occupied anti-diagonals
- Recursive placement with validation
- Pruning invalid branches early

**Key Features**:
- Displays all valid board configurations
- Counts total number of solutions
- Visual representation with symbols (V=Queen, X=Blocked, .=Empty)
- Efficient constraint checking

**Time Complexity**: O(N!) - exploring all permutations
**Space Complexity**: O(N²) for board matrix and constraint arrays

**Reference**: See [Question.pdf](Question.pdf) for detailed problem statement

---

## Project Structure

```
DAA_project/
├── treap.c                  # TREAP data structure (Question 1)
├── subtree_prime_count.c    # Prime counting in tree subtrees (Question 2)
├── QUEEN.C                  # N-Queens algorithm (Question 3)
├── Question.pdf             # Complete problem statements and requirements
├── DAA PPT.pptx            # Algorithm presentations and visualizations
├── DAA report.pdf          # Comprehensive analysis and complexity discussion
└── README.md               # This file
```

## Building and Running

### Prerequisites
- GCC compiler
- Standard C library (stdio.h, stdlib.h, stdbool.h, time.h)

### Compilation
```bash
gcc treap.c -o treap
gcc subtree_prime_count.c -o prime_count
gcc QUEEN.C -o queen
```

### Execution
```bash
./treap
./prime_count
./queen
```

## Documentation

- **Question.pdf**: Detailed problem statements, constraints, and test cases (3 pages)
- **DAA PPT.pptx**: Algorithm visualizations and complexity analysis presentations
- **DAA report.pdf**: Comprehensive written report with implementations and analysis

## Course Information

**Subject**: Design and Analysis of Algorithms (DAA)

**Topics Covered**:
- Self-balancing data structures (TREAP)
- Tree algorithms and traversals (DFS)
- Backtracking algorithms
- Number theory applications (Sieve of Eratosthenes)
- Algorithm complexity analysis and Big-O notation
- Constraint satisfaction problems

## Algorithm Summary

| Algorithm | File | Category | Time | Space |
|-----------|------|----------|------|-------|
| TREAP | treap.c | Data Structure | O(log N) avg | O(N) |
| Prime Counting | subtree_prime_count.c | Graph Algorithm | O(N√M) | O(N) |
| N-Queens | QUEEN.C | Backtracking | O(N!) | O(N²) |

## License

Educational project for DAA course .

---
