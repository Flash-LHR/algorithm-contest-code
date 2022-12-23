/*************************************************************************
  > File Name: solve.cpp
  > Author: XeroxAuto
  > Mail: lanzongwei@gmail.com
  > Created Time: 2021-12-24 22:36:24
 ************************************************************************/

#define GOODOJ
#define SYNC 0

#ifdef GOODOJ
#include <bits/stdc++.h>

#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <random>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#else
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#endif
using namespace std;

#define endl '\n'
#define fep(i, b, e) for (int i = (b), i##_ = (e); i < i##_; ++i)
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; ++i)
#define rap(i, x) for (auto& i : (x))
#define seg(t) (t).begin(), (t).end()
#define eb emplace_back
#define ep emplace
#define mkp make_pair
#define mkt make_tuple
#define qxx(i, x) for (int i = head[x]; ~i; i = node[i].nex)
#define F first
#define S second
#define lowbit(x) ((-(x)) & (x))
#define RE register
#define getchar() getchar_unlocked()
#define sz(x) (int)x.size()
#ifdef DEBUG
void err(istream_iterator<string>) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ' ';
  err(++it, args...);
}
#define debug(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(seg(_s), ',', ' ');              \
    cerr << "DEBUG:";                        \
    istringstream it(_s);                    \
    err(istream_iterator<string>(it), args); \
    cerr << endl;                            \
  }
#else
#define debug(...)
#endif

template <typename T>
inline bool cmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool cmin(T& a, const T& b) {
  return a > b ? a = b, 1 : 0;
}

#ifdef GOODOJ
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
using pq = __gnu_pbds::priority_queue<int>;
#endif
using str = std::string;
using ll = long long;
using db = double;
using pa = std::pair<int, int>;

const double P = acos(-1.0), eps = 1e-9;
struct point {
  db x, y;
};
inline int sign(db a) { return a < -eps ? -1 : a > eps; }
#define dot(p1, p2, p3) \
  ((p2.x - p1.x) * (p3.x - p1.x) + (p2.y - p1.y) * (p3.y - p1.y))
#define cross(p1, p2, p3) \
  ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
  out << "{ ";
  for (auto& i : v) out << i << ' ';
  out << "} ";
  return out;
}

#ifdef GOODOJ
constexpr
#else
const
#endif
    int Ma = 1e6,
        inf = 0x3f3f3f3f, mod = 1e9 + 7;

void solve() {
	int n; cin >> n;
	str a, b; cin >> a >> b;
	if (a == b) cout << "0" << endl;
	else {
		int cb = count_if(seg(b), [] (char t) {return t == '1';});
		int ca = count_if(seg(a), [] (char t) {return t == '1';});
		cout << "ca = " << ca << " " << cb << "\n";
        if (ca != cb and n - ca + 1 != cb) return cout << "-1" << endl, void();
		int ans = inf;
		if (ca == cb) {
			int cnt{0};
			for (int i = 0; i < n; i++) if (a[i] != b[i]) ++cnt;
			cmin(ans, cnt);
		}
	   	if (n - ca + 1 == cb) {
			int cnt{1}; bool p{true};
			for (int i = 0; i < n; i++) a[i] ^= '0' ^ '1';
			for (int i = 0; i < n; i++)
				if (a[i] != b[i]) {
					++cnt;
					if (a[i] == '0' and p) --cnt, p = false;
				}
			cmin(ans, cnt);
		}
		cout << ans << endl;
	}
}

signed main() {
#if SYNC == 0
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(6);
#endif
  int t; cin >> t;
  while (t--) solve();

  return 0;
}

