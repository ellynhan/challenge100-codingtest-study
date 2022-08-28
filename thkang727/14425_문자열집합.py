import sys
input = sys.stdin.readline


n,m = map(int,input().split())

cnt=0

s = set()
for i in range(n):
    tmp = input()
    s.add(tmp)

for j in range(m):
    tmp = input()
    if tmp in s:
        cnt+=1

print(cnt)
