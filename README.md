# Data Structures in C++

![Language](https://img.shields.io/badge/Language-C%2B%2B17-blue)
![Tests](https://img.shields.io/badge/Tests-41%20passing-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

Generic implementation of core data structures in C++17 using templates.
All structures are header-only and verified by 41 automated tests.

## Data Structures Implemented

| Structure | Operations | Complexity |
|-----------|-----------|------------|
| LinkedList | push, pop, search, remove | O(n) |
| Stack | push, pop, top | O(1) |
| Queue | enqueue, dequeue, front, back | O(1) |
| BST | insert, search, remove, height | O(log n) avg |
| MaxHeap | push, pop, top | O(log n) |
| Graph | add_edge, BFS, DFS | O(V+E) |

## Quick Start

    git clone https://github.com/0mohamed123/data-structures-cpp.git
    cd data-structures-cpp

    # Compile and run demo
    g++ -std=c++17 -Wall -I include -o main src/main.cpp
    ./main

    # Run all tests
    g++ -std=c++17 -Wall -I include -o test_runner tests/test_all.cpp
    ./test_runner

## Test Results

    Running all tests...

    [LinkedList]  8/8  passed
    [Stack]       6/6  passed
    [Queue]       7/7  passed
    [BST]         6/6  passed
    [MaxHeap]     6/6  passed
    [Graph]       8/8  passed

    41 passed | 0 failed

## Key Design Decisions

- Header-only implementation using C++ templates
- Generic types — works with int, double, string, or any type
- RAII memory management — no memory leaks
- Exception handling for invalid operations
- BFS uses queue, DFS uses stack (iterative)

## Technologies

- C++17
- Templates for generic types
- STL (vector, queue, stack, unordered_map)
- Manual memory management with new/delete