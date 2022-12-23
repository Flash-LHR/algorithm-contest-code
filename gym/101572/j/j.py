a, b = map(int, input().split())
tot = max(a, b) * 2
if tot == 0 :
    print("Not a moose")
else :
    print("Odd" if a != b else "Even", tot)

