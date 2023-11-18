import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')


def preorderTraversal(node):
    if node == '.':
        return
    print(node,end='')
    preorderTraversal(tree[node][0])
    preorderTraversal(tree[node][1])

def inorderTraversal(node):
    if node == '.':
        return
    inorderTraversal(tree[node][0])
    print(node,end='')
    inorderTraversal(tree[node][1])

def postorderTraversal(node):
    if node == '.':
        return
    postorderTraversal(tree[node][0])
    postorderTraversal(tree[node][1])
    print(node,end='')

N = int(input())
tree = {}

for _ in range(N):
    parent, left, right = input().split()
    tree[parent] = [left, right]

preorderTraversal('A')
print()
inorderTraversal('A')
print()
postorderTraversal('A')
print()