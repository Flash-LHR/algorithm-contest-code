for _ in range(int(input())) :
    n, m = map(int, input().split())
    ans = 0
    for i in range(1, n + 1) :
        ans += i * i
    print(ans * m)
