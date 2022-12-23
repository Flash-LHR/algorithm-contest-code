#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define endl '\n'
#define sz(x) (int)x.size()
const int Ma = 42;

template <typename T>
inline bool cmax(T& a, const T& b) {
  return a >= b or (a = b, false);
}

char mz[Ma][Ma];
int have[Ma][Ma];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m; cin >> n >> m;
  int xz[] = {1, 0, 1, 1},
	  yz[] = {0, 1, 1, -1};
  auto ck = [&] (int r, int c) {
	  return r >= 0 and r < n and c >= 0 and c < m;
  };
  rep (i, n) cin >> mz[i];
  int q; cin >> q;
  while (q--) {
	  string s; cin >> s;
	  unordered_multiset<char> a;
	  rap (i, s) a.emplace(i);
	  rep (i, n) rep (j, m) {
		  rep (ii, 4) {
	      	unordered_multiset<char> b;
			int r = i, c = j;
		  	rep (k, sz(s)) {
				if (!ck(r, c)) break;
				b.emplace(mz[r][c]);
				r += xz[ii], c += yz[ii];
			}
			if (b.size() == s.size() and b == a) {
				r = i, c = j;
				rep (k, sz(s)) {
					have[r][c] |= 1 << q;
					r += xz[ii], c += yz[ii];
				}
			}
		  }
	  }
  }
  int ans{0};
  rep (i, n) rep (j, m) if (__builtin_popcount(have[i][j]) > 1)
	  ++ans;
  cout << ans << endl;
}
