from random import randint

n = randint(1, 100) * 2
print(''.join([str(randint(0, 1)) for i in range(n)]))
print(' '.join([str(randint(1, 10000)) for i in range(3)]))
