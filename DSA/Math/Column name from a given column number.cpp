/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on
*/

class Solution{
    public:
    string colName (long long int n)
    {
        string ans="";
        while(n)
        {
            int rem = n%26;
            n /= 26;
            if(rem==0)
            {
                ans += 'Z';
                n--;
                if(n==0)
                {
                    break;
                }
            }
            else
            {
                ans += (char)('A'+rem-1); 
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
