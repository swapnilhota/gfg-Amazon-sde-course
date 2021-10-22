/*
Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
*/

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        pair<int, int> src;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    src = make_pair(i, j);
                    break;
                }
            }
        }
        
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        
        queue<pair<int, int>> q;
        q.push(src);
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(grid[r][c]==2)
            {
                return true;
            }
            if(grid[r][c]!=0)
            {
                grid[r][c]=0;
                for(int k=0; k<4; k++)
                {
                    int i = r+dr[k]; int j = c+dc[k];
                    auto p = make_pair(i, j);
                    if(i>=0 && j>=0 && i<m && j<n)
                    {
                        if(grid[i][j]!=0)
                        {
                            q.push(p);
                        }
                    }
                }
            }
        }
        
        return false;
    }
};
