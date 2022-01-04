import sys

x1, y1 = map(int, sys.stdin.readline().split())

lx = [x1]
ly = [y1]

x2, y2 = map(int, sys.stdin.readline().split())

lx.append(x2)
ly.append(y2)

x3, y3 = map(int, sys.stdin.readline().split())

lx.append(x3)
ly.append(y3)

if(lx.count(x1) == 1):
    x4 = x1
elif(lx.count(x2) == 1):
    x4 = x2
else:
    x4 = x3


if(ly.count(y1) == 1):
    y4 = y1
elif(ly.count(y2) == 1):
    y4 = y2
else:
    y4 = y3

print(x4, y4)