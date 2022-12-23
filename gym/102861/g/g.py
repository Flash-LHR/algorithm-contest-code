n = int(input())
mx = 100
now = 100
for _ in range(n) :
    now += int(input())
    mx = max(mx, now)
print(mx)

