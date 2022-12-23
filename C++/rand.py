from random import randint

T = randint(1, 10)
print(T)
for _ in range(T):
    n = randint(1, 10000)
    a = randint(0, 10000)
    b = randint(a, 10000)
    print(n, a, b)
