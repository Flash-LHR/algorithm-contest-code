from random import randint

for i in range(6):
    if randint(0, 1) == 0: print('true', end=' ')
    else: print('false', end=' ')
print()
