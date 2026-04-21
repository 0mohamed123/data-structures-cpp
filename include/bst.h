#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, T val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    bool search(Node* node, T val) const {
        if (!node) return false;
        if (val == node->data) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    Node* min_node(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* remove(Node* node, T val) {
        if (!node) return nullptr;
        if (val < node->data) node->left = remove(node->left, val);
        else if (val > node->data) node->right = remove(node->right, val);
        else {
            if (!node->left) { Node* temp = node->right; delete node; return temp; }
            if (!node->right) { Node* temp = node->left; delete node; return temp; }
            Node* successor = min_node(node->right);
            node->data = successor->data;
            node->right = remove(node->right, successor->data);
        }
        return node;
    }

    void inorder(Node* node) const {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    int height(Node* node) const {
        if (!node) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroy(root); }

    void insert(T val) { root = insert(root, val); }
    bool search(T val) const { return search(root, val); }
    void remove(T val) { root = remove(root, val); }
    int height() const { return height(root); }
    bool empty() const { return root == nullptr; }

    void print_inorder() const {
        std::cout << "Inorder: ";
        inorder(root);
        std::cout << std::endl;
    }
};