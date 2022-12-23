from random import randint

n = int(2)
m = int(2)
print(n, m)
for i in range(n):
    print(chr(randint(97, 100)), end='')
print()
for i in range(m):
    l = randint(1, n)
    r = randint(1, n)
    c = chr(randint(97, 100))
    if l > r:
        l, r = r, l
    print(l, r, c)
