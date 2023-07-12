#include <bits/stdc++.h>
using namespace std;

int dist[50];
int solution(string begin, string target, vector<string> words) {
  int answer = 0;
  queue<int> q;
  q.push(-1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    string cur_word;
    if (cur == -1)
      cur_word = begin;
    else
      cur_word = words[cur];
    if (cur_word == target) {
      answer = dist[cur];
      break;
    }
    for (int nxt = 0; nxt < words.size(); nxt++) {
      int cnt = 0;
      for (int i = 0; i < words[nxt].size(); i++)
        if (words[nxt][i] != cur_word[i]) cnt++;
      if (dist[nxt] > 0 || cnt != 1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }
  return answer;
}