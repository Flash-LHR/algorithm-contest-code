n = int(input())
a = []
for _ in range(n) :
    a.append(int(input()))
money = 100
item = 0
mx = 100000
for i in range(n) :
    if (i == 0 or a[i - 1] >= a[i]) and (i != n - 1 and a[i + 1] >= a[i]):
        diff = min(mx - item, money // a[i])
        item += diff
        money -= diff * a[i]
    elif (i != 0 and a[i - 1] <= a[i]) and (i == n - 1 or a[i + 1] <= a[i]) :
        money += item * a[i]
        item = 0

print(money)

