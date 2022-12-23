from random import randint
def gen() :
    return chr(ord('a') + randint(0, 3))

a = 'a' + ''.join([gen() for _ in range(randint(1, 10))])
t = [randint(1, len(a) - 1) for _ in range(4)]
t = list(set(t))
t.sort()
pre = 0
for i in t :
    a = a[:i + pre] + "+*"[randint(0, 1)] + a[i + pre:]
    pre += 1
print(a)
b = 'a' + ''.join([gen() for _ in range(randint(1, 10))])
print(b)

