#include <bits/stdc++.h>

class Compare{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b){
            return (a.second > b.second);
        }
};

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{

    vector<vector<pair<int, int>>> adj(n + 1);
    for(auto edge : g){
        adj[edge.first.first].push_back(make_pair(edge.first.second, edge.second));
        adj[edge.first.second].push_back(make_pair(edge.first.first, edge.second));
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> minHeap;
    vector<int> key(n + 1, INT_MAX);
    
    vector<bool> mst(n + 1, false);
    
    vector<int> parent(n + 1, -1);
    
    key[1] = 0;
    minHeap.push(make_pair(1, 0));
    for(int i = 0; i < n; i++){
        
        while(mst[minHeap.top().first]) minHeap.pop();
        int u = minHeap.top().first;
        minHeap.pop();
        
        mst[u] = true;
     
        for(auto neighbour : adj[u]){
            if(!mst[neighbour.first] && key[neighbour.first] > neighbour.second){
                key[neighbour.first] = neighbour.second;
                parent[neighbour.first] = u;
            }
            minHeap.push(make_pair(neighbour.first, neighbour.second));
        } 
    }
    vector<pair<pair<int,int>,int>> ans;
    for(int i = 2; i <= n; i++){
        ans.push_back(make_pair(make_pair(i, parent[i]),key[i]));
        
    }
    return ans;
}