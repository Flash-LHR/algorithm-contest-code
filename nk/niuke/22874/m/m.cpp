#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
constexpr int Ma = 510;
vector<int> g[Ma];
int in[Ma];

int main() {
    int n; scanf("%d\n", &n);
    set<char> st;
    string ans;
    for (int i = 0; i < n; i++) {
        char x[3];
        scanf("%c:%c%c\n", x, x + 1, x + 2);
        in[x[0]]++, in[x[2]]++;
        for (int j = 0; j < 3; j++)
            st.emplace(x[j]);
        g[x[1]].emplace_back(x[0]);
        g[x[0]].emplace_back(x[2]);
    }
    queue<int> q;
    for (auto& i : st) if (in[i] == 0)
        q.emplace(i);
    while (!q.empty()) {
        int t = q.front(); q.pop();
        ans += (char) t;;
        for (auto& i : g[t]) if (--in[i] == 0)
            q.emplace(i);
    }
    if (ans.size() != st.size()) puts("No Answer");
    else printf("%s\n", ans.c_str());
}

