int help(int idx, vector<int>&price, int target, vector<vector<int>>&dp){

    if(idx == 0){

        return (target/(idx+1))*price[0];

    } 

    if(dp[idx][target]!=-1) return dp[idx][target];

    int notpick = help(idx-1,price,target,dp);

    int pick = 0;

    if(idx+1 <=target)

    pick = price[idx] + help(idx,price,target-(idx+1),dp);

    return dp[idx][target] = max(pick,notpick);

}

int cutRod(vector<int> &price, int n)

{

    vector<vector<int>>dp(n,vector<int>(n+1,-1));

    return help(n-1,price,n,dp);

}