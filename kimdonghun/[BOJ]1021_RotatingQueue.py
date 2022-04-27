from collections import deque
import sys

N,M = map(int, sys.stdin.readline().split())
ans_l = deque(list(map(int, sys.stdin.readline().split())))
q = deque([i for i in range(1,N+1)])

#print(q)
#print(ans_l)

cnt_left = 0
cnt_right = 0
while(len(ans_l) > 0):
    #print("=loopinit=", q)
    if q[0] == ans_l[0]:
        q.popleft()
        ans_l.popleft()
    else:
        if q.index(ans_l[0]) <= len(q) // 2:
            while q[0] != ans_l[0]:
                q.append(q[0])
                q.popleft()
                cnt_left += 1
                #print("--LEFT--", q, ans_l[0])
            if q[0] == ans_l[0]:
                #print("**finish**", q)
                q.popleft()
                ans_l.popleft()
        else:
            while q[0] != ans_l[0]:
                q.appendleft(q[-1])
                q.pop()
                cnt_right += 1
                #print("--RIGHT--", q, ans_l[0])
            if q[0] == ans_l[0]:
                #print("**finish**", q)
                q.popleft()
                ans_l.popleft()

print(cnt_left + cnt_right)
            
        