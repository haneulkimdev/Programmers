#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
  int answer = 0;
  int w_max = 0;
  int h_max = 0;
  for (auto size : sizes) {
    if (size[0] < size[1]) swap(size[0], size[1]);
    w_max = max(w_max, size[0]);
    h_max = max(h_max, size[1]);
  }
  answer = w_max * h_max;
  return answer;
}