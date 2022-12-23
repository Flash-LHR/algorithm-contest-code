#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template <ui M_> struct ModInt {
    static constexpr ui M = M_;
    ui x;
    constexpr ModInt(): x(0U){}
    constexpr ModInt(ui x_): x(x_ % M){}
    constexpr ModInt(ull x_): x(x_ % M){}
    constexpr ModInt(int x_): x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_){}
    constexpr ModInt(ll x_): x(((x_ %= static_cast<ll>(M)) < 0) ? (x_ + static_cast<ll>(M)) : x_){}
    ModInt &operator+=(const ModInt &a) {x = ((x += a.x) >= M) ? (x - M) : x; return *this;}
    ModInt &operator-=(const ModInt &a) {x = ((x -= a.x) >= M) ? (x + M) : x; return *this;}
    ModInt &operator*=(const ModInt &a) {x = (static_cast<ull>(x) * a.x) % M; return *this;}
    ModInt &operator/=(const ModInt &a) {return (*this *= a.inv());}
    ModInt pow(ll e) const {
        if(e < 0) return inv().pow(-e);
        ModInt a = *this, b = 1U; for(; e; e >>= 1) {if(e & 1) b *= a; a *= a;} return b;
    }
    ModInt inv() const {
        ui a = M, b = x; int y = 0, z = 1;
        while(b) {const ui q = a / b; const ui c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w;}
        return ModInt(y);
    }
    ModInt operator+() const {return *this;}
    ModInt operator-() const {ModInt a; a.x = x ? (M - x) : 0U; return a;}
    ModInt operator+(const ModInt &a) const {return (ModInt(*this) += a);}
    ModInt operator-(const ModInt &a) const {return (ModInt(*this) -= a);}
    ModInt operator*(const ModInt &a) const {return (ModInt(*this) *= a);}
    ModInt operator/(const ModInt &a) const {return (ModInt(*this) /= a);}
    template <class T> friend ModInt operator+(T a, const ModInt &b) {return (ModInt(a) += b);}
    template <class T> friend ModInt operator-(T a, const ModInt &b) {return (ModInt(a) -= b);}
    template <class T> friend ModInt operator*(T a, const ModInt &b) {return (ModInt(a) *= b);}
    template <class T> friend ModInt operator/(T a, const ModInt &b) {return (ModInt(a) /= b);}
    explicit operator bool() const {return x;}
    bool operator==(const ModInt &a) const {return (x == a.x);}
    bool operator!=(const ModInt &a) const {return (x != a.x);}
    friend std::ostream &operator<<(std::ostream &os, const ModInt &a) {return os << a.x;}
};

constexpr unsigned MO = 998244353U;
constexpr unsigned MO2 = 2U * MO;
constexpr int FFT_MAX = 23;
using Mint = ModInt<MO>;
constexpr Mint FFT_ROOTS[FFT_MAX + 1] = {1U, 998244352U, 911660635U, 372528824U, 929031873U, 452798380U, 922799308U, 781712469U, 476477967U, 166035806U, 258648936U, 584193783U, 63912897U, 350007156U, 666702199U, 968855178U, 629671588U, 24514907U, 996173970U, 363395222U, 565042129U, 733596141U, 267099868U, 15311432U};
constexpr Mint INV_FFT_ROOTS[FFT_MAX + 1] = {1U, 998244352U, 86583718U, 509520358U, 337190230U, 87557064U, 609441965U, 135236158U, 304459705U, 685443576U, 381598368U, 335559352U, 129292727U, 358024708U, 814576206U, 708402881U, 283043518U, 3707709U, 121392023U, 704923114U, 950391366U, 428961804U, 382752275U, 469870224U};
constexpr Mint FFT_RATIOS[FFT_MAX] = {911660635U, 509520358U, 369330050U, 332049552U, 983190778U, 123842337U, 238493703U, 975955924U, 603855026U, 856644456U, 131300601U, 842657263U, 730768835U, 942482514U, 806263778U, 151565301U, 510815449U, 503497456U, 743006876U, 741047443U, 56250497U, 867605899U};
constexpr Mint INV_FFT_RATIOS[FFT_MAX] = {86583718U, 372528824U, 373294451U, 645684063U, 112220581U, 692852209U, 155456985U, 797128860U, 90816748U, 860285882U, 927414960U, 354738543U, 109331171U, 293255632U, 535113200U, 308540755U, 121186627U, 608385704U, 438932459U, 359477183U, 824071951U, 103369235U};

