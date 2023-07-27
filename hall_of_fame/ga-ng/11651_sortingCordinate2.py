import sys

input = sys.stdin.readline

n = int(input())

cor = []

for _ in range(n):
    tempX, tempY = list(map(int, input().split()))
    cor.append([tempY, tempX])
    
cor.sort()

for i in cor:
    print(i[1], i[0])