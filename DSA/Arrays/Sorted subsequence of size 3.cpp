/*
Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.
*/

class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        int minLeft[N];
        minLeft[0] = arr[0];
        for(int i=1; i<N; i++)
        {
            minLeft[i] = min(arr[i], minLeft[i-1]);
        }
        
        int maxRight[N];
        maxRight[N-1] = arr[N-1];
        for(int i=N-2; i>=0; i--)
        {
            maxRight[i] = max(maxRight[i+1], arr[i]);
        }
        
        vector<int> res;
        for(int i=1; i<N-1; i++)
        {
            if(arr[i]>minLeft[i] && arr[i]<maxRight[i])
            {
                res.push_back(minLeft[i]);
                res.push_back(arr[i]);
                res.push_back(maxRight[i]);
                return res;
            }
        }
        return res;
    }
};
