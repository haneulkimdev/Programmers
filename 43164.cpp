#include <bits/stdc++.h>
using namespace std;

bool func(string cur, int cnt, vector<vector<string>> &tickets,
          vector<string> &answer, vector<bool> &is_used) {
  if (cnt == tickets.size()) return true;
  for (int i = 0; i < tickets.size(); i++) {
    if (is_used[i] || tickets[i][0] != cur) continue;
    answer.push_back(tickets[i][1]);
    is_used[i] = true;
    if (func(tickets[i][1], cnt + 1, tickets, answer, is_used)) return true;
    is_used[i] = false;
  }
  answer.pop_back();
  return false;
}

vector<string> solution(vector<vector<string>> tickets) {
  vector<string> answer;
  vector<bool> is_used(tickets.size());
  sort(tickets.begin(), tickets.end());
  answer.push_back("ICN");
  func("ICN", 0, tickets, answer, is_used);
  return answer;
}