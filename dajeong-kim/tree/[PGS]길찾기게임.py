from collections import deque

class Node:
    def __init__(self, info, num, left=None, right=None):
        self.info = info
        self.left = left
        self.right = right
        self.num = num # 노드의 번호
        
    def has_left(self):
        return self.left is not None
    def has_right(self):
        return self.right is not None

# 이진트리 생성 함수
def make_BT(nodeinfo):
    # 노드의 번호 리스트 
    nodes = [i for i in range(1, len(nodeinfo)+1)]
    # y가 클수록 우선순위 높음
    # y가 같다면 x가 작을수록 우선순위 높음
    nodes.sort(key = lambda x : (nodeinfo[x-1][1], -nodeinfo[x-1][0]), reverse=True)
    root = None
    for i in range(len(nodeinfo)):
        if root is None:
            root = Node(nodeinfo[nodes[0]-1], nodes[0])
        else:
            parent = root
            node = Node(nodeinfo[nodes[i]-1], nodes[i])
            
            while True:
                # 부모노드의 x좌표보다 작으면 왼쪽으로
                if node.info[0]<parent.info[0]:
                    if parent.has_left():
                        parent = parent.left
                        continue
                    else:
                        parent.left = node
                        break
                # 부모노드의 x좌표보다 크면 오른쪽으로
                else:
                    if parent.has_right():
                        parent = parent.right
                        continue
                    else:
                        parent.right = node
                        break
    return root
"""
파이썬은 재귀의 최대 깊이를 1000으로 제한 -> 충분하지 않을 때에는 런타임 에러 발생
sys.setrecursionlimit() 함수를 통해 최대 깊이를 수정
"""
import sys
sys.setrecursionlimit(10**4)

def pre_order(root, answer):
    if root is None:
        return
    answer[0].append(root.num)
    pre_order(root.left, answer)
    pre_order(root.right, answer)

def post_order(root, answer):
    if root is None:
        return
    post_order(root.left, answer)
    post_order(root.right, answer)
    answer[1].append(root.num)

"""
비재귀 Ver.
def pre_order(root, answer):
    stack = [root]
    while stack:
        node = stack.pop()
        if node is None:
            continue
        answer[0].append(node.num)
        stack.append(node.right)
        stack.append(node.left)

def post_order(root, answer):
    stack = [(root, False)]
    while stack:
        node, visited = stack.pop()
        if node is None:
            continue
        if visited:
            answer[1].append(node.num)
        else:
            stack.append((node, True))
            stack.append((node.right, False))
            stack.append((node.left, False))
"""

def solution(nodeinfo):
    answer = [[],[]]
    root = make_BT(nodeinfo)
    pre_order(root, answer)
    post_order(root, answer)
    return answer