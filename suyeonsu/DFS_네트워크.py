visited = []

def dfs(i, a):
    global visited
    for j in range(len(a)):
        if j != i and a[i][j] and visited[j] == 0:
            visited[j] = 1
            dfs(j, a)

def solution(n, computers):
    global visited
    network = 0
    visited = [0] * n
    for i in range(n):
        if visited[i] == 0:
            visited[i] = 1
            network += 1
            dfs(i, computers)
    return network
  
"""
항상 작은 노드 번호부터 탐색하는 것이 아니기 때문에, dfs에서 j의 탐색 범위를 i+1 ~ n 으로 설정하면 방문하지 못하는 노드가 발생한다.
  (예를 들어 네트워크 그래프가 1-0-3-2일 경우, '0 -> 1 -> 3 -> 2'의 순서로 방문해야하는데 2번 노드를 탐색하지 못하게됨)
따라서 dfs에서 j에 연결된 노드 탐색시 0 ~ n까지 탐색해야 한다.
"""
