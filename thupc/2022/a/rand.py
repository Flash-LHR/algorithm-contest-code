from random import randint

l = randint(1, 10)
r = randint(1, 10)
if l > r:
    l,r = r,l
print(l, r)
