/*
Given an array consisting of only prime numbers, remove all duplicate numbers from it. 

Example 1:

Input:
N = 6
A[] = {2,2,3,3,7,5}
Output: 2 3 7 5
Explanation: After removing the duplicate
2 and 3 we get 2 3 7 5.
Your Task:

Complete the function removeDuplicate() that takes the array of integers and N as input parameters and returns the modified array which has no duplicates. Retain only the first occurrence of the duplicate element. The elements in the returning array should be in the same order as they appear in the original array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=N=106
2<=A[i]<100
*/

class Solution{
  public:
    vector<int> removeDuplicate(vector<int>& arr, int n)
    {
        vector<int> mp(100, 0);
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(mp[arr[i]]>0)
            {
                continue;
            }
            ans.push_back(arr[i]);
            mp[arr[i]]++;
        }
        
        return ans;
    }
};
