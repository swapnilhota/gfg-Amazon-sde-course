/*
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
*/

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int ans=0;
	    vector<long> dist(n+1, INT_MAX);
	    dist[0] = 0;
	    for(int i=0; i<n-1; i++)
	    {
	        for(auto edge: edges)
	        {
	            int u = edge[0];
	            int v = edge[1];
	            int wt = edge[2];
	            
	            if(dist[v] > dist[u]+wt)
	            {
	                dist[v] = dist[u]+wt;
	            }
	        }
	    }
	    
	    for(int i=0; i<n-1; i++)
	    {
	        for(auto edge: edges)
	        {
	            int u = edge[0];
	            int v = edge[1];
	            int wt = edge[2];
	            
	            if(dist[v] > dist[u]+wt)
	            {
	                return 1;
	            }
	        }
	    }
	    
	    return 0;
	}
};
