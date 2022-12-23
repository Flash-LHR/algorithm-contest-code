from random import randint

t = int(4e6)
print(t)
for _ in range(t):
    print('%08x %04x' % (randint(0, (1<<32)-1), randint(0, (1<<16) - 1)))
