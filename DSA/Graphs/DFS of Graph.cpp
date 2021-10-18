/*
Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..
*/

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V+1, false);
        vector<int> res;
        dfs(adj, 0, vis, res);
        return res;
    }
    
    void dfs(vector<int>* adj, int curr, vector<bool> &vis, vector<int> &res)
    {
        vis[curr] = true;
        res.push_back(curr);
        
        for(int i=0; i<adj[curr].size(); i++)
        {
            if(!vis[adj[curr][i]])
            {
                dfs(adj, adj[curr][i], vis, res);
            }
        }
    }
};
