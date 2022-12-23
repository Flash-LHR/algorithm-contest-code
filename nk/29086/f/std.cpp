#include <bits/stdc++.h>
using namespace std;

class trie
{
private:
    struct node
    {
        int ed;
        int fail;
        int ch[2];
        node()
        {
            ed = fail = ch[0] = ch[1] = 0;
        }
    } NIL;
    int siz = 0;
    vector<node> tr;
    vector<int> vis, f;

public:
    trie()
    {
        tr.push_back(NIL);
    }
    void insert(string s)
    {
        if(!tr.size())
            tr.push_back(NIL);
        int place = 0;
        for (int i = 0; i < s.length();i++)
        {
            if (tr[place].ch[s[i] - 48] == 0)
            {
                tr[place].ch[s[i] - 48] = ++siz;
                tr.push_back(NIL);
            }
            place = tr[place].ch[s[i] - 48];
        }
        tr[place].ed = 1;
    }
    void build()
    {
        queue<int> q;
        vis.resize(siz + 1);
        f.resize(siz + 1);
        for (int i = 0; i <= 1;i++)
            if(tr[0].ch[i])
                q.push(tr[0].ch[i]);
        while(!q.empty())
        {
            int tp = q.front();
            tr[tp].ed |= tr[tr[tp].fail].ed;
            q.pop();
            for (int i = 0; i <= 1;i++)
                if(tr[tp].ch[i])
                {
                    tr[tr[tp].ch[i]].fail = tr[tr[tp].fail].ch[i];
                    q.push(tr[tp].ch[i]);
                }
                else
                    tr[tp].ch[i] = tr[tr[tp].fail].ch[i];
        }
        // for (int i = 0; i <= siz;i++)
        //     printf("%d %d\n%d %d\n", i, tr[i].ch[0], i, tr[i].ch[1]);
        // for (int i = 0; i <= siz;i++)
        //     if(tr[i].ed)
        //         printf("%d\n", i);
    }
    bool dfs(int place)
    {
        vis[place] = 1;
        bool ans = 0;
        for (int i = 0; i <= 1; i++)
            if(vis[tr[place].ch[i]])
                return true;
            else if(!tr[tr[place].ch[i]].ed && !f[tr[place].ch[i]])
            {
                f[tr[place].ch[i]] = 1;
                ans |= dfs(tr[place].ch[i]);
            }
        vis[place] = false;
        return ans;
    }
};
int main()
{
    int n;
    scanf("%d", &n);
    string s;
    trie solve;
    for (int i = 1; i <= n;i++)
    {
        cin >> s;
        solve.insert(s);
    }
    solve.build();
    if(solve.dfs(0))
        printf("TAK\n");
    else
        printf("NIE\n");
    return 0;
}
