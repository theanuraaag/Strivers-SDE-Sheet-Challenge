#include <bits/stdc++.h>
bool bfs(int src, vector<vector<int>> &adj, vector<int> &vis) {
  queue<pair<int, int>> q;
  q.push({src, -1});
  vis[src] = 1;
  while (!q.empty()) {
    int node = q.front().first;
    int par = q.front().second;
    q.pop();
    for (auto it : adj[node]) {
      if (!vis[it]) {
        vis[it] = 1;
        q.push({it, node});
      }

      else if (it != par)
        return true;
    }
  }
  return false;
}
bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis) {
  vis[node] = 1;
  for (auto it : adj[node]) {
    if (!vis[it]) {
      if (dfs(it, node, adj, vis))
        return true;
    } else if (it != parent)
      return true;
  }
  return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
  vector<vector<int>> adj(n + 1);
  vector<int> vis(n + 1, 0);
  for (auto it : edges) {
    int u = it[0];
    int v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    // if (!vis[i] && bfs(i, adj, vis))return "Yes";
    if (!vis[i] && dfs(i, -1, adj, vis))
      return "Yes";
  }
  return "No";
}
