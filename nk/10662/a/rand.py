from random import randint

n = 200
print(n)
for _ in range(2):
    for i in range(n):
        for j in range(n):
            print(randint(0, 1), end=' ')
        print()
