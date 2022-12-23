from random import randint

T = 10
print(T)
for _ in range(T):
    n = randint(1, 5)
    print(n)
    for i in range(n):
        print(randint(1, 1e9), end=' ')
    print()
    for i in range(n):
        print(randint(0, i), end=' ')
    print()
