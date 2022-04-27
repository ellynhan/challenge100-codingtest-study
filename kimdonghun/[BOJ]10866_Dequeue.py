from collections import deque
import sys

N = int(sys.stdin.readline())

class Deque():
    q = deque([])

    def push_front(self, X):
        self.q.appendleft(X)
    
    def push_back(self, X):
        self.q.append(X)

    def pop_front(self):
        if self.empty():
            print(-1)
        else :
            print(self.q.popleft())

    def pop_back(self):
        if self.empty():
            print(-1)
        else :
            print(self.q.pop())

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

for i in range(N):
    q = Deque()

    cmd_list = list(sys.stdin.readline().split())
    #print(cmd_list)

    if cmd_list[0] == "push_front":
        q.push_front(int(cmd_list[1]))
    elif cmd_list[0] == "push_back":
        q.push_back(int(cmd_list[1]))
    elif cmd_list[0] == "pop_front":
        q.pop_front()
    elif cmd_list[0] == "pop_back":
        q.pop_back()
    elif cmd_list[0] == "size":
        print(q.size())
    elif cmd_list[0] == "empty":
        print(q.empty())
    elif cmd_list[0] == "front":
        q.front()
    elif cmd_list[0] == "back":
        q.back()
