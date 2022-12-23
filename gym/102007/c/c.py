n = int(input())
ans = float('inf')
g = [[] for _ in range(1000001)]
for i in range(1, 1000001) :
    for j in range(i, 1000001, i) :
        g[j].append(i)
for i in range(1, n + 1) :
    if n % i == 0 :
        mi = float('inf')
        for x in g[n // i] :
            mi = min(mi, x + n // i // x)
        ans = min(ans, n // i * 2 + mi * i * 2)
print(ans)

