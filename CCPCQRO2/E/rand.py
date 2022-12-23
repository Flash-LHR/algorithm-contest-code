from random import randint

t = randint(1, 2)
print(t)
for _ in range(t):
    [n, m] = [randint(1, 5), randint(1, 5)]
    print(n, m)
    for i in range(n):
        print(randint(-10, 10), end=' ')
    print()
    for i in range(m):
        print(randint(-10, 10))
