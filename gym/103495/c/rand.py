from random import randint

t = 5
print(t)
for _ in range(t):
    for i in range(10): print(randint(0, 2), end=' ')
    print()
