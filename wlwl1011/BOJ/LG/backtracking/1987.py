import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

def dfs(r,c,s):
    global answer
    answer = max(answer, len(s))

    for i in range(4):
        tr = r + dx[i]
        tc = c + dy[i]

        if 0 <= tr < R and 0 <= tc < C:
            if arr[tr][tc] not in s :
                dfs(tr,tc,s+arr[tr][tc])

dx = [-1,1,0,0]
dy = [0,0,-1,1]

R, C = map(int, input().split())
arr = []

for _ in range(R):
    arr.append(list(input()))

answer = 0
dfs(0,0,arr[0][0])

print(answer)

