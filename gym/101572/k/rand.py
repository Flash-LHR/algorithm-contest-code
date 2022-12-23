from random import randint
a = [randint(0, 5) for _ in range(3)]
if sum(a) & 1 :
    a[0] += 1
if sum(a) == 0 :
    a[0] = 2
print(*a)
lim = 0
b = []
for i in range(3) :
    b.append(randint(lim + 1, lim + 10))
    lim = b[-1]
print(*b)
print(*[randint(1, 20) for _ in range(sum(a) // 2)])

