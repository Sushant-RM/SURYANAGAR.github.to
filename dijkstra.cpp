#include<bits/stdc++.h>
using namespace std;

#define s 100

class Dijkstra {
public:
    int n, m;
    int cost[s][s];
    int dis[s], path[s];
    vector<int> vis;

    Dijkstra();
    void read();
    void shortest_path(int);
    void path1();
};

Dijkstra::Dijkstra() {
    cout << "Enter number of vertices (n): ";
    cin >> n;
    cout << "Enter number of edges (m): ";
    cin >> m;
}

void Dijkstra::read() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    cout << "Enter the adjacency matrix (for each edge, enter the weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        cost[u][v] = weight;
        cost[v][u] = weight;
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    for (int i = 0; i < n; i++) {
        dis[i] = INT_MAX;
        path[i] = -1;
    }
    dis[src] = 0;
    vis.push_back(src);
}

void Dijkstra::shortest_path(int a) {
    int minDist = INT_MAX, minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (find(vis.begin(), vis.end(), i) == vis.end() && dis[i] < minDist) {
            minDist = dis[i];
            minIndex = i;
        }
    }

    if (minIndex == -1) return;

    vis.push_back(minIndex);

    for (int i = 0; i < n; i++) {
        if (cost[minIndex][i] != INT_MAX && dis[minIndex] + cost[minIndex][i] < dis[i]) {
            dis[i] = dis[minIndex] + cost[minIndex][i];
            path[i] = minIndex;
        }
    }

    shortest_path(minIndex);
}

int main() {
    Dijkstra d;
    d.read();

    cout << "Shortest distances from the source vertex:\n";
    for (int i = 0; i < d.n; i++) {
        cout << "Vertex " << i << ": Distance = " << d.dis[i] << ", Path = " << d.path[i] << endl;
    }

    return 0;
}
