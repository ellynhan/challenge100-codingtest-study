import sys

input = sys.stdin.readline

n = int(input())
cntList = [0] * 10001


for _ in range(n):
    cntList[int(input())] += 1



for i in range(1, len(cntList)):
    if cntList[i] != 0:
        for j in range(cntList[i]):
            print(i)