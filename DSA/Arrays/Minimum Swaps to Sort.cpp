/*
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


*/

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> tmp = nums;
	    sort(tmp.begin(), tmp.end());
	    
	    map<int, int> ideal;
	    map<int, int> present;
	    
	    for(int i=0; i<nums.size(); i++)
	    {
	        present[nums[i]] = i;
	        ideal[tmp[i]] = i;
	    }
	    
	    int ans=0;
	    
	    for(int i=0; i<nums.size(); i++)
	    {
	        if(nums[i]!=tmp[i])
	        {
	            ans++;
	            swap(nums[i], nums[present[tmp[i]]]);
	            int temp = present[nums[i]];
	            present[nums[i]] = i;
	            present[nums[temp]] = temp;
	        }
	    }
	    
	    return ans;
	}
};
