from random import randint

T = 10
print(T)
for _ in range(T):
    n = randint(1, 50)
    q = randint(1, 50)
    print(n, q)
    for i in range(n):
        print(randint(1, 100), end=' ')
    print()
    for i in range(q):
        l = randint(1, n)
        r = randint(1, n)
        if l > r:
            l, r = r, l
        print(l, r)
