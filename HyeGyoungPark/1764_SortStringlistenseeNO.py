import sys


inp = (sys.stdin.readline().rstrip().split())
n = int(inp[0])
m = int(inp[1])

di = dict()
ans = []

for i in range(n+m):
    word = sys.stdin.readline().rstrip()
    if word not in di:
        di[word] = 1
    else:
        di[word] += 1
        if di[word]==2:
            ans.append(word)

ans.sort()

print(len(ans))
for k in ans:
    print(k)
