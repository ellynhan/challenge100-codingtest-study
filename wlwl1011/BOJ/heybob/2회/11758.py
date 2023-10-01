import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

def ccw():
    return (arr[0][0]*arr[1][1] + arr[1][0]*arr[2][1] + arr[2][0]*arr[0][1]) - (arr[0][1]*arr[1][0]+arr[1][1]*arr[2][0] + arr[2][1]*arr[0][0])



arr = []

for _ in range(3):
    arr.append(list(map(int, input().split())))


if ccw() < 0:
    print(-1)
elif ccw() > 0:
    print(1)
else:
    print(0)        
