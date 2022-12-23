from random import randint

t = 2
print(t)
for _ in range(t):
    n = randint(1, 20)
    print(n)
    print(' '.join([str(randint(1, n)) for i in range(n)]))
