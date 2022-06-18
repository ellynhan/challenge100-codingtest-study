import sys

class Stack():
    def __init__(self):
        self.arr = []

    def push(self, n):
        self.arr.append(n)
    
    def size(self):
        return len(self.arr)

    def top(self):
        if self.size() == 0:
            return -1
        return self.arr[-1]

    def empty(self):
        if self.size() == 0:
            return 1
        return 0
    
    def pop(self):
        top = self.top()
        if top != -1:
            del self.arr[-1]
        return top
        
n = int(input())
stack = Stack()
answer = []
for i in range(n):
    command = list(map(str,sys.stdin.readline().rstrip().split()))
    if len(command) == 2:
        v = getattr(stack, command[0])(command[1])
    else:
        v = getattr(stack, command[0])()
    if v != None:
        answer.append(v)
for v in answer:
    print(v)