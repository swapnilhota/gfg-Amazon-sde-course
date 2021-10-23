/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.
*/

class Solution{
    public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    
    void dfs(vector<vector<int>> &grid, int n, int r, int c, vector<string> &ans, vector<vector<int>> &vis, string path)
    {
        if(grid[r][c]==0)
        {
            return;
        }
        if(r==n-1 && c==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        vis[r][c]=1;
        
        for(int k=0; k<4; k++)
        {
            int i=r+dr[k];
            int j=c+dc[k];
            
            if(i>=0 && j>=0 && i<n && j<n)
            {
                if(!vis[i][j])
                {
                    char move;
                    switch(k)
                    {
                        case 0:
                            //up
                            move='U';
                            break;
                        case 1:
                            move='L';
                            break;
                        case 2:
                            move='D';
                            break;
                        case 3:
                            move='R';
                            break;
                    }
                    
                    dfs(grid, n, i, j, ans, vis, path+move);
                }
            }
        }
        
        vis[r][c]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        dfs(m, n, 0, 0, ans, vis, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};
