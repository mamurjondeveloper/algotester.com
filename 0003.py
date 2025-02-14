n = int(input())
l = list(map(int, input().split()))
arr = sorted(enumerate(l, 1), key=lambda x: x[1])
print(" ".join(str(x[0]) for x in arr))
