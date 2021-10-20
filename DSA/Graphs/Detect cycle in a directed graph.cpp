/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V+1, false);
        vector<bool> rec_stack(V+1, false);
        
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                if(dfs(adj, vis, i, rec_stack))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<int> *adj, vector<bool> &vis, int curr, vector<bool> &rec_stack)
    {
        vis[curr] = true;
        rec_stack[curr] = true;
        for(int j=0; j<adj[curr].size(); j++)
        {
            if(rec_stack[adj[curr][j]])
            {
                return true;
            }
            if(!vis[adj[curr][j]])
            {
                if(dfs(adj, vis, adj[curr][j], rec_stack))
                {
                    //cout<<curr<<" "<<adj[curr][j]<<endl;
                    return true;
                }
            }
        }
        rec_stack[curr] = false;
        
        return false;
    }
};
