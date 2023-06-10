#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
   vector<vector<int>> ans;

   for(int i=0;i<arr.size();i++)
   {
      for(int j=0;j<arr.size();j++)
      {
         if(arr[i]+arr[j]==s)
         {
            vector<int> v;
            v.push_back(min(arr[i],arr[j]));
            v.push_back(max(arr[i],arr[j]));
            ans.push_back(v);
            arr[j]=100001;
         }
      }
   }
   sort(ans.begin(),ans.end());
   return(ans);
}