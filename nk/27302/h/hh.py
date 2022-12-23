cur = int(input())
ans = 0
while cur > 0:
    ans += cur
    cur //= 10
print(ans)
