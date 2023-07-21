#include <bits/stdc++.h>
using namespace std;

bool solve(int x, vector<int> &rocks, int n) {
  int cnt = 0;
  int cur = 0;
  for (auto rock : rocks) {
    if (rock - cur < x)
      cnt++;
    else
      cur = rock;
  }
  return cnt <= n;
}

int solution(int distance, vector<int> rocks, int n) {
  rocks.push_back(distance);
  sort(rocks.begin(), rocks.end());
  int st = 1;
  int en = distance;
  while (st < en) {
    int mid = (st + en + 1) / 2;
    if (solve(mid, rocks, n)) {
      st = mid;
    } else
      en = mid - 1;
  }
  return st;
}