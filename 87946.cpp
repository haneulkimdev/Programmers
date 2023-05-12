#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
  int answer = -1;
  sort(dungeons.begin(), dungeons.end());
  do {
    int cnt = 0;
    int val = k;
    for (auto dungeon : dungeons) {
      if (val < dungeon[0]) continue;
      cnt++;
      val -= dungeon[1];
    }
    answer = max(answer, cnt);
  } while (next_permutation(dungeons.begin(), dungeons.end()));
  return answer;
}