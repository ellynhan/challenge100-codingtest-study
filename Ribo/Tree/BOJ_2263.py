import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)


def getPreorder(inS, inE, postS, postE):
    if inS > inE:
        return
    
    root = postorder[postE]
    
    left = pos[root] - inS
    right = inE - pos[root]
    
    print(root, end = " ")
    getPreorder(inS, inS+left-1, postS, postS+left-1)
    getPreorder(inE-right+1, inE, postE-right, postE-1)

n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))

pos = [0]*(n+1)
for i in range(n):
    pos[inorder[i]] = i
    
getPreorder(0, n-1, 0, n-1)
