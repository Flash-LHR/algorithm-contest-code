from random import randint

t = randint(1, 1)
print(t)
for _ in range(t):
    n = randint(1, 5)
    m = randint(1, 5)
    print(n, m)
    for i in range(m):
        print(randint(1, n), randint(1, n))
