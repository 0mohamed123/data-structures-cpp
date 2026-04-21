#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* top_node;
    int size;

public:
    Stack() : top_node(nullptr), size(0) {}

    ~Stack() {
        while (top_node) {
            Node* temp = top_node;
            top_node = top_node->next;
            delete temp;
        }
    }

    void push(T val) {
        Node* newNode = new Node(val);
        newNode->next = top_node;
        top_node = newNode;
        size++;
    }

    void pop() {
        if (empty()) throw std::underflow_error("Stack is empty");
        Node* temp = top_node;
        top_node = top_node->next;
        delete temp;
        size--;
    }

    T top() const {
        if (empty()) throw std::underflow_error("Stack is empty");
        return top_node->data;
    }

    bool empty() const { return size == 0; }
    int get_size() const { return size; }

    void print() const {
        Node* curr = top_node;
        std::cout << "TOP -> ";
        while (curr) {
            std::cout << curr->data;
            if (curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};