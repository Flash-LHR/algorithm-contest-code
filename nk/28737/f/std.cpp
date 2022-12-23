#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::pair<ll, ll> PLL;
#define x first
#define y second
#define pb push_back
#define mkp make_pair
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n;
int h[N], e[N << 1], to[N << 1], idx, sz[N];

void add(int a, int b){
    e[idx] = b, to[idx] = h[a], h[a] = idx++;
}

int ne[N];

void get_ne(string s){
	int len = s.size() + 1;
	ne[1] = 0;
	for(int i = 2, j = 0; i <= len; i++){
		while(j && s[j + 1] != s[i]) j = ne[j];
		if(s[i] == s[j + 1]) j++;
		ne[i] = j;
	}
}

void dfs(int u, int p){
	sz[u] = 1;
	for(int i = h[u]; ~i; i = to[i]){
		int v = e[i];
		if(v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(h, -1, sizeof h);
    string s;
    int k, n;
    cin >> n >> k;
    cin >> s;
    s = " " + s;
    get_ne(s);
    for(int i = 1; i <= n; i++){
    	add(ne[i], i), add(i, ne[i]);
    }
    dfs(0, -1);
    int now = n;
    while(now && sz[now] < k){
    	now = ne[now];
    }
    if(!now) cout << -1 << endl;
    else cout << s.substr(1, now) << endl;
    return 0;
}
