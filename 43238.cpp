#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool solve(ll x, int n, vector<int> &times) {
  ll cur = 0;
  for (auto time : times) cur += x / time;
  return cur < n;
}

ll solution(int n, vector<int> times) {
  ll st = 1;
  ll en = 1000000000000000000;
  while (st < en) {
    ll mid = (st + en) / 2;
    if (solve(mid, n, times))
      st = mid + 1;
    else
      en = mid;
  }
  return st;
}