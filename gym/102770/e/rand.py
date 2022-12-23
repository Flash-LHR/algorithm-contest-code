from random import randint

M = 100

t = 100
print(t)
for _ in range(t):
    n = int(M)
    print(n)
    for i in range(n): print(randint(1, int(1e6)), end=' ')
    print()
    q = int(M)
    print(q)
    for i in range(q):
        l = randint(1, n)
        r = randint(1, n)
        if l > r: l,r = r,l
        print(l, r, randint(1, r - l + 1))
