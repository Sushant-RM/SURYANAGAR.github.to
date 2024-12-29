#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <string>
#include <ctime>  // Added for time()

using namespace std;

// ----------------------------- 1. Early Warning System -----------------------------------

// Simulating an IoT-enabled sensor network (e.g., flood or earthquake sensors)
class Sensor {
public:
    int id;  // Sensor ID
    double reading;  // Sensor data (e.g., water level or seismic reading)
    string type;  // Type of sensor (e.g., "Flood", "Earthquake")

    Sensor(int id, double reading, string type) : id(id), reading(reading), type(type) {}

    // Simulate sensor threshold alerting
    bool is_alert_triggered(double threshold) const {
        return reading >= threshold;
    }
};

// ----------------------------- 2. Crisis Mapping -----------------------------------

// Representing a city with a grid (for simplicity)
class CrisisMapping {
public:
    vector<vector<int>> cityGrid;
    int rows, cols;

    CrisisMapping(int rows, int cols) : rows(rows), cols(cols) {
        cityGrid = vector<vector<int>>(rows, vector<int>(cols, 0));  // Initializing city grid with 0 (no crisis)
    }

    // Update city grid with new crisis locations (e.g., flood areas)
    void update_grid(int row, int col, int crisisLevel) {
        cityGrid[row][col] = crisisLevel;
    }

    // Display the crisis map
    void display_map() {
        cout << "City Crisis Map: \n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << cityGrid[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// ----------------------------- 3. Resilience Dashboard ---------------------------------

// Class to simulate resilience dashboard, tracking various metrics
class ResilienceDashboard {
public:
    unordered_map<string, double> resilienceMetrics;

    // Add or update resilience metric (e.g., infrastructure health, response time)
    void update_metric(const string& metricName, double value) {
        resilienceMetrics[metricName] = value;
    }

    // Display the resilience dashboard
    void display_dashboard() {
        cout << "Resilience Dashboard:\n";
        for (const auto& metric : resilienceMetrics) {
            cout << metric.first << ": " << metric.second << endl;
        }
    }
};

// ---------------------------- 4. Union-Find Data Structure ----------------------------

// Union-Find class to track connected areas (used in Crisis Mapping for efficient grouping)
class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                if (rank[rootX] == rank[rootY]) rank[rootY]++;
            }
        }
    }
};

// ---------------------------- 5. Dijkstra's Algorithm for Resource Allocation ----------------------------

// Dijkstra's Algorithm for finding the shortest path to the crisis area
class Dijkstra {
public:
    void find_shortest_path(int start, const vector<vector<pair<int, int>>>& graph) {
        int n = graph.size();
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

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

// --------------------------- Main Program ---------------------------------

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Fixed time seed for randomness

    // ----------------- 1. Early Warning System -----------------
    cout << "Early Warning System - Simulating Sensor Alerts:\n";
    vector<Sensor> sensors = {
        Sensor(1, 8.0, "Flood"),
        Sensor(2, 3.0, "Earthquake"),
        Sensor(3, 7.5, "Flood"),
        Sensor(4, 9.0, "Earthquake")
    };

    double floodThreshold = 7.0;
    double earthquakeThreshold = 5.0;

    // Check for alerts
    for (const auto& sensor : sensors) {
        if ((sensor.type == "Flood" && sensor.is_alert_triggered(floodThreshold)) ||
            (sensor.type == "Earthquake" && sensor.is_alert_triggered(earthquakeThreshold))) {
            cout << "ALERT! Sensor " << sensor.id << " triggered for " << sensor.type << " with reading " << sensor.reading << endl;
        }
    }

    // ----------------- 2. Crisis Mapping -----------------
    cout << "\nCrisis Mapping - Updating Crisis Levels on the Map:\n";
    CrisisMapping cityMap(5, 5);  // 5x5 city grid (representing the city)
    cityMap.update_grid(2, 2, 5);  // Flood detected at (2,2)
    cityMap.update_grid(4, 4, 7);  // Earthquake detected at (4,4)
    cityMap.display_map();

    // ----------------- 3. Resilience Dashboard -----------------
    cout << "\nResilience Dashboard - Updating Metrics:\n";
    ResilienceDashboard dashboard;
    dashboard.update_metric("Disaster Response Time", 2.5);  // Time in hours
    dashboard.update_metric("Infrastructure Health", 85.5);  // Percentage
    dashboard.update_metric("Disaster Readiness", 92.0);  // Percentage
    dashboard.display_dashboard();

    // ----------------- 4. Union-Find for Green Infrastructure -----------------
    cout << "\nUnion-Find - Connecting Areas in the Crisis Map:\n";
    UnionFind uf(25);  // Representing a 5x5 grid of areas
    uf.union_sets(2, 12);  // Connect area 2 with area 12 (e.g., flood zones)
    uf.union_sets(4, 16);  // Connect area 4 with area 16 (e.g., earthquake zones)

    // ----------------- 5. Dijkstra for Resource Allocation -----------------
    cout << "\nDijkstra's Algorithm - Finding Shortest Paths to Crisis Areas:\n";
    vector<vector<pair<int, int>>> graph = {
        {{1, 10}, {2, 20}},  // Node 0
        {{0, 10}, {3, 5}},   // Node 1
        {{0, 20}, {3, 10}},  // Node 2
        {{1, 5}, {2, 10}}    // Node 3
    };
    Dijkstra dijkstra;
    dijkstra.find_shortest_path(0, graph);  // Find shortest paths from node 0 (e.g., resource center)

    return 0;
}
