#간선값이 모두 일정할 때, 인접리스트형식으로 그래프 구현

graph = [
  [],
  [2,3,8],
  [1,7],
  [4,5],
  [3,5],
  [3,4],
  [7],
  [2,6,8],
  [1,7]
]

visited = [0]*9

def dfs(graph, v, visited):
  visited[v] = 1
  print(v, end=' ')
  for i in graph[v]:
    if not visited[i]:
      dfs(graph, i, visited)


dfs(graph, 1, visited)

