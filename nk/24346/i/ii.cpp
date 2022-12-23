#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T& x)
{
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
    x *= f;
}

template <typename T>
void print(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch)
{
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;

const db eps = 1e-8;
const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

struct Complex
{
    db r, i;

    Complex(db r = 0, db i = 0) {
        this->r = r, this->i = i;
    }

    void scan() {
        scanf("%lf %lf", &r, &i);
    }

    void print() {
        printf("%.12f %.12f\n", r, i);
    }

    db length2() {
        return r * r + i * i;
    }

    Complex operator+(Complex b) {
        return Complex(r + b.r, i + b.i);
    }

    Complex operator-(Complex b) {
        return Complex(r - b.r, i - b.i);
    }

    Complex operator*(Complex b) {
        return Complex(r * b.r - i * b.i, r * b.i + i * b.r);
    }

    Complex operator/(Complex b) {
        return Complex((r * b.r + i * b.i) / b.length2(), (i * b.r - r * b.i) / b.length2());
    }

    int sign(db a) {
        return a < -eps ? -1 : a > eps;
    }

    int cmp(db a, db b) {
        return sign(a - b);
    }

    bool operator==(Complex b) {
        return cmp(r, b.r) == 0 && cmp(i, b.i) == 0;
    }

    bool operator>(Complex b) {
        return this->length2() > b.length2();
    }
};

Complex z[4], w[4];

bool check()
{
    Complex a = (w[2] - w[1]) / (z[2] - z[1]), b = w[1] - a * z[1];
    if(a * z[3] + b == w[3])
    {
        (a * z[0] + b).print();
        return 1;
    }
    return 0;
}

Complex a[10][10];

void build()
{
    for(int i = 1; i <= 3; ++i)
    {
        a[i][1] = z[i], a[i][2] = 1, a[i][3] = Complex(0, 0) - w[i], a[i][4] = w[i] * z[i];
    }

}

void nmsl()
{
    printf("-----------\n");
    for(int i = 1; i <= 3; ++i)
    {
        for(int j = 1; j <= 4; ++j)
        {
            printf("[%f,%f] ", a[i][j].r, a[i][j].i);
        }
        printf("\n");
    }
    printf("--------------\n");

}

void guass(int n, int m)
{
    int c, r;
    for(c = 1, r = 1; c <= m; ++c)
    {
        int t = r;
        for(int i = r; i <= n; ++i)
        {
            if(a[i][c] > a[t][c]) t = i;
        }
        for(int i = c; i <= m + 1; ++i) swap(a[t][i], a[r][i]);
        for(int i = m + 1; i >= c; --i) a[r][i] = a[r][i] / a[r][c];
        for(int i = 1; i <= n; ++i)
        {
            if(i == r) continue;
            if(a[i][c].length2() > eps)
            {
                for(int j = m + 1; j >= c; --j)
                {
                    a[i][j] = a[i][j] - a[r][j] * a[i][c];
                }
            }
        }
        ++r;
    }
}

void work()
{
    for(int i = 1; i < 4; ++i) z[i].scan(), w[i].scan();
    z[0].scan();
    if(check()) return;
    build();
    guass(3, 3);
    Complex A = a[1][4], B = a[2][4], D = a[3][4];
    Complex ans = (A * z[0] + B) / (z[0] + D);
    ans.print();
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}



