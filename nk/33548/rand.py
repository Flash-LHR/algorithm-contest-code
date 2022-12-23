from random import randint

n = randint(1, 5)
k = randint(1, 5)
print(n, k)
print(''.join([chr(ord('a')+randint(0, 2)) for i in range(n)]))
