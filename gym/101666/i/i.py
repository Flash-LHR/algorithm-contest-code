n, m = map(int, input().split())
if n == 1 :
    if m & 1 :
        print(1)
    else :
        print(2)
else :
    if m == 1 :
        if n & 1 :
            print(1)
        else :
            print(0)
    elif n & 1 and m & 1 :
        print(1)
    elif n & 1:
        print(2)
    else:
        print(0)

