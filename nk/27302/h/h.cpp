#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T& x) {
	x = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
	x *= f;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch) {
	print(x), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const db eps = 1e-6;
const int M = (int)5e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

//大数
struct BigInteger
{
    static const int BASE = 100000000; //和WIDTH保持一致
    static const int WIDTH = 8;        //八位一存储,如修改记得修改输出中的%08d
    bool sign;                         //符号, 0表示负数
    size_t length;                     //位数
    vector<int> num;                   //反序存
                                       //构造函数
    BigInteger(long long x = 0) { *this = x; }
    BigInteger(const string &x) { *this = x; }
    BigInteger(const BigInteger &x) { *this = x; }
    //剪掉前导0，并且求一下数的位数
    void cutLeadingZero()
    {
        while (num.back() == 0 && num.size() != 1)
        {
            num.pop_back();
        }
        int tmp = num.back();
        if (tmp == 0)
        {
            length = 1;
        }
        else
        {
            length = (num.size() - 1) * WIDTH;
            while (tmp > 0)
            {
                length++;
                tmp /= 10;
            }
        }
    }
    //赋值运算符
    BigInteger &operator=(long long x)
    {
        num.clear();
        if (x >= 0)
        {
            sign = true;
        }
        else
        {
            sign = false;
            x = -x;
        }
        do
        {
            num.push_back(x % BASE);
            x /= BASE;
        } while (x > 0);
        cutLeadingZero();
        return *this;
    }
    BigInteger &operator=(const string &str)
    {
        num.clear();
        sign = (str[0] != '-'); //设置符号
        int x, len = (str.size() - 1 - (!sign)) / WIDTH + 1;
        for (int i = 0; i < len; i++)
        {
            int End = str.size() - i * WIDTH;
            int start = max((int)(!sign), End - WIDTH); //防止越界
            sscanf(str.substr(start, End - start).c_str(), "%d", &x);
            num.push_back(x);
        }
        cutLeadingZero();
        return *this;
    }
    BigInteger &operator=(const BigInteger &tmp)
    {
        num = tmp.num;
        sign = tmp.sign;
        length = tmp.length;
        return *this;
    }
    //绝对值
    BigInteger abs() const
    {
        BigInteger ans(*this);
        ans.sign = true;
        return ans;
    }
    //正号
    const BigInteger &operator+() const { return *this; }
    //负号
    BigInteger operator-() const
    {
        BigInteger ans(*this);
        if (ans != 0)
            ans.sign = !ans.sign;
        return ans;
    }
    // + 运算符
    BigInteger operator+(const BigInteger &b) const
    {
        if (!b.sign)
        {
            return *this - (-b);
        }
        if (!sign)
        {
            return b - (-*this);
        }
        BigInteger ans;
        ans.num.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= num.size() && i >= b.num.size())
                break;
            int x = g;
            if (i < num.size())
                x += num[i];
            if (i < b.num.size())
                x += b.num[i];
            ans.num.push_back(x % BASE);
            g = x / BASE;
        }
        ans.cutLeadingZero();
        return ans;
    }
    // - 运算符
    BigInteger operator-(const BigInteger &b) const
    {
        if (!b.sign)
        {
            return *this + (-b);
        }
        if (!sign)
        {
            return -((-*this) + b);
        }
        if (*this < b)
        {
            return -(b - *this);
        }
        BigInteger ans;
        ans.num.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= num.size() && i >= b.num.size())
                break;
            int x = g;
            g = 0;
            if (i < num.size())
                x += num[i];
            if (i < b.num.size())
                x -= b.num[i];
            if (x < 0)
            {
                x += BASE;
                g = -1;
            }
            ans.num.push_back(x);
        }
        ans.cutLeadingZero();
        return ans;
    }
    // * 运算符
    BigInteger operator*(const BigInteger &b) const
    {
        int lena = num.size(), lenb = b.num.size();
        BigInteger ans;
        for (int i = 0; i < lena + lenb; i++)
            ans.num.push_back(0);
        for (int i = 0, g = 0; i < lena; i++)
        {
            g = 0;
            for (int j = 0; j < lenb; j++)
            {
                long long x = ans.num[i + j];
                x += (long long)num[i] * (long long)b.num[j];
                ans.num[i + j] = x % BASE;
                g = x / BASE;
                ans.num[i + j + 1] += g;
            }
        }
        ans.cutLeadingZero();
        ans.sign = (ans.length == 1 && ans.num[0] == 0) || (sign == b.sign);
        return ans;
    }
    //*10^n 大数除大数中用到
    BigInteger e(size_t n) const
    {
        int tmp = n % WIDTH;
        BigInteger ans;
        ans.length = n + 1;
        n /= WIDTH;
        while (ans.num.size() <= n)
            ans.num.push_back(0);
        ans.num[n] = 1;
        while (tmp--)
            ans.num[n] *= 10;
        return ans * (*this);
    }
    // /运算符 (大数除大数)
    BigInteger operator/(const BigInteger &b) const
    {
        BigInteger aa((*this).abs());
        BigInteger bb(b.abs());
        if (aa < bb)
            return 0;
        char *str = new char[aa.length + 1];
        memset(str, 0, sizeof(char) * (aa.length + 1));
        BigInteger tmp;
        int lena = aa.length, lenb = bb.length;
        for (int i = 0; i <= lena - lenb; i++)
        {
            tmp = bb.e(lena - lenb - i);
            while (aa >= tmp)
            {
                str[i]++;
                aa = aa - tmp;
            }
            str[i] += '0';
        }
        BigInteger ans(str);
        delete[] str;
        ans.sign = (ans == 0 || sign == b.sign);
        return ans;
    }
    // %运算符
    BigInteger operator%(const BigInteger &b) const
    {
        return *this - *this / b * b;
    }
    // ++ 运算符
    BigInteger &operator++()
    {
        *this = *this + 1;
        return *this;
    }
    // -- 运算符
    BigInteger &operator--()
    {
        *this = *this - 1;
        return *this;
    }
    // += 运算符
    BigInteger &operator+=(const BigInteger &b)
    {
        *this = *this + b;
        return *this;
    }
    // -= 运算符
    BigInteger &operator-=(const BigInteger &b)
    {
        *this = *this - b;
        return *this;
    }
    // *=运算符
    BigInteger &operator*=(const BigInteger &b)
    {
        *this = *this * b;
        return *this;
    }
    // /= 运算符
    BigInteger &operator/=(const BigInteger &b)
    {
        *this = *this / b;
        return *this;
    }
    // %=运算符
    BigInteger &operator%=(const BigInteger &b)
    {
        *this = *this % b;
        return *this;
    }
    // < 运算符
    bool operator<(const BigInteger &b) const
    {
        if (sign != b.sign) //正负，负正
        {
            return !sign;
        }
        else if (!sign && !b.sign) //负负
        {
            return -b < -*this;
        }
        //正正
        if (num.size() != b.num.size())
            return num.size() < b.num.size();
        for (int i = num.size() - 1; i >= 0; i--)
            if (num[i] != b.num[i])
                return num[i] < b.num[i];
        return false;
    }
    bool operator>(const BigInteger &b) const { return b < *this; }                     // >  运算符
    bool operator<=(const BigInteger &b) const { return !(b < *this); }                 // <= 运算符
    bool operator>=(const BigInteger &b) const { return !(*this < b); }                 // >= 运算符
    bool operator!=(const BigInteger &b) const { return b < *this || *this < b; }       // != 运算符
    bool operator==(const BigInteger &b) const { return !(b < *this) && !(*this < b); } //==运算符
    // 逻辑运算符
    bool operator||(const BigInteger &b) const { return *this != 0 || b != 0; } // || 运算符
    bool operator&&(const BigInteger &b) const { return *this != 0 && b != 0; } // && 运算符
    bool operator!() { return (bool)(*this == 0); }                             // ！ 运算符
 
    //重载<<使得可以直接输出大数
    friend ostream &operator<<(ostream &out, const BigInteger &x)
    {
        if (!x.sign)
            out << '-';
        out << x.num.back();
        for (int i = x.num.size() - 2; i >= 0; i--)
        {
            char buf[10];
            //如WIDTH和BASR有变化,此处要修改为%0(WIDTH)d
            sprintf(buf, "%08d", x.num[i]);
            for (int j = 0; j < strlen(buf); j++)
                out << buf[j];
        }
        return out;
    }
    //重载>>使得可以直接输入大数
    friend istream &operator>>(istream &in, BigInteger &x)
    {
        string str;
        in >> str;
        size_t len = str.size();
        int start = 0;
        if (str[0] == '-')
            start = 1;
        if (str[start] == '\0')
            return in;
        for (int i = start; i < len; i++)
        {
            if (str[i] < '0' || str[i] > '9')
                return in;
        }
        x.sign = !start;
        x = str.c_str();
        return in;
    }
};
 
char s[M + 5];

void work() {
	scanf("%s", s);
	int n = strlen(s);
	BigInteger ans = 0, cur = 0;
	for(int i = 0; i < n; ++i) {
		cur *= 10;
		cur += s[i] - '0';
		ans += cur;
	}
	cout << ans << "\n";
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

