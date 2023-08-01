n, m, sn = input().split()
# n = int(input())
# m = int(input())
# sp = int(input())
n = int(n)
m = int(m)
sn = int(sn)

dfs_node = [[] for _ in range(1001)]
bfs_node = [[] for _ in range(1001)]

dfs_vis = [False for _ in range(1001)]
bfs_vis = [False for _ in range(1001)]

while m > 0:
    x, y = input().split()
    x = int(x)
    y = int(y)
    dfs_node[int(x)].append(int(y))
    dfs_node[int(y)].append(int(x))
    bfs_node[int(x)].append(int(y))
    bfs_node[int(y)].append(int(x))
    m -= 1

for i in range(1001):
    dfs_node[i].sort()
    bfs_node[i].sort()

# DFS
stack = []

dfs_vis[sn] = True

stack.append(sn)

print(sn, end=" ")

while len(stack) > 0:
    cur = stack[-1]

    if len(dfs_node[cur]) == 0:
        stack.pop()
        continue

    nxt = dfs_node[cur][0]

    if dfs_vis[nxt] == True:
        dfs_node[cur].pop(0)
        continue

    print(nxt, end=" ")

    dfs_node[cur].pop(0)
    dfs_vis[nxt] = True
    stack.append(nxt)


print()

# BFS
queue = []
bfs_vis[sn] = True

queue.append(sn)

while len(queue) > 0:
    cur = queue[0]
    queue.pop(0)

    print(cur, end=" ")

    for nxt in bfs_node[cur]:
        if bfs_vis[nxt] == False:
            bfs_vis[nxt] = True
            queue.append(nxt)

print()
