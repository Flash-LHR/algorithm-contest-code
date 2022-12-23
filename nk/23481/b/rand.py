from random import randint

T = 2
print(T)
for _ in range(T):
    n = randint(1, 5)
    print(n)
    for i in range(n):
        print(randint(1, 5), end=' ')
    print()
