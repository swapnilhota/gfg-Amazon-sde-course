/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        q.push(0);
        vector<int> res;
        vector<bool> visited(V+1, false);
        visited[0]=true;
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            res.push_back(curr);
            for(int i=0; i<adj[curr].size(); i++)
            {
                if(visited[adj[curr][i]]) continue;
                q.push(adj[curr][i]);
                visited[adj[curr][i]]=true;
            }
        }
        return res;
    }
};
