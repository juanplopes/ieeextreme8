import sys

raw_input()

T = map(int, (x.strip() for x in raw_input().strip().split(' ') if x.strip() != ''))
n = int(raw_input())
M = int(1e9+7)
p = pow(2, n, M)

print sum((x*p%M+M)%M for x in T)%M