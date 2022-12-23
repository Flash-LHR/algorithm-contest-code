n, a, b = map(int, input().split())
f = [0.0] * (n + b + 1)
f[n + b] = 0.0
for i in range(n - 1, -1, -1) :
    for j in range(max(1, a), b + 1) :
        f[i] += (f[i + j] + 1.0) / (b - a + 1)
    if a == 0 : f[i] += (f[i] + 1.0) / (b - a);
print(f)
#if a == 0 : f[0] += (f[0] + 1.0) / (b - a + 1);
print(f[0])

