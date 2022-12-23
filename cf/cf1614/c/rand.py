from random import randint

T = 2
print(T)
for _ in range(T):
    n = randint(1, 5)
    m = randint(1, 5)
    print(n, m)
    for i in range(m):
        l = randint(1, n)
        r = randint(1, n)
        if l > r:
            l, r = r, l
        print(l, r, randint(0, 5))
