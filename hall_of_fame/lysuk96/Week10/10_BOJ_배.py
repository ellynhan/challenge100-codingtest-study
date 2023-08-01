from collections import deque

def moving():
    if max(crain) < max(q):
        return -1
    else:
        time = 0

        # while True:
        #     left =0
        #     right = N-1
        #     print(q)
        #     if not q:
        #         break
            
        #     while q and left<=right:
        #         flag = True
        #         if crain[left]>= q[0]:
        #             q.popleft()
        #             left+=1
        #             flag = False
        #         if q and crain[right]>= q[-1]:
        #             q.pop()
        #             right-=1
        #             flag = False
        #         if flag:
        #             break
        #     time+=1
        while True:
            i= N-1
            temp = deque()
            if not q:
                break

            while i>=0 and q:
                if crain[i] >= q[-1]:
                    q.pop()
                    i-=1
                else:
                    temp.appendleft(q.pop())

            q.extend(temp)
            time+=1
        
        return time

N = int(input())
crain = sorted(list(map(int, input().split(" "))))
M = int(input())
q = deque(sorted(list(map(int, input().split(" ")))))
visit = [False]*M
# q = deque(q)

# print(crain)
answer = moving()
print(answer)