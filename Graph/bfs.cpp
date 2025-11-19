#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<int> adj[], int n) {
    vector<bool> vis(n+1, false);
    queue<int> q;

    q.push(start);
    vis[start] = true;

    cout << "BFS: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int child : adj[node]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    // Input graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    bfs(1, adj, n); // start from node 1
}
