import sys

class binaryTree:
    def __init__(self) -> None:
        self.visited = False
        self.left = -1
        self.right = -1


n = int(input())

inputData = [binaryTree() for _ in range(n)]

for _ in range(n):
    pos, left, right = map(ord,sys.stdin.readline().rstrip().split())
    if left != 46 : # .의 아스키 코드는 46이다.
        inputData[pos-65].left = left-65
    if right != 46 : # .의 아스키 코드는 46이다.
        inputData[pos-65].right = right-65

# 전위 순휘
stack = []
stack.append(0)

while len(stack) > 0:
    now = stack.pop()
    print(chr(now+65), end='')
    if inputData[now].right != -1:
        stack.append(inputData[now].right)
    if inputData[now].left != -1:
        stack.append(inputData[now].left)
print()

# 중위 순휘
stack.append(0)
while len(stack) > 0:
    now = stack.pop()

    if inputData[now].left == -1 or inputData[inputData[now].left].visited :
        inputData[now].visited = True
        print(chr(now+65), end='')
        if inputData[now].right != -1 :
            stack.append(inputData[now].right)
    else:
        stack.append(now)
        stack.append(inputData[now].left)
print()

# 후위 순회
stack.append(0)
for tree in inputData:
    tree.visited = False

while len(stack) > 0:
    now = stack.pop()

    if (inputData[now].left == -1 or inputData[inputData[now].left].visited) and (inputData[now].right == -1 or inputData[inputData[now].right].visited):
        inputData[now].visited = True
        print(chr(now+65), end='')
    else:
        stack.append(now)
        if inputData[now].right != -1 :
            stack.append(inputData[now].right)
        if inputData[now].left != -1 :
            stack.append(inputData[now].left)