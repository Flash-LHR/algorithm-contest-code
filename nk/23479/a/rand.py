from random import randint

n, k = randint(1, 10), randint(1, 5)
print(n, k)
print(''.join(["RPA"[randint(0, 2)] for i in range(n)]))
