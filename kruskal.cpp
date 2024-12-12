#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Kruskal {
public:
    int parent[MAX], rank[MAX];

    Kruskal();
    void read();
    int find(int);
    void unionSets(int, int);
    void kruskalMST();
};

Kruskal::Kruskal() {
    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int Kruskal::find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void Kruskal::unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

void Kruskal::read() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}

    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({weight, {u, v}});
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // Run Kruskal's MST
    cout << "Minimum Spanning Tree:\n";
    int mstWeight = 0;
    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int weight = edge.first;

        if (find(u) != find(v)) {
            cout << u << " - " << v << " : " << weight << endl;
            unionSets(u, v);
            mstWeight += weight;
        }
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    Kruskal k;
    k.read();
    return 0;
}
