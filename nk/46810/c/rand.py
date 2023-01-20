from random import randint

n = randint(1, 10)
m = randint(1, 5)
print(n, m)
for i in range(m):
    l = randint(1, 10)
    r = randint(1, 10)
    if l > r:
        l, r = r, l
    print(l, r)