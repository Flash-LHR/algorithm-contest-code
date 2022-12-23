#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define P pair<int,int>
#define pll pair<long long,long long>
using namespace std;
template<typename T>void write(T x) {
    if(x<0) { putchar('-'); x=-x; }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], str[64];
    int l = SIZE, r = SIZE;
    int read(char *s) {
        while (r) {
            for (; l < r && buf[l] <= ' '; l++);
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        int cur = 0;
        while (r) {
            for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        s[cur] = '\0';
        return cur;
    }
    template<typename type>
    bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        if (flag) x = -x;
        return true;
    }
    template <typename type>
    type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        return flag ? -x : x;
    }
} using FastIO::read;
using namespace std;
const int N=5e5+10;
bool vis[N];
int sum[N],a[N];
int lowbit(int x) {
	return x&(-x);
}
int Sum(int pos) {
	int res=0;
	for (int i=pos; i; i-=lowbit(i)) res+=sum[i];
	return res;
}
void add(int pos, int val) {
	for (int i=pos; i<N; i+=lowbit(i)) sum[i]+=val;
}
int main() {
	vis[0]=vis[1]=true;
	for (ll i=2; i<N; i++) {
		if (vis[i]) continue;
		for (ll j=i*i; j<N; j+=i) vis[j]=true;
	}
	int n,m;
	read(n),read(m);
	set<int> s,one;
	for (int i=1; i<=n; i++) {
		read(a[i]);
		if (a[i]==1&&i>1) {
			one.insert(i);
			continue;
		}
		if (vis[a[i]]) continue;
        if (i>1) s.insert(i);
		add(i,1);
	}
	while (m--) {
		int op,l,r,x;
		read(op),read(l),read(r);
		if (op==1) {
			read(x);
			if (x) {
				auto p=s.lower_bound(l);
				auto L=p;
				while (p!=s.end()&&(*p)<=r) {
					add(*p,-1);
					p++;
				}
				s.erase(L,p);
				if (x>1) {
					auto p=one.lower_bound(l);
					auto L=p;
					while (p!=one.end()&&(*p)<=r) {
						p++;
					}
					one.erase(L,p);
				} else {
					auto p=one.lower_bound(l);
					auto L=p;
					while (p!=one.end()&&(*p)<=r) {
						if (!vis[*p]) {
							add(*p,1);
							s.insert(*p);
						}
						p++;
					}
					one.erase(L,p);
				}
			}
		}
		printf("%d\n",Sum(r)-Sum(l-1));
	}
    return 0;
}
