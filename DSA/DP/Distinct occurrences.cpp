/*
Given two strings S and T of length n and m respectively. find count of distinct occurrences of T in S as a sub-sequence. 
*/

const int M = 1e9+7;
class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        
        long dp[m+1][n+1];
        
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(j==0)
                {
                    dp[i][j] = 1;
                }
                else if(i==0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%M;
                }
                else
                {
                    dp[i][j] = dp[i-1][j]%M;
                }
            }
        }
        
        return dp[m][n]%M;
    }
};
