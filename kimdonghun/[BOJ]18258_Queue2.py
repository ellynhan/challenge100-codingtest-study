import sys
from collections import deque

class Queue():
    q = deque([])

    def push(self, X):
        self.q.append(X)

    def pop(self):
        if self.empty():
            print(-1)
        else:
            print(self.q[0])
            self.q.popleft()

    def size(self):
        return len(self.q)

    def empty(self):
        if self.size() == 0:
            return 1
        else:
            return 0
    
    def front(self):
        if self.empty():
            print(-1)
        else:
            print(self.q[0])

    def back(self):
        if self.empty():
            print(-1)
        else:
            print(self.q[-1])
        

N = int(sys.stdin.readline())
cmd_list = []
q = Queue()

for i in range(N):
    cmd_list = list(sys.stdin.readline().split())
    #print(cmd_list)

    if cmd_list[0] == "push":
        q.push(int(cmd_list[1]))
    elif cmd_list[0] == "pop":
        q.pop()
    elif cmd_list[0] == "size":
        print(q.size())
    elif cmd_list[0] == "empty":
        print(q.empty())
    elif cmd_list[0] == "front":
        q.front()
    elif cmd_list[0] == "back":
        q.back()
