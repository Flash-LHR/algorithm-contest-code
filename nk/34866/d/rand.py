from random import randint

n = randint(1, 500)
k = randint(1, n * (n + 1) // 2)
print(n, k)
for i in range(n):
    print(randint(-10000, 10000), end=' ')
print()
