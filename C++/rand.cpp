#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const int M = (int)1e5;
const int N = (int)2e4;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = (ll)1e9 + 7;

int Rand(int l, int r)
{
    return rand() % (r - l + 1) + l;
}

double Rand(double l, double r)
{
    return 1.0 * rand() / RAND_MAX * (r - l) + l;
}

void work()
{
	int n = Rand((int)1, (int)5);
	printf("%d\n", n);
    for(int i = 2; i <= n; ++i) printf("%d %d\n", Rand(1, i - 1), i);
    for(int i = 1; i <= n; ++i) printf("%d ", i); printf("\n");
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("input.txt", "w", stdout);
//    int T; scanf("%d", &T);
//    while(T--) work();
    srand(time(NULL));
    int T = (int)2;
    printf("%d\n", T);
    while(T--)
    work();
//    printf("0 0\n");
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}
