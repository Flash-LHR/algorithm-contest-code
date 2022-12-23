from random import randint

T = 2
print(T)
for _ in range(T):
    n = randint(3, 5)
    print(n)
    print(' '.join([str(randint(1, 10)) for i in range(n)]))
    print(' '.join([str(randint(1, 10)) for i in range(n)]))
