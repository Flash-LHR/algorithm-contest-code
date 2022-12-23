from random import randint

n = randint(5e5, 5e5)
print(n)
for i in range(n):
    print(randint(1e9 - 1, 1e9), end=' ')
print()
