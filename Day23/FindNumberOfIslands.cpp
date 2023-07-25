#include <bits/stdc++.h>

int getTotalIslands(int **arr, int n, int m)

{

  vector<vector<int>> vis(n, vector<int>(m, 0));

  int cnt = 0;

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < m; j++) {

      if (!vis[i][j] and arr[i][j]) {

        queue<pair<int, int>> q;

        cnt++;

        q.push({i, j});

        vis[i][j] = 1;

        int nrow[] = {-1, -1, -1, 0, 1, 1, 1, 0};

        int ncol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {

          int row = q.front().first;

          int col = q.front().second;

          q.pop();

          for (int i = 0; i < 8; i++) {

            int newR = row + nrow[i];

            int newC = col + ncol[i];

            if (newR >= 0 and newC >= 0 and newR < n and newC < m and

                arr[newR][newC] and !vis[newR][newC]) {

              q.push({newR, newC});

              vis[newR][newC] = 1;
            }
          }
        }
      }
    }
  }

  return cnt;
}