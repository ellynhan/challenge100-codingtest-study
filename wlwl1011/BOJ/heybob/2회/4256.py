import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

def printPostorder(preorder, inorder):
    if len(preorder) == 1:
        print(preorder[0], end = ' ')
        return
    elif len(preorder) == 2:
        print(preorder[1],preorder[0],end = ' ')   
        return
    elif not preorder:
        return
    else:
        
        root = preorder[0]
        root_indx = inorder.index(root)
        preorder_left = preorder[1:root_indx+1]
        inorder_left = inorder[:root_indx]

        preorder_right = preorder[root_indx+1:]
        inorder_right = inorder[root_indx+1:]

        printPostorder(preorder_left,inorder_left)
        printPostorder(preorder_right,inorder_right)
        print(root,end = ' ')



for _ in range(int(input())):
    N = int(input())
    preorder = list(map(int, input().split()))
    inorder = list(map(int, input().split()))
    printPostorder(preorder,inorder)
    print()

