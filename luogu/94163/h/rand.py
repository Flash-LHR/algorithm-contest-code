from random import randint

t = 1
print(t)
for _ in range(t):
    n = randint(1, 10)
    h = randint(1, 1000)
    print(n, h)
    print(' '.join(str(randint(-1000000000, 1000000000)) for __ in range(n)))
