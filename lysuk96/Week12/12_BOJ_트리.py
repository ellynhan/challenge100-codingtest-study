# https://www.acmicpc.net/problem/4803
from collections import defaultdict, deque

def is_cyclic(i):
    q = deque([i])
    visit[i] = True
    flag = False
    while q:
        tmp= q.popleft()
        for node in v[tmp]:
            if not visit[node]:
                visit[node] = True
                v[tmp].remove(node)
                v[node].remove(tmp)
                q.append(node)
            else:
                flag = True
    return flag

case = 0
while True:
    case+=1
    n, m = map(int, input().split(" "))
    if n==m== 0:
        break
    
    visit = [False]*(n+1)
    v = defaultdict(list)
    for _ in range(m):
        a, b = map(int, input().split(" "))
        v[a].append(b)
        v[b].append(a)
    
    answer = 0
    for i in range(1, n+1):
        if not visit[i]:
            if (not is_cyclic(i)):
                answer+=1
    
    if answer == 0:
        print('Case {}: No trees.'.format(case))
    elif answer == 1:
        print('Case {}: There is one tree.'.format(case))
    else:
        print('Case {}: A forest of {} trees.'.format(case, answer))




    