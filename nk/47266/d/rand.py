from random import randint

T = 2
print(T)
for _ in range(T):
    n = randint(1, int(1e16))
    k = randint(1, 100)
    m = randint(1, int(1e5))
    print(n, k, m)
    print(' '.join([str(randint(0, n - 1)) for i in range(m)]))