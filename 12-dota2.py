import sys

n,m = map(int, raw_input().strip().split(' '))

heroes = []

for i, line in enumerate(sys.stdin):
    if line.strip() == '': continue
    name,kind,ratio = (x.strip() for x in line.split(','))
    win,loss= map(float, ratio.split(':'))
    heroes.append((int((win*100)/(win+loss))*(i+1), -i, name, kind))

heroes.sort(reverse=True)
i, s, a = 0, 0, 0
for hero in heroes[:m]:
    print hero[2]
    kind = hero[3].lower()
    if kind == 'intelligence':
        i+=1
    elif kind == 'strength':
        s+=1
    elif kind == 'agility':
        a+=1
    else:
        raise Exception('what')
       
total = i+s+a
i/=float(total)
s/=float(total)
a/=float(total)
        
print ''
print 'This set of heroes:'
print 'Contains %.2f percentage of Intelligence' % (i*100)
print 'Contains %.2f percentage of Strength' % (s*100)
print 'Contains %.2f percentage of Agility' % (a*100)
        
