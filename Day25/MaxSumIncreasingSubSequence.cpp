#include <bits/stdc++.h>

bool checkinc(vector<int> v1) {

  for (int i = 0; i < v1.size(); i++) {

    if (v1[i] > v1[i + 1] && i + 1 < v1.size()) {

      return false;
    }
  }

  return true;
}

void solve(vector<int> rack, vector<int> op, vector<vector<int>> &v, int n) {

  if (rack.size() == 0) {

    if (op.size() != 0) {

      v.push_back(op);
    }

    return;
  }

  vector<int> op1 = op;

  vector<int> op2 = op;

  op2.push_back(rack[0]);

  rack.erase(rack.begin() + 0);

  solve(rack, op1, v, n);

  solve(rack, op2, v, n);

  return;
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)

{

  // Write your code here

  vector<vector<int>> v;

  vector<int> op;

  solve(rack, op, v, n);

  int maxi = INT_MIN;

  for (int i = 0; i < v.size(); i++) {

    int sum = 0;

    if (checkinc(v[i])) {

      for (int j = 0; j < v[i].size(); j++) {

        if (v[i][j] == v[i][j + 1] && j + 1 < v[i].size()) {

          sum = sum + v[i][j];

          break;
        }

        sum = sum + v[i][j];


      }
    }

    if (sum > maxi) {

      maxi = sum;
    }
  }

  return maxi;
}