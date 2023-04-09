#include <bits/stdc++.h>
using namespace std;

bool cmp1(const pair<string, int> &a, const pair<string, int> &b) {
  return a.second > b.second;
}

bool cmp2(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;
  unordered_map<string, int> cnt;
  unordered_map<string, vector<pair<int, int>>> m;
  for (int i = 0; i < genres.size(); i++) {
    cnt[genres[i]] += plays[i];
    m[genres[i]].push_back({plays[i], i});
  }
  vector<pair<string, int>> v(cnt.begin(), cnt.end());
  sort(v.begin(), v.end(), cmp1);
  for (auto p : v) {
    sort(m[p.first].begin(), m[p.first].end(), cmp2);
    for (int i = 0; i < min((int)m[p.first].size(), 2); i++)
      answer.push_back(m[p.first][i].second);
  }
  return answer;
}