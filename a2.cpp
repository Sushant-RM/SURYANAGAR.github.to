#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <climits>
#include <ctime>
#include <unordered_set>
#include <algorithm>

using namespace std;

// ------------------------ 1. Air Quality Monitoring (Hashing) ------------------------

class AirQualitySystem {
private:
    unordered_map<string, string> air_quality_data;

public:
    // Add air quality data for a region
    void add_data(const string& region, const string& data) {
        air_quality_data[region] = data;
    }

    // Retrieve air quality data for a region
    string get_data(const string& region) {
        if (air_quality_data.find(region) != air_quality_data.end()) {
            return air_quality_data[region];
        }
        return "No data available for this region.";
    }
};

// ------------------------ 2. Climate Resilience Planning (Union-Find) ------------------------

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
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

// ------------------------ 3. Waste Management System (Segment Tree) ------------------------

class SegmentTree {
private:
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    // Build the segment tree
    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];  // Sum of both children
        }
    }

    // Query the sum of elements in a range
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_query = query(2 * node + 1, start, mid, l, r);
        int right_query = query(2 * node + 2, mid + 1, end, l, r);
        return left_query + right_query;
    }

    // Update an element in the segment tree
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];  // Sum of both children
        }
    }
};

// ------------------------ 4. Graph Traversal for Optimal Waste Collection (DFS) ------------------------

class WasteCollection {
private:
    vector<vector<int>> graph;
    unordered_set<int> visited;

public:
    WasteCollection(int n) {
        graph.resize(n);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Depth First Search to traverse the graph for optimal collection
    void dfs(int node) {
        visited.insert(node);
        cout << "Visiting node: " << node << endl;

        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor);
            }
        }
    }
};

// ------------------------ 5. Main Program ------------------------

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation

    // 1. Air Quality Monitoring using Hashing
    AirQualitySystem airQualitySystem;
    airQualitySystem.add_data("RegionA", "PM2.5: 45 µg/m³, CO2: 300 ppm");
    airQualitySystem.add_data("RegionB", "PM2.5: 30 µg/m³, CO2: 200 ppm");

    cout << "Air Quality Data for RegionA: " << airQualitySystem.get_data("RegionA") << endl;
    cout << "Air Quality Data for RegionC: " << airQualitySystem.get_data("RegionC") << endl;

    // 2. Climate Resilience Planning using Union-Find
    UnionFind uf(5);  // Assume 5 different regions
    uf.union_sets(0, 1);  // Regions 0 and 1 are connected
    uf.union_sets(2, 3);  // Regions 2 and 3 are connected

    cout << "Regions 0 and 1 are connected: " << (uf.find(0) == uf.find(1)) << endl;
    cout << "Regions 1 and 3 are connected: " << (uf.find(1) == uf.find(3)) << endl;

    // 3. Waste Management using Segment Tree
    vector<int> waste_levels = {10, 20, 30, 40, 50};  // Initial waste levels in zones
    SegmentTree segTree(waste_levels.size());
    segTree.build(waste_levels, 0, 0, waste_levels.size() - 1);

    cout << "Total waste in zones 1 to 3: " << segTree.query(0, 0, waste_levels.size() - 1, 1, 3) << endl;

    // Update waste level in zone 2
    segTree.update(0, 0, waste_levels.size() - 1, 2, 35);
    cout << "Updated total waste in zones 1 to 3: " << segTree.query(0, 0, waste_levels.size() - 1, 1, 3) << endl;

    // 4. Waste Collection using DFS
    WasteCollection wasteCollection(5);  // 5 zones
    wasteCollection.add_edge(0, 1);
    wasteCollection.add_edge(1, 2);
    wasteCollection.add_edge(2, 3);
    wasteCollection.add_edge(3, 4);

    cout << "DFS Waste Collection starting from zone 0:\n";
    wasteCollection.dfs(0);

    return 0;
}

