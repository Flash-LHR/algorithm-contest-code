from random import randint

n = randint(1, 2)
print(n)
for _ in range(3):
    for __ in range(n):
        print(randint(-10, 10), end=' ')
    print()
