/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.
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
