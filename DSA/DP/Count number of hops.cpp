/*
A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. As the answer will be large find the answer modulo 1000000007.
*/

const int M = 1e9+7;
int dp[1000001];
class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
    
    long long helper(int n)
    {
        if(n<0) return 0LL;
        if(n==0) return 1LL;
        if(n==1) return 1LL;
        if(n==2) return 2LL;
        
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        
        long long a1 = helper(n-1);
        long long a2 = helper(n-2);
        long long a3 = helper(n-3);
        
        return dp[n] = (a1+a2+a3)%M;
    }
};
