import sys

# -는 Dead State
AUTOMATA = dict({
    'S': ('A','B'),
    'A': ('-','S'),
    'B': ('C','-'),
    'C': ('D','-'),
    'D': ('D','E'),
    'E': ('A','F'),
    'F': ('G','F'),
    'G': ('D','S'),
})
n = int(input())
for _ in range(n):
    s = sys.stdin.readline().rstrip()
    State = 'S'
    for c in s:
        t = int(c)
        State = AUTOMATA[State][int(c)]
        if(State == '-'):
            break
    
    if State == 'S' or State == 'E' or State == 'F' :
        print("YES")
    else :
        print("NO")