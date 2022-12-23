from random import randint

M = 10

n = randint(1, 10)
print(n)
a = [randint(1, M) for i in range(n)]
b = [randint(1, M) for i in range(n)]
c = [a[i] + b[i] for i in range(n)]
ap, bp, cp = randint(0, n - 1), randint(0, n - 1), randint(0, n - 1)
print(' '.join([str(a[(i + ap) % n]) for i in range(n)]))
print(' '.join([str(b[(i + bp) % n]) for i in range(n)]))
print(' '.join([str(c[(i + cp) % n]) for i in range(n)]))
