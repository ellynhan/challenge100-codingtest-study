import sys

class Stack_int :
    def __init__(self) :
        self.__reverse_stack = []

    def push(self, n) :
        self.__reverse_stack.append(n)

    def pop(self) :
        if self.__reverse_stack :
            n = self.__reverse_stack.pop()
            print(n)
        else :
            print(-1)
    
    def top(self) :
        if self.__reverse_stack :
            print(self.__reverse_stack[-1])
        else :
            print(-1)

    def size(self) :
        print(len(self.__reverse_stack))

    def empty(self) :
        if self.__reverse_stack :
            print(0)
        else :
            print(1)

N = int(sys.stdin.readline())
stack = Stack_int()

for i in range(N) :
    command = list(sys.stdin.readline().strip().split())
    if command[0] == 'push' :
        stack.push(int(command[1]))
    elif command[0] == 'pop' :
        stack.pop()
    elif command[0] == 'top' :
        stack.top()
    elif command[0] == 'size' :
        stack.size()
    elif command[0] == 'empty' :
        stack.empty()
    else :
        print('?')

del stack
