#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class MaxHeap {
private:
    std::vector<T> data;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    void heapify_up(int i) {
        while (i > 0 && data[parent(i)] < data[i]) {
            std::swap(data[parent(i)], data[i]);
            i = parent(i);
        }
    }

    void heapify_down(int i) {
        int largest = i;
        int l = left(i), r = right(i);
        int n = data.size();
        if (l < n && data[l] > data[largest]) largest = l;
        if (r < n && data[r] > data[largest]) largest = r;
        if (largest != i) {
            std::swap(data[i], data[largest]);
            heapify_down(largest);
        }
    }

public:
    void push(T val) {
        data.push_back(val);
        heapify_up(data.size() - 1);
    }

    void pop() {
        if (empty()) throw std::underflow_error("Heap is empty");
        data[0] = data.back();
        data.pop_back();
        if (!empty()) heapify_down(0);
    }

    T top() const {
        if (empty()) throw std::underflow_error("Heap is empty");
        return data[0];
    }

    bool empty() const { return data.empty(); }
    int get_size() const { return data.size(); }

    void print() const {
        std::cout << "Heap: ";
        for (const T& val : data) std::cout << val << " ";
        std::cout << std::endl;
    }
};