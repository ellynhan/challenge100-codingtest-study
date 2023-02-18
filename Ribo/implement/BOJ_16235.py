import sys
input = sys.stdin.readline


def solve(cnt):
    for _ in range(k):
        for x in range(n):
            for y in range(n):
                tree[x][y].sort()
                length = len(tree[x][y])
                temp, dead = [], 0
                for age in tree[x][y]:
                    if fert[x][y] < age:
                        dead += age//2
                        cnt -= 1
                        continue
                    fert[x][y] -= age
                    age += 1
                    temp.append(age)
                tree[x][y] = temp
                fert[x][y] += dead
                
        for x in range(n):
            for y in range(n):
                length = len(tree[x][y])
                for z in range(length):
                    if tree[x][y][z] % 5 != 0: continue
                    for i in range(8):
                        nx = x + dx[i]
                        ny = y + dy[i]
                        if 0 <= nx < n and 0 <= ny < n:
                            tree[nx][ny].append(1)
                            cnt += 1
        
        for x in range(n):
            for y in range(n):
                fert[x][y] += addAmount[x][y]
    
    return cnt

n, m, k = map(int, input().split())
addAmount = [list(map(int, input().split())) for _ in range(n)]
fert = [[5]*n for _ in range(n)]
tree = [[[] for _ in range(n)] for _ in range(n)]
for _ in range(m):
    x, y, age = map(int, input().split())
    tree[x-1][y-1].append(age)
    
dx = [-1, 1, 0, 0, -1, -1, 1, 1]
dy = [0, 0, -1, 1, 1, -1, -1, 1]    

print(solve(m))
