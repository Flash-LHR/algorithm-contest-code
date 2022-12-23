#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define endl '\n'
#define sz(x) (int)x.size()
const int Ma = 1e6 + 100;

template <typename T>
inline bool cmax(T& a, const T& b) {
  return a >= b or (a = b, false);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int who = 0;
  int score[]{0, 0}, win[]{0, 0};
  string s;
  cin >> s;
  int end = false;
  for (int i = 0; i < sz(s); i++) {
    if (!end and s[i] == 'S')
      score[who]++;
    else if (!end and s[i] == 'R')
      score[who ^= 1]++;
    else {
      if (max(win[0], win[1]) >= 2) {
        cout << win[0] << (win[0] > win[1] ? " (winner) - " : " - ") << win[1]
             << (win[1] > win[0] ? " (winner)\n" : "\n");
        end = true;
        continue;
      }
      cout << win[0] << " (" << score[0] << (who == 0 ? "*)" : ")") << " - "
           << win[1] << " (" << score[1] << (who == 1 ? "*)" : ")") << endl;
      continue;
    }
    if (max(score[1], score[0]) == 10 or
        (abs(score[1] - score[0]) >= 2 and max(score[1], score[0]) >= 5))
      win[score[1] > score[0]]++, score[0] = score[1] = 0;
  }
}
