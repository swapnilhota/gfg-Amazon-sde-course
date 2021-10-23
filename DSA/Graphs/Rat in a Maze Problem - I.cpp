/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.
*/

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    pair<int, int> src = make_pair(KnightPos[1]-1, KnightPos[0]-1);
	    pair<int, int> dest = make_pair(TargetPos[1]-1, TargetPos[0]-1);
	    
	    vector<vector<int>> grid(N, vector<int>(N, 0));
	    
	    queue<pair<pair<int, int>, int>> q;
	    
	    int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	    int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	    
	    q.push(make_pair(src, 0));
	    
	    while(!q.empty())
	    {
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int moves = q.front().second;
	        q.pop();
	        
	        auto curr_pair = make_pair(r, c);
	        if(curr_pair == dest)
	        {
	            return moves;
	        }
	        
	        for(int k=0; k<8; k++)
	        {
	            int i = r+dr[k];
	            int j = c+dc[k];
	            
	            if(i>=0 && j>=0 && i<N && j<N)
	            {
	                if(grid[i][j]!=1)
	                {
	                    auto p = make_pair(i, j);
	                    q.push(make_pair(p, moves+1));
	                    grid[i][j]=1;
	                }
	            }
	        }
	    }
	    
	    return -1;
	}
};
