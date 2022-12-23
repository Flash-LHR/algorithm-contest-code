from random import randint

t = 2
print(t)
for _ in range(t):
    n = randint(1, 5)
    m = randint(1, 5)
    print(n, m)
    for i in range(n):
        for j in range(n):
            if randint(0, 1) == 0: print('#', end='')
            else: print(chr(ord('a') + randint(0, 1)), end='')
        print()
    for i in range(m):
        for j in range(randint(1, n)):
            print(chr(ord('a')+randint(0, 1)), end='')
        print(' ' + str(randint(1, 2)))
