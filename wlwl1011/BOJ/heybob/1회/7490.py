import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from itertools import permutations
from collections import deque

def recur(arr, m):
    if len(arr) == m:
        operators.append(arr[:])
        return
    
    arr.append(' ')
    recur(arr, m)
    arr.pop()

    arr.append('+')
    recur(arr, m)
    arr.pop()

    arr.append('-')
    recur(arr, m)
    arr.pop()

for _ in range(int(input())):
    operators = []
    N = int(input())
    recur([], N-1)
    for operator in operators:
        statement = ''
        for i in range(N-1):
            statement += str(i+1)+operator[i]
        statement += str(N)
        if (eval(statement.replace(' ','')) == 0):
            print(statement)    
    print()        

