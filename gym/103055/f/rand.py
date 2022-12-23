from random import randint

t = randint(1, 10)
print(t)
for _ in range(t):
    print(randint(1, 10), randint(1, 10))
