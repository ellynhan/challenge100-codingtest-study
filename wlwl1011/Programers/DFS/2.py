def checkNetwork(n, node,computers,visited):
    for i in range(n):
        if computers[node][i] == 1 and not visited[i]:
            visited[i] = 1
           
            checkNetwork(n, i, computers, visited)


def solution(n, computers):
    answer = 0
    visited = [0] * n

    for i in range(n):
        ans = []
        if not visited[i]:
            visited[i] = 1
            checkNetwork(n, i, computers, visited)
            answer += 1
        
    return answer     
        
    
    
                    
                    
                 
    return answer