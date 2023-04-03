#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";
  unordered_map<string, int> m;
  for (auto p : participant) m[p]++;
  for (auto c : completion) m[c]--;
  for (auto e : m) {
    if (e.second == 1) {
      answer = e.first;
      break;
    }
  }
  return answer;
}