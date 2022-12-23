#include <bits/stdc++.h>
using namespace std;

using db=double;
#define endl '\n'
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
const int Ma = 22;

bool ban[Ma][Ma];
string ans[Ma][Ma];

bool ck (int r, int c) {
   return r > 0 and r <= 12 and c > 0 and c <= 12 and !ban[r][c];
}

char go[] = {'D', 'U', 'R', 'L'};
int xz[] = {-1, 1, 0, 0},
    yz[] = {0, 0, -1, 1};

void dfs(int r, int c, string s="") {
    ans[r][c] = s;
    rep (i, 4) {
        int rr = r + xz[i], cc = c + yz[i];
        if (ck(rr, cc) and ans[rr][cc].empty() and (rr != 3 or cc != 3))
            dfs(rr, cc, go[i] + s);
    }
}

int main() {
    ban[6][6] = ban[6][7] = ban[7][6] = ban[7][7] = 
    ban[9][2] = ban[9][3] = ban[10][2] = 
    ban[9][10] = ban[9][11] = ban[10][11] = true;
    dfs(3, 3);
    int L; cin >> L;
    while (L--) {
        int r, c; cin >> r >> c;
        cout << ans[r][c].size() << endl;
        cout << ans[r][c] << endl;
    }
}

