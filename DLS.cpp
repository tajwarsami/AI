#include <bits/stdc++.h>
using namespace std;

void dls(int node, vector<vector<int>>& adj, vector<bool>& visited, int limit, int depth) {

    if (depth > limit) return;


    cout << node << " ";
    visited[node] = true;

    for (int adjNode : adj[node]) {
        if (!visited[adjNode]) {
            dls(adjNode, adj, visited, limit, depth + 1);
        }
    }
}

int main() {
    vector<vector<int>> adj(100);
    vector<bool> visited(100, false);

    cout << "Enter the number of nodes and edges: ";
    int node, edge;
    cin >> node >> edge;

    cout << "Enter pairs of connected nodes (node1 node2):" << endl;
    int x_connected, y_connected;
    for (int i = 0; i < edge; i++) {
        cin >> x_connected >> y_connected;
        adj[x_connected].push_back(y_connected);
        adj[y_connected].push_back(x_connected);
    }

    int startNode = 1;
    int limit;
    cout << "Enter the depth limit: ";
    cin >> limit;

    cout << "DLS traversal starting from node " << startNode << " with depth limit " << limit << ": ";

    dls(startNode, adj, visited, limit, 0);  // Calling DLS starting from node 1

    cout << endl;

    return 0;
}
