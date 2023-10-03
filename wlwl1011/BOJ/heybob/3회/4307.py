import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
T = int(input())

for _ in range(T):
    L,N = map(int,input().split())
    fast = []
    slow = []
    for _ in range(N):
        t = int(input())
        if t > L//2:
            fast.append(L-t)
            slow.append(t)
        else:
            fast.append(t)
            slow.append(L-t)
    print(max(fast),max(slow))            