void dfs(vector<int> adj[], vector<int> &vis, int node, vector<int> &temp)
{

    vis[node] = 1;

    temp.push_back(node);

    for (auto it : adj[node])
    {

        if (!vis[it])
        {

            dfs(adj, vis, it, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    // Write your code here

    vector<vector<int>> ans;

    vector<int> adj[V];

    for (int i = 0; i < edges.size(); i++)
    {

        adj[edges[i][0]].push_back(edges[i][1]);

        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> vis(V);

    for (int i = 0; i < V; i++)
    {

        if (!vis[i])
        {

            vector<int> temp;

            dfs(adj, vis, i, temp);

            ans.push_back(temp);
        }
    }

    return ans;
}