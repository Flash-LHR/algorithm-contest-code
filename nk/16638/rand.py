from random import randint

n = randint(1, 3)
m = randint(1, 3)
print(n, m)
ch = [chr(ord('a') + i) for i in range(0,3)]
for i in range(n):
    for j in range(m):
        print(ch[randint(0, len(ch) - 1)], end='')
    print()
for i in range(n):
    for j in range(m):
        print(randint(1, 5), end=' ')
    print()
