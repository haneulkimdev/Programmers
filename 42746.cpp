#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b) { return a + b > b + a; }

string solution(vector<int> numbers) {
  string answer = "";
  vector<string> v;
  for (auto number : numbers) v.push_back(to_string(number));
  sort(v.begin(), v.end(), cmp);
  for (auto s : v) answer += s;
  if (answer[0] == '0') answer = "0";
  return answer;
}