import sys

s = sys.stdin.readline()
ts = s.strip()
a = ts.count(' ')

if ts == '' :
    a = -1

print(a+1)