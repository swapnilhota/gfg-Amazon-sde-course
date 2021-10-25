/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
*/

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int Xor = 0;
        for(int i=0; i<n; i++)
        {
            Xor ^= arr[i];
        }
        
        for(int i=1; i<=n; i++)
        {
            Xor ^= i;
        }
        
        int x=0;
        int y=0;
        
        int set_bit = Xor & ~(Xor-1);
        
        for(int i=0; i<n; i++)
        {
            if(arr[i]&set_bit)
            {
                x ^= arr[i];
            }
            else
            {
                y ^= arr[i];
            }
        }
        
        for(int i=1; i<=n; i++)
        {
            if(i&set_bit)
            {
                x ^= i;
            }
            else
            {
                y ^= i;
            }
        }
        
        int flag=0;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i]==y)
            {
                flag=1;
                break;
            }
        }
        
        if(!flag)
        {
            swap(x, y);
        }
        
        int* res = new int[2];
        res[0] = y;
        res[1] = x;
        
        return res;
    }
};
