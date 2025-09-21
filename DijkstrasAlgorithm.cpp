#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;


struct Edge {
    int destination;
    int weight;
};


void dijkstra(vector<vector<Edge>>& graph, int vertices, int start, int end) {
    vector<int> distances(vertices, INT_MAX); 
    vector<bool> visited(vertices, false);    
    vector<int> parent(vertices, -1);        

    distances[start] = 0; 

 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // {distance, node}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        // Check all neighbors of current node
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                parent[v] = u;
                pq.push({distances[v], v});
            }
        }
    }

    // Output results
    if (distances[end] == INT_MAX) {
        cout << "No path from node " << start << " to node " << end << endl;
        return;
    }

    cout << "Shortest path cost from node " << start << " to node " << end 
         << ": " << distances[end] << endl;
    cout << "Path: ";

    // Reconstruct path
    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    // Hardcoded graph with 5 vertices (0 to 4)
    int vertices = 5;
    vector<vector<Edge>> graph(vertices);

    // Graph structure (undirected, weighted)
    // Node 0: (0->1, 4), (0->4, 8)
    graph[0].push_back({1, 4});
    graph[0].push_back({4, 8});
    // Node 1: (1->0, 4), (1->2, 8)
    graph[1].push_back({0, 4});
    graph[1].push_back({2, 8});
    // Node 2: (2->1, 8), (2->3, 7)
    graph[2].push_back({1, 8});
    graph[2].push_back({3, 7});
    // Node 3: (3->2, 7), (3->4, 9)
    graph[3].push_back({2, 7});
    graph[3].push_back({4, 9});
    // Node 4: (4->0, 8), (4->3, 9)
    graph[4].push_back({0, 8});
    graph[4].push_back({3, 9});

    int start, end;
    cout << "Enter start node (0 to " << vertices - 1 << "): ";
    cin >> start;
    cout << "Enter end node (0 to " << vertices - 1 << "): ";
    cin >> end;

    // Validate input
    if (start < 0 || start >= vertices || end < 0 || end >= vertices) {
        cout << "Invalid node selection!" << endl;
        return 1;
    }

    dijkstra(graph, vertices, start, end);

    return 0;
}