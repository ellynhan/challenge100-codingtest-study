import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
tree = dict()

def preTravel(node):
    if node == '.':
        return
    print(node,end='')
    preTravel(tree[node][0])
    preTravel(tree[node][1])

def inTravel(node):
    if node == '.':
        return
    inTravel(tree[node][0])
    print(node,end='')
    inTravel(tree[node][1])   

def poTravel(node):
    if node == '.':
        return
    poTravel(tree[node][0])
    poTravel(tree[node][1])  
    print(node,end='')


for _ in range(N):
    node, left, right = input().split()
    tree[node] = (left,right)
preTravel('A')
print()
inTravel('A')
print()
poTravel('A')


