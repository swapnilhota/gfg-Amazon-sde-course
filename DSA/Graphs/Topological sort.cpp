/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> res;
	    vector<bool> vis(V+1, false);
	    for(int i=0; i<V; i++)
	    {
	        if(!vis[i])
	        {
	            dfs(adj, i, vis, res);
	        }
	    }
	    reverse(res.begin(), res.end());
	    return res;
	}
	
	void dfs(vector<int>* adj, int curr, vector<bool> &vis, vector<int> &res)
	{
	    vis[curr]=true;
	    for(int i=0; i<adj[curr].size(); i++)
	    {
	        int next = adj[curr][i];
	        if(!vis[next])
	        {
	            dfs(adj, next, vis, res);
	        }
	    }
	    res.push_back(curr);
	}
};
