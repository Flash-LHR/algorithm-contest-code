n1 = int(input())
n2 = int(input())
one = n2 - n1
t = 360
if one < 0 :
    one += t
two = one - 360
if abs(one) <= abs(two) :
    print(one)
else :
    print(two)

