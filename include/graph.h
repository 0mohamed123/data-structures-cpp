#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

template <typename T>
class Graph {
private:
    std::unordered_map<T, std::vector<T>> adj;
    bool directed;

public:
    Graph(bool directed = false) : directed(directed) {}

    void add_vertex(T v) {
        if (adj.find(v) == adj.end())
            adj[v] = {};
    }

    void add_edge(T u, T v) {
        add_vertex(u);
        add_vertex(v);
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }

    std::vector<T> bfs(T start) {
        std::vector<T> result;
        std::unordered_set<T> visited;
        std::queue<T> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            T node = q.front(); q.pop();
            result.push_back(node);
            for (T neighbor : adj[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return result;
    }

    std::vector<T> dfs(T start) {
        std::vector<T> result;
        std::unordered_set<T> visited;
        std::stack<T> s;

        s.push(start);
        while (!s.empty()) {
            T node = s.top(); s.pop();
            if (!visited.count(node)) {
                visited.insert(node);
                result.push_back(node);
                for (T neighbor : adj[node])
                    if (!visited.count(neighbor))
                        s.push(neighbor);
            }
        }
        return result;
    }

    bool has_edge(T u, T v) {
        for (T neighbor : adj[u])
            if (neighbor == v) return true;
        return false;
    }

    int vertex_count() const { return adj.size(); }

    void print() const {
        for (auto& [v, neighbors] : adj) {
            std::cout << v << " -> ";
            for (T n : neighbors) std::cout << n << " ";
            std::cout << std::endl;
        }
    }
};