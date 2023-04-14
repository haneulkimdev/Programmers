#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  int n = id_list.size();
  vector<int> answer(n);
  map<string, int> s2i;
  for (int i = 0; i < n; i++) s2i[id_list[i]] = i;
  set<int> s[1000];
  for (auto r : report) {
    stringstream ss(r);
    string id1, id2;
    ss >> id1 >> id2;
    s[s2i[id2]].insert(s2i[id1]);
  }
  for (int i = 0; i < n; i++) {
    if (s[i].size() < k) continue;
    for (auto x : s[i]) answer[x]++;
  }
  return answer;
}