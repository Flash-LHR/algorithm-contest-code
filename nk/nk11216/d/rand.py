from random import randint

n = randint(1, 5)
m = randint(1, 5)
print(n, m)
for i in range(n):
    print(randint(1, 10), end=' ')
print()
for i in range(m):
    op = randint(1, 2)
    if op == 1:
        l = randint(1, n)
        r = randint(1, n)
        if l > r:
            l, r = r, l
        x = randint(0, 5)
        print(op, l, r, x)
    elif op == 2:
        l = randint(1, n)
        r = randint(1, n)
        if l > r:
            l, r = r, l
        print(op, l, r)
