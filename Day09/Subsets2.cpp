#include <bits/stdc++.h>

void findSubs(int index, vector<int> &arr, vector<int> &ds,
              vector<vector<int>> &res) {

  res.push_back(ds);

  for (int i = index; i < arr.size(); i++) {

    if (i != index and arr[i] == arr[i - 1]) {
      continue;
    }

    ds.push_back(arr[i]);

    findSubs(i + 1, arr, ds, res);

    ds.pop_back();
  }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr) {

  vector<int> ds;
  vector<vector<int>> res;

  sort(arr.begin(), arr.end());
  findSubs(0, arr, ds, res);

  return res;
}