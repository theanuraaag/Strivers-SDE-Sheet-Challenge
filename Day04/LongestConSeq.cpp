#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
  // Write your code here.
  int lastNum = INT_MIN;

  int count = 0, ans = 0;

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n; i++) {

    if (arr[i] - 1 == lastNum) {

      count += 1;

      lastNum = arr[i];

    }

    else if (arr[i] != lastNum) {

      count = 1;

      lastNum = arr[i];
    }

    if (count > ans) {

      ans = count;
    }
  }

  return ans;
}