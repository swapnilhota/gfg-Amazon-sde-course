/*
Given an Undirected Graph and a node X. The task is to find the level of X from 0.
*/

class Solution {
public:
	int levelOfX(int V, vector<int> adj[], int X) {
	    vector<bool> vis(V+1, false);
	    vis[0] = true;
	    queue<pair<int, int>> q;
	    q.push(make_pair(0, 0));
	    
	    while(!q.empty())
	    {
	        int curr = q.front().first;
	        int level = q.front().second;
	        q.pop();
	        
	        if(curr==X)
	        {
	            return level;
	        }
	        
	        for(int i=0; i<adj[curr].size(); i++)
	        {
	            int next = adj[curr][i];
	            
	            if(!vis[next])
	            {
	                q.push(make_pair(next, level+1));
	                vis[next]=true;
	            }
	        }
	    }
	    
	    
	    return -1;
	}
};
