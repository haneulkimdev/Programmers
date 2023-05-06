#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
  vector<int> answer;
  for (int i = 1; i <= yellow; i++) {
    if (yellow % i == 0) {
      int j = yellow / i;
      if ((i + 2) * (j + 2) == brown + yellow) {
        answer.push_back(j + 2);
        answer.push_back(i + 2);
        break;
      }
    }
  }
  return answer;
}