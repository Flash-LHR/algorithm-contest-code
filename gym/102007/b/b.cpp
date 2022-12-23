#include <bits/stdc++.h>
using namespace std;

constexpr int Ma = 1e6 + 100, inf = 0x3f3f3f3f;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
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

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int tot = 365;
int aim = 0;

int days[Ma];
char s_a[Ma];

int nm(int x) {
    return (x % tot + tot) % tot;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cerr << accumulate(month, month + 13, 0) << endl;
    for (int i = 0; i < 10; i++) aim += month[i];
    aim += 28;
    int n; cin >> n;
    rep (i, n) {
        string s; cin >> s;
        string data; cin >> data;
        int m, d;
        sscanf(data.c_str(), "%d-%d", &m, &d);
        int day{0};
        for (int j = 0; j < m; j++) day += month[j];
        day += d;
        day -= aim;
        if (day < 0) day += tot;
        days[i] = day;
    }
    sort(days, days + n);
    days[n] = days[0] + tot;
    int ans = 0, len = -1;
    for (int i = 1; i <= n; i++) if (days[i] - days[i - 1] > len) {
        len = days[i] - days[i - 1];
        ans = nm(days[i] - 1);
    } else if (days[i] - days[i - 1] == len)
        cmin(ans, nm(days[i] - 1));
    ans += aim; ans %= tot;
    if (ans == 0) ans = tot;
    for (int i = 1; i <= 12; i++) if (ans <= month[i]) {
        sprintf(s_a, "%02d-%02d\n", i, ans);
        break;
    } else ans -= month[i];
    cout << s_a;
}

