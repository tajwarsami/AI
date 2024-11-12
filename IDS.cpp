#include <bits/stdc++.h>
using namespace std;


bool dls(int node, vector<vector<int>>& adj, vector<bool>& visited, int limit, int depth) {
    if (depth > limit) return false;

    cout << node << " ";
    visited[node] = true;

    for (int adjNode : adj[node]) {
        if (!visited[adjNode]) {
            if (dls(adjNode, adj, visited, limit, depth + 1)) {
                return true;
            }
        }
    }

    return false;
}


void ids(int startNode, vector<vector<int>>& adj, int maxDepth) {
    for (int limit = 0; limit <= maxDepth; ++limit) {
        cout << "\nDepth " << limit << ": ";
        vector<bool> visited(100, false);
        dls(startNode, adj, visited, limit, 0);
    }
}

int main() {
    vector<vector<int>> adj(100);

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
    int maxDepth;
    cout << "Enter the maximum depth limit for IDS: ";
    cin >> maxDepth;

    cout << "IDS traversal starting from node " << startNode << " up to depth " << maxDepth << ":";

    ids(startNode, adj, maxDepth);

    cout << endl;

    return 0;
}
