/*
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Example 1:

Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9
Example 2:

Input:
N = 10
arr[] = {10 9 8 7 6 5 4 3 2 1}
Output:
1 2 3 4 5 6 7 8 9 10

Your Task:
You don't need to take the input or print anything. Your task is to complete the function merge() which takes arr[], l, m, r as its input parameters and modifies arr[] in-place such that it is sorted from position l to position r, and function mergeSort() which uses merge() to sort the array in ascending order using merge sort algorithm.

Expected Time Complexity: O(nlogn) 
Expected Auxiliary Space: O(n)

Constraints:
1 <= N <= 105
1 <= arr[i] <= 103
*/

class Solution
{
    public:
    void merge(int* arr, int l, int m, int r)
    {
         vector<int> tmp;
         int i=l;
         int j=m+1;
         while(i<=m && j<=r)
         {
             if(arr[i]<arr[j])
             {
                tmp.push_back(arr[i]);
                i++;
             }
             else
             {
                 tmp.push_back(arr[j]);
                 j++;
             }
         }
         
         while(i<=m)
         {
             tmp.push_back(arr[i]);
             i++;
         }
         
         while(j<=r)
         {
             tmp.push_back(arr[j]);
             j++;
         }
         
         for(int x=0; x<tmp.size(); x++)
         {
             arr[l+x] = tmp[x];
         }
    }
    public:
    void mergeSort(int* arr, int l, int r)
    {
        if(l<r)
        {
            int mid = (r-l)/2+l;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }
};
