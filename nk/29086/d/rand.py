from random import randint

n = randint(1, 3)
m = randint(1, 5)
print(n, m)
for i in range(n):
    for j in range(randint(1, 3)): print(chr(ord('A') + randint(0, 2)), end='')
    print()
