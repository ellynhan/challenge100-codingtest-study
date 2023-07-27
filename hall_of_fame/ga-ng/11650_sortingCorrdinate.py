import sys

input = sys.stdin.readline

n = int(input())

cor = []

for _ in range(n):
    cor.append(list(map(int, input().split())))
    
cor.sort()

for i in cor:
    print(i[0], i[1])