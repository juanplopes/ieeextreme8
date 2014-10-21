import sys
from itertools import permutations

def answer(s):
    s = s[::-1]
    for i, test in enumerate(sorted(''.join(p) for p in permutations(s))):
        if test==s:
            return i+1
            
print '%02d' % (answer(raw_input().strip()[:-1])%100)
    
