from random import randint
T = 2
print(T)
for _ in range(T):
    n = randint(1, 5)
    print(n)
    for i in range(n):
        l, r = randint(1, 10), randint(1, 10)
        if l > r:
            l, r = r, l
        print(l, r, randint(1, 10))
