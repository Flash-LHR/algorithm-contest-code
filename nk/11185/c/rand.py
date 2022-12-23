from random import randint

t = 2
print(t)
for _ in range(t):
    n = randint(1, 5)
    k = randint(1, n)
    print(n, k)
    print(' '.join([str(randint(1, 20)) for i in range(n)]))
