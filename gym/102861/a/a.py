n, a, b = map(int, input().split())
f = [0.0] * (n + b + 1)
suf = [0.0] * (n + b + 2)
for i in range(n - 1, -1, -1) :
    sz = b + 1 - max(a, 1)
    f[i] = (suf[i + max(a, 1)] - suf[i + b + 1]) / (b - a + 1) + sz / (b - a + 1)
    if a == 0 : f[i] += (f[i] + 1.0) / (b - a);
    suf[i] = suf[i + 1] + f[i]
#print(f)
#if a == 0 : f[0] += (f[0] + 1.0) / (b - a + 1);
print(f[0])

