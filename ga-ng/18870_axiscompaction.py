import sys

input = sys.stdin.readline

n = int(input())

lst = []

lst = list(map(int, input().split()))

setlst = list(set(lst))
setlst.sort()

dic = dict()
cnt = 0

for i in range(len(setlst)):
    dic[setlst[i]] = i


for i in lst:
    print(dic[i], end=" ")