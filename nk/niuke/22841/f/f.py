f = [0] * 10001
f[1] = 1
cur = 2
num = 1
p = 1
while cur < 10001 :
    num += 1
    p <<= 1
    for i in range(num) :
        f[cur] = f[cur - 1] + p
        cur += 1
        if cur > 10000 :
            break
for _ in range(int(input())) :
    print(f[int(input())])

