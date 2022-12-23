from random import randint

n = randint(2, 5)
print(n)
for i in range(2, n + 1):
    print(randint(1, i - 1), end=' ')
print()
