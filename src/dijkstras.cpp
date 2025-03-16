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

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int at = destination; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& path, int total) {
    for (int node : path) {
        cout << node << " ";
    }
    cout << "(Cost: " << total << ")\n";
}
