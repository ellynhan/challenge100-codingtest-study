import sys

A,B = map(int, sys.stdin.readline().split())
C = int(sys.stdin.readline())

min = B + C

hour_add = min // 60
min %= 60

hour = A + hour_add
hour %= 24

print(hour, min)
