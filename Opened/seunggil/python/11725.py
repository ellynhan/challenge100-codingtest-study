import sys
class node:
    def __init__(self) -> None:
        self.connect = []
        self.parent = -1 #  0 : root, -1 : not defined

    def add(self, n) -> bool:
        self.connect.append(n)

n = int(sys.stdin.readline().rstrip())

inputData = [node() for _ in range(n+1)]

for _ in range(n-1):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    inputData[a].add(b)
    inputData[b].add(a)

inputData[1].parent = 0
dfs = []
dfs.append(1)

while len(dfs) > 0:
    now = dfs.pop()
    for i in inputData[now].connect :
        if i is not None and inputData[i].parent == -1:
            inputData[i].parent = now
            dfs.append(i)

for i in range(2,n+1):
    print(inputData[i].parent)