#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int solution(vector<int> priorities, int location) {
  int answer = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < priorities.size(); i++) q.push({priorities[i], i});
  sort(priorities.begin(), priorities.end(), greater<int>());
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (cur.X == priorities[answer]) {
      answer++;
      if (cur.Y == location) break;
    } else {
      q.push(cur);
    }
  }
  return answer;
}