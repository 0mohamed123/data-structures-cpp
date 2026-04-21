#include <iostream>
#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "bst.h"
#include "heap.h"
#include "graph.h"

int main() {
    // LinkedList
    LinkedList<int> list;
    list.push_back(1); list.push_back(2);
    list.push_back(3); list.push_front(0);
    std::cout << "LinkedList: "; list.print();

    // Stack
    Stack<int> stack;
    stack.push(10); stack.push(20); stack.push(30);
    std::cout << "Stack: "; stack.print();
    stack.pop();
    std::cout << "After pop: "; stack.print();

    // Queue
    Queue<int> q;
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    std::cout << "Queue: "; q.print();
    q.dequeue();
    std::cout << "After dequeue: "; q.print();

    // BST
    BST<int> bst;
    bst.insert(5); bst.insert(3); bst.insert(7);
    bst.insert(1); bst.insert(4); bst.insert(6);
    bst.print_inorder();
    std::cout << "Height: " << bst.height() << std::endl;
    bst.remove(3);
    std::cout << "After removing 3: "; bst.print_inorder();

    // Heap
    MaxHeap<int> heap;
    heap.push(3); heap.push(1); heap.push(7);
    heap.push(5); heap.push(9); heap.push(2);
    heap.print();
    std::cout << "Max: " << heap.top() << std::endl;
    heap.pop();
    std::cout << "After pop: "; heap.print();

    // Graph
    Graph<int> g;
    g.add_edge(1, 2); g.add_edge(1, 3);
    g.add_edge(2, 4); g.add_edge(3, 4);
    g.add_edge(4, 5);

    std::cout << "BFS from 1: ";
    for (int v : g.bfs(1)) std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "DFS from 1: ";
    for (int v : g.dfs(1)) std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}