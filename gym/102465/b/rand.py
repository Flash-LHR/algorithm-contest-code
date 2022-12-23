from random import randint
n = randint(1, 10)
print(n)
for _ in range(n) :
    l = randint(1, n - 1)
    r = randint(l, n - 1)
    print(l, r)

