import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

arr = list(map(int, input().split()))

truck = []
for i in range(3):
    s, e = map(int, input().split())
    truck.append([s,1])
    truck.append([e,-1])
    # truck = list(map(int, input().split()))

truck.sort()

answer = 0
temp = 0
check = 1
for t in range(len(truck)):
    tr = truck[t]
    
    answer += temp * arr[temp-1] * (tr[0]-check)
   
    temp += tr[1]
    check = tr[0]

print(answer)