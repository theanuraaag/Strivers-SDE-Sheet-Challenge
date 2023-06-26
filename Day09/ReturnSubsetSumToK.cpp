void solve(vector<int> arr, int n, int k,int index,vector<vector<int>>& ans,int sum,vector<int> output){
    if(index>=n){
        if(sum == k){
            ans.push_back(output);
        }
        return;
    }
    // Take
    sum+=arr[index];
    output.push_back(arr[index]);
    solve(arr,n,k,index+1,ans,sum,output);
    // Not Take
    sum-=arr[index];
    output.pop_back();
    solve(arr,n,k,index+1,ans,sum,output);
    return;
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    int sum =0;
    vector<int> output;
    int index = 0;
    solve(arr,n,k,index,ans,sum,output);
    return ans;
}