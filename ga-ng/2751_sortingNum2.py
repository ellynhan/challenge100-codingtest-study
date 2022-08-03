import sys

input = sys.stdin.readline

n = int(input())

numList = []

for _ in range(n):
    numList.append(int(input()))

numList.sort()


for i in range(n):
    print(numList[i])