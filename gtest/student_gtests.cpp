#include "dijkstras.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    vector<int> distance(G.numVertices, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    distance[source] = 0;
    pq.emplace(0, source);
    previous.resize(G.numVertices, -1);
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (dist > distance[u]) continue;
        
        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.emplace(distance[v], v);
            }
        }
    }
    return distance;
}

void print_path(const vector<int>& path, int total) {
    if (path.empty()) {
        cout << "No path found.\n";
        return;
    }
    cout << "Path: ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\nTotal cost is " << total << "\n";
}
