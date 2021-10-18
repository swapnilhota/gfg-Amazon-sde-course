/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
*/

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int vis[m][n];
        memset(vis, 0, sizeof(vis));
        
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(make_pair(i, j), 0));
                    vis[i][j] = 1;
                }
            }
        }
        
        
        int dist[m][n];
        memset(dist, -1, sizeof(dist));
        
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            dist[r][c] = t;
            
            for(int k=0; k<4; k++)
            {
                int i = r+dr[k]; int j = c+dc[k];
                if(i>=0 && j>=0 && i<m && j<n)
                {
                    if(!vis[i][j] && grid[i][j]==1)
                    {
                        q.push(make_pair(make_pair(i, j), t+1));
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    if(dist[i][j]==-1)
                    {
                        return -1;
                    }
                    ans = max(ans, dist[i][j]);
                }
            }
        }
        
        return ans;
    }
};
