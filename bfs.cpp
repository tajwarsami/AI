#include <bits/stdc++.h>
using namespace std;

int main() {
    bool visited[100] = {false};
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

    queue<int> q;
    int startNode = 1;
    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS traversal starting from node " << startNode << ": ";
    while (!q.empty()) {
        int currentNode = q.front();
        cout << currentNode << " ";
        q.pop();

        for (int adjNode : adj[currentNode]) {
            if (!visited[adjNode]) {
                visited[adjNode] = true;
                q.push(adjNode);
            }
        }
    }
    cout << endl;

    return 0;
}
