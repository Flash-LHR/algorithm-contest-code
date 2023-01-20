from random import randint

n = randint(5000, 5000)
p = randint(5000, 5000)
print(n, p)
print(' '.join([str(randint(0, 1e9)) for _ in range(n)]))