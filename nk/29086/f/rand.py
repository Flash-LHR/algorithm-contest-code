from random import randint

n = randint(1, 3)
print(n)
for i in range(n):
    for j in range(randint(1, 3)): print(randint(0,1), end='')
    print()