void fft(Mint *as, int n) {
    int m = n;
    if(m >>= 1) {
        for(int i = 0; i < m; ++i) {
            const ui x = as[i + m].x;
            as[i + m].x = as[i].x + MO - x;
            as[i].x += x;
        }
    }
    if(m >>= 1) {
        Mint prod = 1U;
        for(int h = 0, i0 = 0; i0 < n; i0 += (m<<1)) {
            for(int i = i0; i < i0 + m; ++i) {
                const ui x = (prod * as[i + m]).x;
                as[i + m].x = as[i].x + MO - x;
                as[i].x += x;
            }
            prod *= FFT_RATIOS[__builtin_ctz(++h)];
        }
    }
    while(m) {
        if(m >>= 1) {
            Mint prod = 1U;
            for(int h = 0, i0 = 0; i0 < n; i0 += (m<<1)) {
                for(int i = i0; i < i0 + m; ++i) {
                    const ui x = (prod * as[i + m]).x;
                    as[i + m].x = as[i].x + MO - x;
                    as[i].x += x;
                }
                prod *= FFT_RATIOS[__builtin_ctz(++h)];
            }
        }
        if(m >>= 1) {
            Mint prod = 1U;
            for(int h = 0, i0 = 0; i0 < n; i0 += (m<<1)) {
                for(int i = i0; i < i0 + m; ++i) {
                    const ui x = (prod * as[i + m]).x;
                    as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;
                    as[i + m].x = as[i].x + MO - x;
                    as[i].x += x;
                }
                prod *= FFT_RATIOS[__builtin_ctz(++h)];
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;
        as[i].x = (as[i].x >= MO) ? (as[i].x - MO) : as[i].x;
    }
}

void invFft(Mint *as, int n) {
    int m = 1;
    if(m < n>>1) {
        Mint prod = 1U;
        for(int h = 0, i0 = 0; i0 < n; i0 += (m<<1)) {
            for(int i = i0; i < i0 + m; ++i) {
                const ull y = as[i].x + MO - as[i + m].x;
                as[i].x += as[i + m].x;
                as[i + m].x = (prod.x * y) % MO;
            }
            prod *= INV_FFT_RATIOS[__builtin_ctz(++h)];
        }
        m <<= 1;
    }
    for(; m < n>>1; m <<= 1) {
        Mint prod = 1U;
        for(int h = 0, i0 = 0; i0 < n; i0 += (m<<1)) {
            for(int i = i0; i < i0 + (m>>1); ++i) {
                const ull y = as[i].x + MO2 - as[i + m].x;
                as[i].x += as[i + m].x;
                as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;
                as[i + m].x = (prod.x * y) % MO;
            }
            for(int i = i0 + (m>>1); i < i0 + m; ++i) {
                const ull y = as[i].x + MO - as[i + m].x;
                as[i].x += as[i + m].x;
                as[i + m].x = (prod.x * y) % MO;
            }
            prod *= INV_FFT_RATIOS[__builtin_ctz(++h)];
        }
    }
    if(m < n) {
        for(int i = 0; i < m; ++i) {
            const ui y = as[i].x + MO2 - as[i + m].x;
            as[i].x += as[i + m].x;
            as[i + m].x = y;
        }
    }
    const Mint invN = Mint(n).inv();
    for(int i = 0; i < n; ++i) {
        as[i] *= invN;
    }
}

void fft(vector<Mint> &as) {
    fft(as.data(), as.size());
}

void invFft(vector<Mint> &as) {
    invFft(as.data(), as.size());
}

void convolve(vector<Mint>& as, vector<Mint>& bs) {
    if(as.empty() || bs.empty()) return as.clear(), void();
    const int len = as.size() + bs.size() - 1;
    int n = 1;
    for(; n < len; n <<= 1) {}
    as.resize(n); fft(as);
    bs.resize(n); fft(bs);
    for(int i = 0; i < n; ++i) as[i] *= bs[i];
    invFft(as);
    as.resize(len);
}

const int M = (int)1e5;
const ll mod = (ll)998244353;

int n, q; ll m;
int a[M + 5];
int b[M + 5];
int inv[M + 5];
vector<Mint> as, bs;
Mint s[M + 5];

void solve()
{
    int k = n;
    as.resize(n + 1), bs.resize(k + 1);
    for(int i = 0; i <= n; ++i) as[i] = a[i];
    inv[1] = 1; for(int i = 2; i <= k; ++i) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 0, cof = 1; i <= k; ++i) bs[i] = cof, cof = (m + i) % mod * cof % mod * inv[i + 1] % mod;
    convolve(as, bs);
    s[0] = 0; for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + b[i] * as[i];
}

void work()
{
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    solve();
    for(int i = 1, l, r; i <= q; ++i)
    {
        cin >> l >> r;
        cout << s[r] - s[l - 1] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    work();
    return 0;
}

