/*
Given a Directed Graph. Count the total number of ways or paths that exist between two vertices in the directed graph. These paths doesn’t contain any cycle.
Note: Graph doesn't contain multiple edges, self loop and cycles and the two vertices( source and destination) are denoted in the example.
*/

class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        int ans=0;
        dfs(adj, source, destination, ans);
        return ans;
    }
    
    void dfs(vector<int>* &adj, int curr, int dest, int &ans)
    {
        if(curr==dest)
        {
            ans++;
            return;
        }
        
        for(int i=0; i<adj[curr].size(); i++)
        {
            int next = adj[curr][i];
            dfs(adj, next, dest, ans);
        }
    }
};
