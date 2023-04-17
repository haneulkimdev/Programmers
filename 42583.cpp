#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  queue<int> q;
  int sum = 0;
  for (int i = 0; i < bridge_length; i++) q.push(0);
  for (auto truck_weight : truck_weights) {
    while (true) {
      answer++;
      sum -= q.front();
      q.pop();
      if (sum + truck_weight <= weight) {
        q.push(truck_weight);
        sum += truck_weight;
        break;
      } else {
        q.push(0);
      }
    }
  }
  answer += bridge_length;
  return answer;
}