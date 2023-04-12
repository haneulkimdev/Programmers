#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  queue<int> q;
  for (int i = 0; i < progresses.size(); i++) {
    int day = (100 - progresses[i]) / speeds[i];
    if ((100 - progresses[i]) % speeds[i] != 0) day++;
    q.push(day);
  }
  while (!q.empty()) {
    int cnt = 1;
    int cur = q.front();
    q.pop();
    while (!q.empty() && q.front() <= cur) {
      cnt++;
      q.pop();
    }
    answer.push_back(cnt);
  }
  return answer;
}