import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

T = int(input())

for _ in range(T):
    length, n = map(int, input().split())
    
    origin = []
    non_origin = []
    for _ in range(n):
        ant = int(input())
        if ant > length // 2:
            origin.append(length-ant)
            non_origin.append(ant)
        else:    
            origin.append(ant)
            non_origin.append(length-ant)
    print(max(origin),max(non_origin))        




    