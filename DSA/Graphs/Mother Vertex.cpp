/*
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
*/

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> path;
	    vector<bool> vis(V+1, false);
	    for(int i=0; i<V; i++)
	    {
	        if(!vis[i])
	        {
	            dfs(adj, vis, path, i);
	        }
	    }
	    reverse(path.begin(), path.end());
	    int mother = path[0];
	    
	    vector<bool> final_vis(V+1, false);
	    path.clear();
	    dfs(adj, final_vis, path, mother);
	    
	    for(int i=0; i<V; i++)
	    {
	        if(!final_vis[i]) return -1;
	    }
	    
	    return mother;
	}
	
	void dfs(vector<int>* adj, vector<bool> &vis, vector<int> &path, int curr)
	{
	    vis[curr]=true;
	    
	    for(int i=0; i<adj[curr].size(); i++)
	    {
	        if(!vis[adj[curr][i]])
	        {
	            dfs(adj, vis, path, adj[curr][i]);
	        }
	    }
	    
	    path.push_back(curr);
	}

};
