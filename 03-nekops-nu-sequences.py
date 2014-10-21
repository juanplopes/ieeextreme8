def transform(T):
    Q = []

    count = 0
    last = T[0]
    for x in T:
        if x==last:
            count+=1
        else:
            Q.append(count)
            Q.append(last)
            count=1
            last=x
    Q.append(count)
    Q.append(last)
    return Q

def represent(T):
    return ' '.join(map(str, T))    

T = map(int, raw_input().strip().split(' '))
k, T = T[0], T[1:]

R = [represent(T)]
for i in xrange(k):
    T = transform(T)
    R.append(represent(T))       

size = max(map(len, R))
for answer in R:
    pad = (size-len(answer))/2
    off = (size-len(answer))%2

    print ('.'*(pad+off)) + answer + ('.'*pad)
print len(T)