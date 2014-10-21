import sys

labels = {}
commands = []
memory = [0]*256
comp = 0

def f(n):
    return '%02X'%n

def d(s):
    return int(s, 16)

def what(s):
    if s[0] == '#':
        return d(s[1:])
    if s[0] == '(':
        return memory[memory[d(s[1:-1])]]
    return memory[d(s)]

def where(s):
    if s[0] == '(':
        return memory[d(s[1:-1])]
    return d(s)

def split(s, c):
    return [x for x in s.strip().split(c) if x.strip() != '']

raw_input()
for line in sys.stdin:
    if line.strip() == '': continue
    temp1 = split(line, ',')
    temp2 = split(temp1[0], ' ')
    if len(temp2) == 2:
        commands.append((temp2[0].lower(), temp2[1:] + temp1[1:]))
    elif len(temp2) == 3:
        labels[temp2[0]] = len(commands)
        commands.append((temp2[1].lower(), temp2[2:] + temp1[1:]))

pc = 0
while pc < len(commands):
    opcode, args = commands[pc]
    pc+=1
    
    if opcode == 'print':
        if len(args)==1:
            print f(memory[d(args[0])])
        else:
            print ' '.join(f(memory[x]) for x in xrange(d(args[0]), d(args[1])+1))
    elif opcode == 'move':
        memory[where(args[1])] = what(args[0])                
        memory[where(args[1])] &= 0xFF
    elif opcode == 'add':
        memory[where(args[1])] += what(args[0])                
        memory[where(args[1])] &= 0xFF
    elif opcode == 'sub':
        memory[where(args[1])] -= what(args[0])                
        memory[where(args[1])] &= 0xFF
    elif opcode == 'and':
        memory[where(args[1])] &= what(args[0])                
        memory[where(args[1])] &= 0xFF
    elif opcode == 'or':
        memory[where(args[1])] |= what(args[0])                
        memory[where(args[1])] &= 0xFF
    elif opcode == 'xor':
        memory[where(args[1])] ^= what(args[0])                
        memory[where(args[1])] &= 0xFF
    elif opcode == 'comp':
        a = what(args[0])
        b = what(args[1])
        comp = -1 if a<b else 0 if a==b else 1    
    elif opcode == 'beq':
        if comp == 0:
            pc = labels[args[0]]
    elif opcode == 'bne':
        if comp != 0:
            pc = labels[args[0]]
    elif opcode == 'bgt':
        if comp == 1:
            pc = labels[args[0]]
    elif opcode == 'bge':
        if comp >= 0:
            pc = labels[args[0]]
    elif opcode == 'blt':
        if comp == -1:
            pc = labels[args[0]]
    elif opcode == 'ble':
        if comp <= 0:
            pc = labels[args[0]]
    else:
        raise Exception('what')

