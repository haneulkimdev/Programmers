#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int solution(vector<int> scoville, int K) {
  int answer = 0;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (auto s : scoville) pq.push(s);
  while (pq.size() > 1 && pq.top() < K) {
    answer++;
    ll a = pq.top();
    pq.pop();
    ll b = pq.top();
    pq.pop();
    pq.push(a + b * 2);
  }
  if (pq.top() < K) answer = -1;
  return answer;
}