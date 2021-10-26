/*
A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded, as the answer can be large return the answer modulo 109 + 7.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.
*/

class Solution {
	public:
	    const int M = 1e9+7;
		int CountWays(string str){
		    if(str[0]=='0') return 0;
		    vector<int> dp(str.length()+1, -1);
		    int ans = solve(str, str.length(), dp);
		    return ans%M;
		}
		
		bool valid(string s)
		{
		    int num = stoi(s);
		    string temp = to_string(num);
		    if(temp.length()!=s.length())
		    {
		        return false;
		    }
		    if(num<1 || num>26)
		    {
		        return false;
		    }
		    return true;
		}
		
		int solve(string &str, int n, vector<int> &dp)
		{
		    if(n==0 || n==1)
		    {
		        return 1;
		    }
		    if(str[0]=='0')
		    {
		        return 0;
		    }
		    if(dp[n]!=-1)
		    {
		        return dp[n];
		    }
		    
		    int ans = 0;
		    
		    if(str[n-1]!='0')
		    {
		        ans += solve(str, n-1, dp);
		    }
		    if(valid(str.substr(n-2, 2)))
		    {
		        ans += solve(str, n-2, dp);
		    }
		    
		    return dp[n] = ans%M;
		}

};
