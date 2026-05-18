#include <bits/stdc++.h>
using namespace std;

class GraphDFS {
    map<int, bool> visited;
    map<int, list<int>> adj;

    // Utility function for DFS
    void DFSUtil(int v);

public:
    void addEdge(int v, int w);
    void DFS();
};

void GraphDFS::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list
}

void GraphDFS::DFSUtil(int v) {
    visited[v] = true;
    cout << v << " ";

    for (auto i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(i);
        }
    }
}

// Function to do DFS traversal for the complete graph
void GraphDFS::DFS() {
    for (auto i : adj) {
        if (!visited[i.first]) {
            DFSUtil(i.first);
        }
    }
}

// Driver code
int main() {
    GraphDFS g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    cout << "Following is Depth First Traversal:\n";
    g.DFS();

    return 0;
}
