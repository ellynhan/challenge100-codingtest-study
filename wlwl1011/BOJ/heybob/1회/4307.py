import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

T = int(input())

for _ in range(T):
    length, number = map(int, input().split())
    straight = []
    non_straight = []
    for _ in range(number):
        ant = int(input())
        if ant > length // 2:
            non_straight.append(ant)
            straight.append(length-ant)
        else:    
            non_straight.append(length-ant)
            straight.append(ant)
    print(max(straight),max(non_straight))        
        

