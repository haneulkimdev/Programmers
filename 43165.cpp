#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int solution(vector<int> numbers, int target) {
  int answer = 0;
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (cur.Y == numbers.size()) {
      if (cur.X == target) answer++;
      continue;
    }
    for (int nxt : {numbers[cur.Y], -numbers[cur.Y]})
      q.push({cur.X + nxt, cur.Y + 1});
  }
  return answer;
}