#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* front_node;
    Node* back_node;
    int size;

public:
    Queue() : front_node(nullptr), back_node(nullptr), size(0) {}

    ~Queue() {
        while (front_node) {
            Node* temp = front_node;
            front_node = front_node->next;
            delete temp;
        }
    }

    void enqueue(T val) {
        Node* newNode = new Node(val);
        if (empty()) { front_node = back_node = newNode; }
        else {
            back_node->next = newNode;
            back_node = newNode;
        }
        size++;
    }

    void dequeue() {
        if (empty()) throw std::underflow_error("Queue is empty");
        Node* temp = front_node;
        front_node = front_node->next;
        if (!front_node) back_node = nullptr;
        delete temp;
        size--;
    }

    T front() const {
        if (empty()) throw std::underflow_error("Queue is empty");
        return front_node->data;
    }

    T back() const {
        if (empty()) throw std::underflow_error("Queue is empty");
        return back_node->data;
    }

    bool empty() const { return size == 0; }
    int get_size() const { return size; }

    void print() const {
        Node* curr = front_node;
        std::cout << "FRONT -> ";
        while (curr) {
            std::cout << curr->data;
            if (curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << " <- BACK" << std::endl;
    }
};