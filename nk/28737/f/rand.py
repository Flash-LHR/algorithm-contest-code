from random import randint

n = randint(1, 5)
k = randint(1, n)
print(n, k)
ch = [chr(ord('a') + i) for i in range(0,2)]
for i in range(n): print(ch[randint(0, len(ch) - 1)], end='')
print()
