/*
Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.
*/

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<pair<int, int>, int>> q;
	    int m = grid.size();
	    int n = grid[0].size();
	    
	    vector<vector<int>> res(m, vector<int>(n, 0));
	    
	    for(int i=0; i<m; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if(grid[i][j]==1)
	            {
	                auto p = make_pair(i, j);
	                q.push(make_pair(p, 0));
	            }
	        }
	    }
	    
	    int dr[4] = {-1, 0, 1, 0};
	    int dc[4] = {0, -1, 0, 1};
	    
	    while(!q.empty())
	    {
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        
	        for(int k=0; k<4; k++)
	        {
	            int i = r+dr[k];
	            int j = c+dc[k];
	            
	            if(i>=0 && j>=0 && i<m && j<n)
	            {
	                if(grid[i][j]!=1)
	                {
	                    res[i][j] = d+1;
	                    grid[i][j] = 1;
	                    auto p = make_pair(i, j);
	                    q.push(make_pair(p, d+1));
	                }
	            }
	        }
	    }
	    
	    return res;
	}
};
