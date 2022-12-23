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

void work()
{
    for(int i = 1; i < 4; ++i) z[i].scan(), w[i].scan();
    z[0].scan();
    if(check()) return;
    Complex a = (w[3] * z[3] - w[1] * z[1]) * (w[1] - w[2]) - (w[2] * z[2] - w[1] * z[1]) * (w[1] - w[3]);
    a = a / ((z[1] - z[2]) * (w[1] - w[3]) - (z[1] - z[3]) * (w[1] - w[2]));
    Complex d = (w[3] * z[3] - a * z[3] - w[1] * z[1] + a * z[1]) / (w[1] - w[3]);
    Complex b = w[1] * z[1] + w[1] * d - a * z[1];
    w[0] = (a * z[0] + b) / (z[0] + d);
    w[0].print();
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



