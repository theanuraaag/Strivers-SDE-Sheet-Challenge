#include <bits/stdc++.h> 

bool isSafe(string &s, int start , int end){

    while (start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

void solve(int index , string &s, vector<string> &curr , vector<vector<string>> &res){

   
    if(index == s.size()){
        res.push_back(curr);
        return;
    }

    for(int i = index; i < s.size(); i++){
        if(isSafe(s, index ,i)){
            curr.push_back(s.substr(index , i - index + 1));
            solve(i+1, s, curr, res);
            curr.pop_back();
        }
    }

}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> res;
    vector<string> curr;

    solve(0 , s , curr , res);

    return res;
}