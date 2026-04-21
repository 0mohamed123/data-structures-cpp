#include <iostream>
#include <cassert>
#include <string>
#include "../include/linked_list.h"
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/bst.h"
#include "../include/heap.h"
#include "../include/graph.h"

int passed = 0;
int failed = 0;

void test(bool condition, const std::string& name) {
    if (condition) {
        std::cout << "  [PASS] " << name << std::endl;
        passed++;
    } else {
        std::cout << "  [FAIL] " << name << std::endl;
        failed++;
    }
}

void test_linked_list() {
    std::cout << "\n[LinkedList]" << std::endl;
    LinkedList<int> list;
    test(list.empty(), "empty on init");
    list.push_back(1); list.push_back(2); list.push_back(3);
    test(list.get_size() == 3, "size after push_back");
    test(list.front() == 1, "front correct");
    test(list.contains(2), "contains existing");
    test(!list.contains(99), "not contains missing");
    list.remove(2);
    test(!list.contains(2), "remove works");
    test(list.get_size() == 2, "size after remove");
    list.push_front(0);
    test(list.front() == 0, "push_front works");
}

void test_stack() {
    std::cout << "\n[Stack]" << std::endl;
    Stack<int> s;
    test(s.empty(), "empty on init");
    s.push(10); s.push(20); s.push(30);
    test(s.top() == 30, "top correct");
    test(s.get_size() == 3, "size correct");
    s.pop();
    test(s.top() == 20, "top after pop");
    test(s.get_size() == 2, "size after pop");
    bool threw = false;
    Stack<int> empty_s;
    try { empty_s.pop(); } catch (...) { threw = true; }
    test(threw, "pop empty throws");
}

void test_queue() {
    std::cout << "\n[Queue]" << std::endl;
    Queue<int> q;
    test(q.empty(), "empty on init");
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    test(q.front() == 1, "front correct");
    test(q.back() == 3, "back correct");
    test(q.get_size() == 3, "size correct");
    q.dequeue();
    test(q.front() == 2, "front after dequeue");
    test(q.get_size() == 2, "size after dequeue");
    bool threw = false;
    Queue<int> empty_q;
    try { empty_q.dequeue(); } catch (...) { threw = true; }
    test(threw, "dequeue empty throws");
}

void test_bst() {
    std::cout << "\n[BST]" << std::endl;
    BST<int> bst;
    test(bst.empty(), "empty on init");
    bst.insert(5); bst.insert(3); bst.insert(7);
    bst.insert(1); bst.insert(4);
    test(bst.search(3), "search existing");
    test(!bst.search(99), "search missing");
    test(bst.height() == 3, "height correct");
    bst.remove(3);
    test(!bst.search(3), "remove works");
    test(bst.search(4), "child preserved after remove");
}

void test_heap() {
    std::cout << "\n[MaxHeap]" << std::endl;
    MaxHeap<int> h;
    test(h.empty(), "empty on init");
    h.push(3); h.push(1); h.push(7); h.push(5); h.push(9);
    test(h.top() == 9, "max at top");
    test(h.get_size() == 5, "size correct");
    h.pop();
    test(h.top() == 7, "max after pop");
    h.push(100);
    test(h.top() == 100, "new max correct");
    bool threw = false;
    MaxHeap<int> empty_h;
    try { empty_h.pop(); } catch (...) { threw = true; }
    test(threw, "pop empty throws");
}

void test_graph() {
    std::cout << "\n[Graph]" << std::endl;
    Graph<int> g;
    g.add_edge(1, 2); g.add_edge(1, 3);
    g.add_edge(2, 4); g.add_edge(3, 4);
    g.add_edge(4, 5);
    test(g.has_edge(1, 2), "edge exists");
    test(g.has_edge(2, 1), "undirected edge");
    test(!g.has_edge(1, 5), "non-edge correct");
    test(g.vertex_count() == 5, "vertex count");
    auto bfs = g.bfs(1);
    test(bfs[0] == 1, "BFS starts correct");
    test(bfs.size() == 5, "BFS visits all");
    auto dfs = g.dfs(1);
    test(dfs[0] == 1, "DFS starts correct");
    test(dfs.size() == 5, "DFS visits all");
}

int main() {
    std::cout << "Running all tests..." << std::endl;
    test_linked_list();
    test_stack();
    test_queue();
    test_bst();
    test_heap();
    test_graph();
    std::cout << "\n==============================" << std::endl;
    std::cout << "  " << passed << " passed | " << failed << " failed" << std::endl;
    std::cout << "==============================" << std::endl;
    return failed > 0 ? 1 : 0;
}