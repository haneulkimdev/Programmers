#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
  vector<int> answer;
  int a[5] = {1, 2, 3, 4, 5};
  int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
  int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
  int cnt[3] = {};
  for (int i = 0; i < answers.size(); i++) {
    cnt[0] += answers[i] == a[i % 5];
    cnt[1] += answers[i] == b[i % 8];
    cnt[2] += answers[i] == c[i % 10];
  }

  for (int i = 0; i < 3; i++)
    if (cnt[i] == *max_element(cnt, cnt + 3)) answer.push_back(i + 1);
  return answer;
}