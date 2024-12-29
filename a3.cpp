
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

// ------------------------- 1. Dijkstra's Algorithm for Smart Transportation ------------------------

class Dijkstra {
public:
    // Function to find the shortest path using Dijkstra's algorithm
    void find_shortest_path(int start, const vector<vector<pair<int, int>>>& graph) {
        int n = graph.size();
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});  // {distance, node}

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;  // Skip if already processed

            // Explore neighbors
            for (const auto& neighbor : graph[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Output the shortest paths
        cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << ": " << (dist[i] == INT_MAX ? -1 : dist[i]) << " units\n";
        }
    }
};

// ------------------------ 2. Segment Tree for Energy Consumption ------------------------

class SegmentTree {
private:
    vector<int> tree;
    int n;

    // Helper function to build the segment tree
    void build(const vector<int>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, 2 * v, tl, tm);
            build(arr, 2 * v + 1, tm + 1, tr);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    // Helper function to get the sum in a range [l, r]
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    // Helper function to update a single value
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2 * v, tl, tm, pos, new_val);
            } else {
                update(2 * v + 1, tm + 1, tr, pos, new_val);
            }
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

public:
    // Constructor to build the segment tree
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    // Function to query the sum in a range [l, r]
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    // Function to update a value at position pos
    void update(int pos, int new_val) {
        update(1, 0, n - 1, pos, new_val);
    }
};

// ------------------------ 3. Union-Find for Green Infrastructure ------------------------

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor to initialize Union-Find
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // Find the root of the set containing element x
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    // Union of two sets
    void union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// ------------------------ 4. Main Program ------------------------

int main() {
    srand(time(0));  // Seed for random number generation

    // 1. Dijkstra's Algorithm for Smart Transportation
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 1}},  // Node 0: connected to 1 with weight 4, 2 with weight 1
        {{0, 4}, {2, 2}, {3, 5}},  // Node 1
        {{0, 1}, {1, 2}, {3, 1}},  // Node 2
        {{1, 5}, {2, 1}}   // Node 3
    };
    Dijkstra dijkstra;
    dijkstra.find_shortest_path(0, graph);  // Find shortest paths from node 0

    // 2. Segment Tree for Energy Consumption
    vector<int> energy_data = {50, 60, 70, 80, 90};  // Sample energy data
    SegmentTree energy_tree(energy_data);
    cout << "Energy consumption sum from 1 to 3: " << energy_tree.query(1, 3) << endl;

    // Update energy consumption for building 2
    energy_tree.update(2, 100);
    cout << "Updated energy consumption sum from 1 to 3: " << energy_tree.query(1, 3) << endl;

    // 3. Union-Find for Green Infrastructure (connecting parks)
    UnionFind uf(5);
    uf.union_sets(0, 1);
    uf.union_sets(2, 3);
    uf.union_sets(3, 4);

    cout << "Park 0 and Park 4 are connected: " << (uf.find(0) == uf.find(4)) << endl;

    return 0;
}
