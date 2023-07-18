#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[102][102];
int dist[102][102];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
  int answer = 0;
  for (auto r : rectangle) {
    int x1 = r[0] * 2, y1 = r[1] * 2, x2 = r[2] * 2, y2 = r[3] * 2;
    for (int i = x1; i <= x2; i++)
      for (int j = y1; j <= y2; j++) board[i][j] = 1;
  }
  for (auto r : rectangle) {
    int x1 = r[0] * 2 + 1, y1 = r[1] * 2 + 1, x2 = r[2] * 2 - 1, y2 = r[3] * 2 - 1;
    for (int i = x1; i <= x2; i++)
      for (int j = y1; j <= y2; j++) board[i][j] = 0;
  }
  queue<pair<int, int>> q;
  q.push({characterX * 2, characterY * 2});
  dist[characterX * 2][characterY * 2] = 1;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (cur.X == itemX * 2 && cur.Y == itemY * 2) {
      answer = dist[cur.X][cur.Y] / 2;
      break;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (dist[nx][ny] > 0 || board[nx][ny] == 0) continue;
      q.push({nx, ny});
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
    }
  }
  return answer;
}