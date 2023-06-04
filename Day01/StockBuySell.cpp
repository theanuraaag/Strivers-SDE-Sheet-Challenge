#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    int temp[n];
    temp[n-1]=prices[n-1];

    for(int i=n-2;i>=0;i--)
    {
        temp[i]=max(temp[i+1],prices[i]);
    }
    int profit=0;

    for(int i=0;i<n;i++)
    {
        profit=max(profit,temp[i]-prices[i]);
    }
    return profit;
}