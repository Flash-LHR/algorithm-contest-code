n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
ans = 1
for i in range(1, n) :
    if a[i] + a[i - 1] <= m :
        ans = i + 1
print(ans)

