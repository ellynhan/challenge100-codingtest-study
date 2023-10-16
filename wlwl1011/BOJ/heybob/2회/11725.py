import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
sys.setrecursionlimit(10**6)

def findRoot(node):
    
    for i in tree[node]:
        if root[i] == 0:
            root[i] = node
            findRoot(i)


N = int(input())
root = [0] * (N+1)

tree = [[] for _ in range(N+1)]

for i in range(N-1):
    node1, node2 = map(int, input().split())
    tree[node1].append(node2)
    tree[node2].append(node1)

findRoot(1)    

for i in range(2,N+1):
    print(root[i])

