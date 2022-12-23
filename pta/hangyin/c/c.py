prime = []

def is_prime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

for i in range(2, 100000):
    if is_prime(i):
        prime.append(i)

for l in range(0, len(prime) - 1):
    x = 1
    for r in range(l, len(prime) - 1):
        x *= prime[r]
        if (x + 1) % prime[r + 1] == 0:
            t = (x + 1) // prime[r + 1]
            if (t&(t - 1)) == 0 and t != 1:
                print(x, l + 1,r +1)
