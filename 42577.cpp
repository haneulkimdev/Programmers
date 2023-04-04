#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
  bool answer = true;
  unordered_set<string> s(phone_book.begin(), phone_book.end());
  for (auto p : phone_book) {
    string prefix = "";
    for (auto c : p) {
      prefix += c;
      if (s.find(prefix) != s.end() && prefix != p) {
        answer = false;
        break;
      }
    }
    if (!answer) break;
  }
  return answer;
}