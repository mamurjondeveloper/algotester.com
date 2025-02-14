import math
n, b, y = map(int, input().split())
def lcm(a, b):
    return a // math.gcd(a, b) * b
L = lcm(b, y)
print((n - 1) // b + (n - 1) // y - (n - 1) // L)
