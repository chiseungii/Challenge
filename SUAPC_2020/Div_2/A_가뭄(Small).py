d1, d2, d3 = map(int, input().split())
sum = (d1 + d2 + d3) / 2

impossible = False
a = sum - d3
if a <= 0: impossible = True
b = sum - d2
if b <= 0: impossible = True
c = sum - d1
if c <= 0: impossible = True

if impossible: print(-1)
else:
    print(1)
    print("%.1f %.1f %.1f" % (a, b, c))
