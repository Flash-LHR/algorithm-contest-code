/*************************************************************************
  > File Name: solve.cpp
  > Author: XeroxAuto
  > Mail: lanzongwei@gmail.com
  > Created Time: 2021-11-11 15:15:19
 ************************************************************************/

#define GOODOJ
#define SYNC 0

#ifdef GOODOJ
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <chrono>
#include <random>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#else
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <vector>
#include <limits>
#include <cassert>
#include <sstream>
#include <iterator>
#include <functional>
#endif
using namespace std;

#define endl '\n'
#define fep(i,b,e) for(int i=(b), i##_ = (e);i<i##_;++i)
#define rep(i,x) for(int i=0, i##_ = (x);i<i##_;++i)
#define rap(i,x) for(auto& i : (x))
#define seg(t) (t).begin(), (t).end()
#define eb emplace_back
#define ep emplace
#define mkp make_pair
#define mkt make_tuple
#define qxx(i,x) for(int i = head[x]; ~i; i = node[i].nex)
#define F first
#define S second
#define lowbit(x) ((-(x))&(x))
#define RE register
#define getchar() getchar_unlocked()
#define sz(x) (int)x.size()
#ifdef DEBUG
void err(istream_iterator<string>){}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ' ';
	err(++it, args...);
}
#define debug(args...) {string _s=#args;replace(seg(_s),',',' ');\
	cerr<<"DEBUG:";istringstream it(_s);\
	err(istream_iterator<string>(it), args);cerr<<endl;}
#else
#define debug(...)
#endif

template<typename T> inline bool cmax(T& a,const T& b) {return a<b?a=b,1:0;}
template<typename T> inline bool cmin(T& a,const T& b) {return a>b?a=b,1:0;}

#ifdef GOODOJ
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
using pq = __gnu_pbds::priority_queue<int>;
#endif
using str = std::string;
using ll = long long;
using db = double;
using pa = std::pair<int, int>;

const double P = acos(-1.0), eps = 1e-9;
struct point { db x ,y;};
inline int sign(db a) {return a < -eps ? -1 : a > eps;}
#define dot(p1,p2,p3) ((p2.x-p1.x)*(p3.x-p1.x)+(p2.y-p1.y)*(p3.y-p1.y))
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

#ifdef GOODOJ
constexpr
#else
const
#endif
int Ma = 1 << 7, inf = 0x3f3f3f3f, mod = 1e9 + 7;

#define state(x) (1ll << (x))

int f[Ma];
int a[Ma];
int lim{Ma - 1};
ll dp[64][Ma][2][2];
bool res[Ma][2][2];
bitset<63> rc;

void init() {
	rep (i, Ma)
		f[i] = __builtin_popcount(i) % 2;
}

ll dfs(int pos, bool zero, bool lim, int who, bool nj, bool jj) {
	if (pos == -1) return res[who][nj][jj];
	if (!zero and !lim and ~dp[pos][who][nj][jj]) return dp[pos][who][nj][jj];
	int up = (lim ? rc[pos] : 1);
	ll tot{0};
	for (int i = 0; i <= up; i++) {
		if (pos >= 7)
			tot += dfs(pos - 1, zero and !i, lim and i == up, who,
					   nj ^ i, i ? jj ^ 1 : 0);
		else
			tot += dfs(pos - 1, zero and !i, lim and i == up, i ? who + state(pos) : who,
					   nj, pos == 6 ? jj ^ 1 ^ nj : jj);
	}
	if (!zero and !lim) dp[pos][who][nj][jj] = tot;
	return tot;
}

ll cal(ll l) {
	memset(dp, -1, sizeof dp);
	rc = bitset<63>(l);
	return dfs(62, true, true, 0, false, false);
}

void solve() {
	int m; ll l; cin >> m >> l;
	rep (i, m) cin >> a[i];
	memset(res, 0, sizeof res);
	rep (i, Ma) {
		int nj{-1}, jj{-1};
		bool can{true};
		for (int j = 0; can and j < m; j++) {
			int now{i + j};
			if (now <= lim) {
				bool is = f[now] ^ a[j];
				if (nj == -1) nj = is;
				else can &= is == nj;
			} else {
				bool is = f[now & lim] ^ a[j];
				if (jj == -1) jj = is;
				else can &= is == jj;
			}
		}
		if (can) {
			if (jj == -1) res[i][nj][0] = res[i][nj][1] = true;
			else res[i][nj][jj] = true;
		}
	}
	cout << cal(l) << endl;
}

signed main() {
#if SYNC==0
	ios::sync_with_stdio(false);
	cin.tie(0); cout<<fixed<<setprecision(6);
#endif
	int T; cin >> T;
	init();
	while (T--) solve();

	return 0;
}

