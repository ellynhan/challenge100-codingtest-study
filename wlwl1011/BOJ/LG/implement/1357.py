import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

def rev(x):
    return int(x[::-1])

A, B = input().split()

print(rev(str(rev(A)+ rev(B))))
