#include <algorithm>

string longestCommonPrefix(vector<string> &arr, int n)

{

    string ans = "";

    sort(arr.begin(), arr.end());

    string first = arr[0], last = arr[n - 1];

    for (int i = 0; i < first.size(); i++)
    {

        if (first[i] != last[i])
            return ans;

        ans = ans + first[i];
    }

    return ans;

    // Write your code here
}