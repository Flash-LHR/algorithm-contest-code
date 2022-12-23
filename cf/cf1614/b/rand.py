from random import randint

t = 10
print(t)
for _ in range(t):
    n = randint(100000, 200000)
    print(n)
    for i in range(n):
        print(randint(0, 1000000), end=' ')
    print()
