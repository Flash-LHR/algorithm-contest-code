from random import randint

n = randint(2, 500)
h = randint(0, n - 1)
print(n, h)
for i in range(1, n):
    print(randint(0, i - 1), i)
