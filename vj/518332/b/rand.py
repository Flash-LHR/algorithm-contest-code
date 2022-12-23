from random import randint

n = randint(1, 10)
m = randint(1, 10)
for i in range(m):
    ch = '?'
    if randint(0, 1) == 0:
        if i == 0: ch = chr(48 + randint(1, 9))
        else: ch = chr(48 + randint(0, 9))
    print(ch, end='')
print(' %d' % n)

