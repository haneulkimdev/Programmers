#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= m; }

int dist[100][100];

int solution(vector<vector<int>> maps) {
  n = maps.size();
  m = maps[0].size();
  queue<pair<int, int>> q;
  q.push({0, 0});
  dist[0][0] = 1;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (cur.X == n - 1 && cur.Y == m - 1) return dist[cur.X][cur.Y];
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || dist[nx][ny] > 0 || maps[nx][ny] == 0) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      q.push({nx, ny});
    }
  }
  return -1;
}