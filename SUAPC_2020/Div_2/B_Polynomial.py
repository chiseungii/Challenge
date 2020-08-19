import sys

MOD = 1000000007

N, x = map(int, sys.stdin.readline().split())

sum = 0
for i in range(N):
    Ai, I = map(int, sys.stdin.readline().split())
    sum += Ai
    sum *= x
    sum %= MOD
Ai, I = map(int, sys.stdin.readline().split())
sum += Ai
sum %= MOD

print(sum)
