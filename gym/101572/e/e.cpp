#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = double;
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define ep emplace_back
#define mkp make_pair
#define mkt make_tuple
#define lowbit(x) ((x)&(-(x)))
#define seg(x) x.begin(), x.end()
#define rseg(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define endl '\n'
constexpr int Ma = 500 + 100, inf = 0x3f3f3f3f;
constexpr db dinf = numeric_limits<db>::max();
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}

int mz[Ma][Ma], water[Ma][Ma];

int xz[] = {0, 0, 1, -1, 1, -1, 1, -1},
    yz[] = {1, -1, 0, 0, 1, -1, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    rep (i, n) rep (j, m) cin >> mz[i + 1][j + 1], water[i + 1][j + 1] = max(0, 0 - mz[i + 1][j + 1]);
    auto ck = [&] (int r, int c) {
        return r > 0 and r <= n and c > 0 and c <= m;
    };
    int r, c; cin >> r >> c;
    auto dis = [&] (int rr, int cc) {
        return max(abs(r - rr), abs(c - cc));
    };
    int id[8]; iota(id, id + 8, 0);
    fep (i, 1, n + 1) fep (j, 1, m + 1) {
        int& water = ::water[i][j];
        auto cal = [&] (int k) {
                    int rr = i + xz[k], cc = j + yz[k];
                    return dis(rr, cc);
                };
        sort(id, id + 8, [&] (int k1, int k2) {
                    return cal(k1) < cal(k2);
                });
        rep (kk, 8) {
            int k = id[kk];
            int rr = i + xz[k], cc = j + yz[k];
            if (ck(rr, cc) and water + mz[i][j] > mz[rr][cc] and dis(rr, cc) < dis(i, j)) {
                int diff = min(water, water + mz[i][j] - mz[rr][cc]);
                water -= diff;
                ::water[rr][cc] += diff;
            }
        }
    }
    for (int i = n; i > 0; i--) for (int j = m; j > 0; j--) {
        int& water = ::water[i][j];
        auto cal = [&] (int k) {
                    int rr = i + xz[k], cc = j + yz[k];
                    return dis(rr, cc);
                };
        sort(id, id + 8, [&] (int k1, int k2) {
                    return cal(k1) < cal(k2);
                });
        rep (kk, 8) {
            int k = id[kk];
            int rr = i + xz[k], cc = j + yz[k];
            if (ck(rr, cc) and water + mz[i][j] > mz[rr][cc] and dis(rr, cc) < dis(i, j)) {
                int diff = min(water, water + mz[i][j] - mz[rr][cc]);
                water -= diff;
                ::water[rr][cc] += diff;
            }
        }
    }
    for (int j = m; j > 0; j--) for (int i = n; i > 0; i--) {
        int& water = ::water[i][j];
        auto cal = [&] (int k) {
                    int rr = i + xz[k], cc = j + yz[k];
                    return dis(rr, cc);
                };
        sort(id, id + 8, [&] (int k1, int k2) {
                    return cal(k1) < cal(k2);
                });
        rep (kk, 8) {
            int k = id[kk];
            int rr = i + xz[k], cc = j + yz[k];
            if (ck(rr, cc) and water + mz[i][j] > mz[rr][cc] and dis(rr, cc) < dis(i, j)) {
                int diff = min(water, water + mz[i][j] - mz[rr][cc]);
                water -= diff;
                ::water[rr][cc] += diff;
            }
        }
    }
    for (int j = 1; j <= m; j++) for (int i = 1; i <= n; i++) {
        int& water = ::water[i][j];
        auto cal = [&] (int k) {
                    int rr = i + xz[k], cc = j + yz[k];
                    return dis(rr, cc);
                };
        sort(id, id + 8, [&] (int k1, int k2) {
                    return cal(k1) < cal(k2);
                });
        rep (kk, 8) {
            int k = id[kk];
            int rr = i + xz[k], cc = j + yz[k];
            if (ck(rr, cc) and water + mz[i][j] > mz[rr][cc] and dis(rr, cc) < dis(i, j)) {
                int diff = min(water, water + mz[i][j] - mz[rr][cc]);
                water -= diff;
                ::water[rr][cc] += diff;
            }
        }
    }
    cout << water[r][c] << endl;
}
