#https://programmers.co.kr/learn/courses/30/lessons/49189
#1트 실패 : depth를 dict로 저장한 후, 끝나고 가장 큰 depth를 다시 세어줬으나 시간초과 (O(N^2))
#2트 성공 : visit 배열(not in 대신 hash 주소값으로 바로 찾기)에 depth를 같이 넣어주고, count는 d dict에 따로 저장해서 성공 (O(N))
from collections import defaultdict, deque
def solution(n, edge):
    e = defaultdict(list) #edge
    d = defaultdict(int) #depth
    for vertex in edge:
        e[vertex[0]].append(vertex[1])
        e[vertex[1]].append(vertex[0])
    
    q = deque([1])
    visit = [-1] * n
    visit[0] = 0
    maximum = 0 #maximum depth
    while q:
        tmp = q.popleft()
        for node in e[tmp]:
            if visit[node-1] < 0: #주솟값 O(1) < not in (O(N))
                if node not in q:
                    visit[node-1] = visit[tmp-1]+1
                    maximum = visit[node-1]
                    d[maximum]+=1
                q.append(node)
    return d[maximum]

    # 1트 실패했던 코드 : O(N) 추가되어 손해
    # maximum = -1
    # tmp = 1
    # for node in d:
    #     if d[node] > maximum:
    #         maximum = d[node]
    #         tmp = 1
    #     elif d[node] == maximum:
    #         tmp+=1    
    # answer = tmp
    # return answer