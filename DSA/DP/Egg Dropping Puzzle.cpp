/*
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.
*/

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        int dp[n+1][k+1];
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                if(i==1)
                {
                    dp[i][j] = j;
                }
                else if(j==0 || j==1)
                {
                    dp[i][j] = j;
                }
            }
        }
        
        for(int i=2; i<=n; i++)
        {
            for(int j=2; j<=k; j++)
            {
                int low = 1;
                int high = j;
                
                int ans = INT_MAX;
                
                while(low<=high)
                {
                    int mid = (high-low)/2+low;
                    
                    int left = dp[i-1][mid-1];
                    int right = dp[i][j-mid];
                    
                    ans = min(ans, 1+max(left, right));
                    
                    if(left>right)
                    {
                        high=mid-1;
                    }
                    else
                    {
                        low=mid+1;
                    }
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[n][k];
    }
};
