from random import randint

n = randint(1, 5)
print(n)
for i in range(n):
    print(randint(1, 5), randint(1, 5))
q = randint(1, 2)
print(q)
for i in range(q):
    op = randint(1, 2)
    if op == 1:
        x = randint(1, 5)
        print(op, x)
    elif op == 2:
        a = randint(1, 5)
        b = randint(1, 5)
        c = randint(1, n)
        print(op, a, b, c)
