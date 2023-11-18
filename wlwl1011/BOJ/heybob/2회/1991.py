import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

def pretravel(node):
    if node == '.':
        return
    print(node,end='')
    pretravel(tree[node][0])
    pretravel(tree[node][1])

def intravel(node):
    if node == '.':
        return
    intravel(tree[node][0])
    print(node,end='')
    intravel(tree[node][1])

def postravel(node):
    if node == '.':
        return
    postravel(tree[node][0])
    postravel(tree[node][1])
    print(node,end='')

N = int(input())
tree = dict()
for _ in range(N):
    node, left, right = input().split()
    tree[node] = [left, right]

pretravel('A')
print()
intravel('A')
print()
postravel('A')