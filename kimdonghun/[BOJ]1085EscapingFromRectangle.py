import sys

Nlist = list(map(int, sys.stdin.readline().split()))

x = Nlist[0]
y = Nlist[1]
w = Nlist[2]
h = Nlist[3]

up_diff = h-y
down_diff = y
left_diff = x
right_diff = w-x

#print(up_diff, down_diff, left_diff, right_diff)

y_max = min(up_diff, down_diff)
x_max = min(left_diff, right_diff)

print(min(y_max, x_max))