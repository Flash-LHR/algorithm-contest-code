from random import randint

n = 300
print(n)
for i in range(n):
    for j in range(n):
        print(randint(1, 1000000), end=' ')
    print()
