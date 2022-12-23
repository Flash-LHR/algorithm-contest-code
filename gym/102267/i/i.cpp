#include <bits/stdc++.h>
using namespace std;

using db=double;
#define endl '\n'
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
const int Ma = 1e6 + 100;

char s[Ma];
int fa[Ma];
int go[Ma];

int gen(int l, int r) {
    char* pt;
    int who = strtol(s + l, &pt, 10);
    //char t = s[r]; s[r] = 0;
    //cerr << who << ' ' << s + l << endl;;
    //s[r] = t;
    for (int i = pt - s, pre = i + 1; i < r; i++) {
        if (s[i] == '(') {
            i = go[i];
            fa[gen(pre, i)] = who;
            pre = i + 2;
        }
    }
    return who;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    cin >> s;
    stack<int> st;
    rep (i, strlen(s)) {
        if (s[i] == '(') st.emplace(i);
        else if (s[i] == ')') go[st.top()] = i, st.pop();
    }
    gen(0, strlen(s));
    rep (i, n) cout << fa[i + 1] << " \n"[i == n - 1];
}

