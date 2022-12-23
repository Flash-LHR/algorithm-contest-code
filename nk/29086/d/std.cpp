#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
struct node
{
    int ch[35];
    int fail;
    bool ed;
};
struct node NIL;
node tr[100005];
struct trie
{
    int siz = 0;
    void insert(string s)
    {
        int place = 0;
        for (int i = 0; i < s.length();i++)
        {
            if (!tr[place].ch[s[i] - 65])
                tr[place].ch[s[i] - 65] = ++siz;
            place = tr[place].ch[s[i] - 65];
        }
        tr[place].ed = 1;
    }
    void build()
    {
        queue<int> q;
        vector<int> temp;
        for (int i = 0; i < 26;i++)
            if(tr[0].ch[i])
            {
                q.push(tr[0].ch[i]);
                temp.push_back(tr[0].ch[i]);
            }
        while(!q.empty())
        {
            int tp = q.front();
            q.pop();
            for (int i = 0; i < 26;i++)
                if(tr[tp].ch[i])
                {
                    tr[tr[tp].ch[i]].fail = tr[tr[tp].fail].ch[i];
                    q.push(tr[tp].ch[i]);
                    temp.push_back(tr[tp].ch[i]);
                }
                else
                    tr[tp].ch[i] = tr[tr[tp].fail].ch[i];
        }
        for (int i = 0; i < temp.size();i++)
            tr[temp[i]].ed |= tr[tr[temp[i]].fail].ed;
    }
};
const int mod = 10007;
int f[105][100005];
int main()
{
    string a;
    int n, m;
    trie tree;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++)
    {
        cin >> a;
        tree.insert(a);
    }
    tree.build();
    int siz = tree.siz;
    f[0][0] = 1;
    for (int i = 1; i <= m;i++)
    {
        for (int j = 0; j <= siz;j++)
            for (int k = 0; k < 26;k++)
            {
                if(tr[tr[j].ch[k]].ed)
                    f[i][siz + 1] = (f[i][siz + 1] + f[i - 1][j]) % mod;
                else
                    f[i][tr[j].ch[k]] = (f[i][tr[j].ch[k]] + f[i - 1][j]) % mod;
            }
        f[i][siz + 1] = (f[i][siz + 1] + f[i - 1][siz + 1] * 26 % mod) % mod;
    }
    printf("%d\n", f[m][siz + 1]);
    return 0;
}
