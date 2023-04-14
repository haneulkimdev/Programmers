#include <bits/stdc++.h>
using namespace std;

bool solution(string s) {
  bool answer = true;
  stack<char> st;
  for (auto c : s) {
    if (c == '(') {
      st.push(c);
    } else if (c == ')') {
      if (st.empty() || st.top() != '(') {
        answer = false;
        break;
      }
      st.pop();
    }
  }
  if (!st.empty()) answer = false;
  return answer;
}