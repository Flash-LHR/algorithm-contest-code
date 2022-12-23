s = input()
n = len(s)
ans = 0
cur = 0
for i in range(n):
    cur *= 10
    cur += ord(s[i]) - 48
    ans += cur
print(ans)

