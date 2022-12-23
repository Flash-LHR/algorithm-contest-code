from random import randint

n = randint(1, 5)
print(n)
for _ in range(n):
    l = randint(1, 5)
    r = randint(1, 5)
    if l > r:
        l, r = r, l
    print(l, r)
