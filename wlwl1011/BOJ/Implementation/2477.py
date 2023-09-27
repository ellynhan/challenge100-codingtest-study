import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

dx = [0,0,0,1,-1]
dy = [0,1,-1,0,0]

height = []
width = []
arr = []
K = int(input())

for i in range(6):
    direction, length = map(int, input().split())
    arr.append(list(direction,length))
    if direction == 1 or direction == 2:
        width.append(length)
    else:
        height.append(length)

small = []
for i in range(6):
    if arr[i][0] == arr[(i+2)%6][0]:
        small.append(arr[(i+1)%6][1])

print((max(height)*max(width)-(small[0]*small[1]))
