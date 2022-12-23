#include <bits/stdc++.h>
using namespace std;

constexpr int Ma = 1e6 + 100, inf = 0x3f3f3f3f;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define F first
#define S second
#define endl '\n'
using ll = long long;
using db = double;
constexpr db eps = 1e-9;
#define ep emplace_back
template<typename T>
bool cmin(T &a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T &a, const T& b) {return a >= b || (a = b, false);}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    int num[]{0, 0, 0};
    rap (i, s) num[i - 'A']++;
    char ss[]{'A', 'B', 'C'};
    int ans = inf;
    s += s;
    do {
        int nm[]{num[ss[0]-'A'], num[ss[1]-'A'], num[ss[2]-'A']};
        int cnt[]{0, 0, 0};
        int mx{inf};
        for (int i = 0; i < n; i++) {
            if (i < nm[0]) cnt[0] += s[i] != ss[0];
            else if (i < nm[1] + nm[0]) cnt[1] += s[i] != ss[1];
            else cnt[2] += s[i] != ss[2];
        }
        cmin(mx, accumulate(cnt, cnt + 3, 0));
        for (int i = 1; i < n; i++) {
            int cur = i - 1;
            rep (j, 3) {
                if (nm[j]) {
                    if (s[cur] != ss[j]) --cnt[j];
                    cur += nm[j];
                    if (s[cur] != ss[j]) ++cnt[j];
                }
            }
            cmin(mx, accumulate(cnt, cnt + 3, 0));
        }
        cmin(ans, mx);
    } while (next_permutation(ss, ss + 3));
    cout << ans << endl;
}

