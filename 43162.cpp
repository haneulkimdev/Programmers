#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
  int answer = 0;
  vector<bool> vis(n);
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    answer++;
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nxt = 0; nxt < computers[cur].size(); nxt++) {
        if (vis[nxt] || computers[cur][nxt] == 0) continue;
        q.push(nxt);
        vis[nxt] = true;
      }
    }
  }
  return answer;
}