k = int(input())
lim = 1 << 1000
m = float('inf')
prim = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]

def dfs(u, k, pv, res) :
    global m
    if u == 12 :
        if k == 1 :
            m = min(m, res)
        return 
    now = 1
    for i in range(pv + 1) :
        if res * now > lim :
            break
        if k % (i + 1) == 0 :
            dfs(u + 1, k // (i + 1), i, res * now)
        now *= prim[u]

dfs(0, k, k, 1)
'''else :
    cur = 2
    mm = m
    tot = 1
    while cur * cur <= m :
        if m % cur == 0 :
            cnt = 0
            while m % cur == 0 :
                cnt += 1
                m //= cur
            tot *= cnt + 1
#            print(cur, cnt)
        cur += 1
    if m != 1 :
#        print(m, 1)
        tot *= 2
    assert tot == k
    m = mm'''
print(m)
