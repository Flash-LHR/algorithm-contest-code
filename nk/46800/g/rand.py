from random import randint

n = randint(1, 10)
m = randint(1, 10)
print(n, m)
print(' '.join([str(randint(1, 100)) for _ in range(n)]))
for _ in range(m):
    op = randint(1, 2)
    if op == 1:
        l = randint(1, n)
        r = randint(1, n)
        k = randint(1, 10)
        if l > r:
            l, r = r, l
        print(op, l, r, k)
    else:
        print(op)