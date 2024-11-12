#include <bits/stdc++.h>
using namespace std;


void ucs(int startNode, int goalNode, vector<vector<pair<int, int>>>& adj, int n) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[startNode] = 0;

    pq.push({0, startNode});

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();


        if (currentNode == goalNode) {
            cout << "Minimum cost from node " << startNode << " to node " << goalNode << " is: " << currentCost << endl;
            return;
        }


        for (auto& neighbor : adj[currentNode]) {
            int adjNode = neighbor.first;
            int edgeCost = neighbor.second;


            int newCost = currentCost + edgeCost;
            if (newCost < dist[adjNode]) {
                dist[adjNode] = newCost;
                pq.push({newCost, adjNode});
            }
        }
    }

    cout << "No path from node " << startNode << " to node " << goalNode << endl;
}

int main() {
    int n, edge;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> edge;

    vector<vector<pair<int, int>>> adj(n);

    cout << "Enter edges with costs (node1 node2 cost):" << endl;
    for (int i = 0; i < edge; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        adj[x].push_back({y, cost});
        adj[y].push_back({x, cost});
    }

    int startNode, goalNode;
    cout << "Enter the start and goal nodes: ";
    cin >> startNode >> goalNode;

    ucs(startNode, goalNode, adj, n);

    return 0;
}

