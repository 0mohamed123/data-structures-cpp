#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(T val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void push_back(T val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; }
        else {
            Node* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = newNode;
        }
        size++;
    }

    void pop_front() {
        if (!head) throw std::underflow_error("List is empty");
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    T front() const {
        if (!head) throw std::underflow_error("List is empty");
        return head->data;
    }

    bool contains(T val) const {
        Node* curr = head;
        while (curr) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }

    void remove(T val) {
        if (!head) return;
        if (head->data == val) { pop_front(); return; }
        Node* curr = head;
        while (curr->next && curr->next->data != val)
            curr = curr->next;
        if (curr->next) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            size--;
        }
    }

    int get_size() const { return size; }
    bool empty() const { return size == 0; }

    void print() const {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data;
            if (curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};