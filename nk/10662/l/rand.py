from random import randint

T = 2
print(T)
for i in range(T):
    m = randint(1, 5)
    L = randint(1, 10000)
    print(m, L)
    for j in range(m):
        print(randint(0, 1), end=' ')
    print()
