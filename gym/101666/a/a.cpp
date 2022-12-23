#include <bits/stdc++.h>
using namespace std;

using db = double;
constexpr db pi = acos(-1.0);
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int n, m; db R; cin >> n >> m >> R;
    int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
    db len = abs(ay - by) * R / m;
    db ang = pi / n * abs(ax - bx);
    db ans = numeric_limits<db>::max();
    for (int i = min(ay, by); i >= 0; i--) {
        db r = i * R / m;
        cmin(ans, len + pi * r / pi * ang);
        len += R / m * 2.0;
    }
    cout << ans << endl;
}
