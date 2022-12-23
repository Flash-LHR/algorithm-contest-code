#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define endl '\n'
#define ep emplace_back
#define sz(x) (int)x.size()
using ll = long long;
const int Ma = 1e3 + 100;

template <typename T>
inline bool cmax(T& a, const T& b) {
  return a >= b or (a = b, false);
}

ll a[Ma];

int now;

namespace PD {
typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll mul(ll a, ll b, ll p) {
  return (a * b - (ll)((long double)a / p * b) * p + p) % p;
}

ll quick(ll a, ll b, ll p) {
  ll s = 1;
  while (b) {
    if (b & 1) s = mul(s, a, p);
    a = mul(a, a, p);
    b >>= 1;
  }
  return s;
}

bool Miller_Rabin(ll n, int c = 20) {
  if (n == 2) return 1;
  if (n < 2 || !(n & 1)) return 0;
  srand(time(NULL));
  ll m = n - 1, k = 0;
  while (!(m & 1)) k++, m >>= 1;
  ll a, x, y;
  for (int i = 1; i <= c; ++i) {
    a = rand() % (n - 1) + 1;
    x = quick(a, m, n);
    for (int j = 1; j <= k; ++j) {
      y = mul(x, x, n);
      if (y == 1 && x != 1 && x != n - 1) return 0;
      x = y;
    }
    if (y != 1) return 0;
  }
  return 1;
}

ll f(ll x, ll c, ll n) { return (mul(x, x, n) + c) % n; }

int Rand() { return rand() << 15 ^ rand(); }

ll llRand() { return (ll)Rand() << 30 ^ Rand(); }

ll Pollard_Rho(ll n) {
  ll s = 0, t = 0, c = llRand() % (n - 1) + 1, val = 1, d;
  for (int i = 1;; i *= 2, s = t, val = 1) {
    for (int j = 1; j <= i; ++j) {
      t = f(t, c, n);
      val = mul(val, t > s ? t - s : s - t, n);
      if (!(j & 127)) {
        d = gcd(val, n);
        if (d > 1) return d;
      }
    }
    d = gcd(val, n);
    if (d > 1) return d;
  }
}

set<ll> prim;
void div(ll n) {
  if (Miller_Rabin(n)) {
    prim.insert(n);
    return;
  }
  ll p = n;
  while (p >= n) p = Pollard_Rho(n);
  while (n % p == 0) n /= p;
  if (n > 1) div(n);
  if (p > 1) div(p);
}
}  // namespace PD

using PD::div;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int m, n, k;
  cin >> m >> n >> k;
  now = m;
  rep(i, n) cin >> a[i], div(a[i]);
  rep(i, m) {
    int u, v, d;
    cin >> u >> v >> d;
  }
  /*memset(mat, -1, sizeof mat);
  int len = 0;
  for (int i = 0; memset(mz, 0, sizeof mz), i < now; i++)
        len += find(i);
  assert(len == now);
  sort(mat, mat + m, [&] (int a, int b) {
                        return prim[a - m] < prim[b - m];
                  });
  rep (i, m) cout << prim[mat[i] - m] << ' ';*/
  rap(i, PD::prim) cout << i << ' ';
  cout << endl;
}
