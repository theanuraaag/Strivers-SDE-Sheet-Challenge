#include <bits/stdc++.h>

bool satisfy(int row, int col, vector<vector<int>> &matrix, int n) {

  for (int r = 0; r < row; r++) {

    if (matrix[r][col] == 1)
      return false;
  }

  int c = col;

  int r = row;

  while (c >= 0 && r >= 0) {

    if (matrix[r][c] == 1)
      return false;

    c--;

    r--;
  }

  r = row;

  c = col;

  while (r >= 0 && c < n) {

    if (matrix[r][c] == 1)
      return false;

    r--;

    c++;
  }

  return true;
}

void solve(int row, int n, vector<vector<int>> &matrix,
           vector<vector<int>> &ans)

{

  if (row == n) {

    vector<int> temp;

    for (int i = 0; i < n; i++) {

      for (int j = 0; j < n; j++) {

        temp.push_back(matrix[i][j]);
      }
    }

    ans.push_back(temp);

    return;
  }

  for (int col = 0; col < n; col++) {

    if (satisfy(row, col, matrix, n)) {

      matrix[row][col] = 1;

      solve(row + 1, n, matrix, ans);

      matrix[row][col] = 0;
    }
  }
}

vector<vector<int>> solveNQueens(int n) {

  vector<vector<int>> matrix(n, vector<int>(n, 0));

  vector<vector<int>> ans;

  solve(0, n, matrix, ans);

  return ans;

  // Write your code here.
}