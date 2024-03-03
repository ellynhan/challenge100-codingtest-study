from queue import deque

def solution(n, edge) :
    nodeinfo = [[] for _ in range(n + 1)]
    distinfo = [-1 for _ in range(n + 1)]
    distinfo[1] = 0
    for i in range(len(edge)) :
        nodeinfo[edge[i][0]].append(edge[i][1])
        nodeinfo[edge[i][1]].append(edge[i][0])
    
    checkque = deque([1])
    while checkque :
        check = checkque.popleft()
        for j in nodeinfo[check] :
            if distinfo[j] == -1 :
                distinfo[j] = distinfo[check] + 1
                checkque.append(j)
                
    answer = distinfo.count(max(distinfo))
    return answer
