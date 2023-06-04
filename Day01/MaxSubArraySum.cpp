#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long curSum=0;
    long long maxSum = INT_MIN; 

    for(int i=0; i<n; i++)
    {
        curSum+=arr[i];
        if(curSum < 0){
            curSum=0;
        }
    maxSum=max(maxSum, curSum);
    }
    return maxSum;
    
}