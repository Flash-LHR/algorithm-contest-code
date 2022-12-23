#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define endl '\n'
#define sz(x) (int)x.size()
using ll = long long;
const int Ma = 55;

template <typename T>
inline bool cmax(T& a, const T& b) {
  return a >= b or (a = b, false);
}

//multiset<ll> s[Ma];
ll a[Ma];

/*void dfs(int l, int r, int k, int cnt, ll now) {
	if (l > r) {
		s[cnt].emplace(now);
		return ;
	}
	dfs(l, r, k, cnt, now);
	if (cnt < k)
		dfs(l + 1, r, k, cnt + 1, now + a[l]);
}*/

ll C(ll n, ll m) {
	if (m > n) return 0;
	__int128 s = 1; 
	if (m * 2 < n) m = n - m;
	for (ll i = n, j = 2; i > n - m; i--) {
		s *= i;
		while (s % j == 0 and j <= m) s /= j, ++j;
	}
	//cerr << "s == " << s << ' ' << n << ' ' << m << endl;
	//for (ll j = 2; j <= m; j++) s /= j;
	return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k; cin >> n >> k;
  /*for (int x = 3, c, r; c = x & -x, r = x + c, __lg(x) < 4;
	   x = ((((r ^ x) >> 2) / c) | r)) {
		   cerr << bitset<5>(x) << endl;
	   }*/
  //ll tot = 0, ans = 0;
  rep (i, n) cin >> a[i];//, tot += a[i];
  ll A, B;
  cin >> A >> B;
  sort(a, a + n);
  function<ll(ll, int, int)> cal = [&] (ll x, int r, int k) -> ll {
	  if (k == 0) return x >= 0;
	  auto nxt = upper_bound(a, a + r, x);
	  if (nxt == a) return 0;
	  --nxt;
	  return C(nxt - a, k) + cal(x - *nxt, nxt - a, k - 1);
  };
  cout << cal(B, n, k) - cal(A - 1, n, k) << endl;
}
