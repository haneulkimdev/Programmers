#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> babbling) {
  int answer = 0;
  string arr[4] = {"aya", "ye", "woo", "ma"};
  for (auto b : babbling) {
    if (b.find("ayaaya") != string::npos || b.find("yeye") != string::npos ||
        b.find("woowoo") != string::npos || b.find("mama") != string::npos)
      continue;
    for (int i = 0; i < 4; i++) {
      while (true) {
        auto it = b.find(arr[i]);
        if (it == string::npos) break;
        b.replace(it, arr[i].size(), " ");
      }
    }
    while (true) {
      auto it = b.find(" ");
      if (it == string::npos) break;
      b.replace(it, 1, "");
    }
    answer += b.empty();
  }
  return answer;
}