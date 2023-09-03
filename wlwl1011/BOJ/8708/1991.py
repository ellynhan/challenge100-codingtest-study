import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N = int(input())
tree = {} #딕셔너리를 이용해 트리를 만든다!

for n in range(N):
    root, left, right = input().split()
    tree[root] = [left, right]

def preorder(root):
    if root !='.':
        print(root,end='')
        preorder(tree[root][0]) #left
        preorder(tree[root][1]) #right
def inorder(root):
    if root !='.':
        inorder(tree[root][0])
        print(root,end='')
        inorder(tree[root][1])
def postorder(root):
    if root != '.':
        postorder(tree[root][0])
        postorder(tree[root][1])
        print(root,end='')                

preorder('A')
print()
inorder('A')
print()
postorder('A')        